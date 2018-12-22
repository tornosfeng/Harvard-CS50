// recover the jpeg file

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // ensure proper usage
    if(argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    char *infile = argv[1];
    //open image
    FILE *inptr = fopen(infile, "r");

    if(inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }
        char buffer[512];
    char filename[50];


    int num = 0;
    int count = 0;

    FILE *outptr = NULL;

    while(fread(buffer, 512, 1, inptr) == 1)
    {

        if((buffer[0] & 0xff) == 0xff && (buffer[1]& 0xff)  == 0xd8 && (buffer[2] & 0xff) == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //判断是新文件开始还是旧文件结束
            if(count == 0) //判断是新文件开始还是旧文件结束
            {
                count = 1;
                sprintf(filename, "%03i.jpg", num);
                num += 1;
                outptr = fopen(filename, "w");
                if (outptr == NULL)
                {
                    fclose(inptr);
                    fprintf(stderr, "Could not create %s.\n", filename);
                 return 4;
                }
                fwrite(buffer, 512, 1, outptr);
            }
            else if(count == 1)
            {
                // close outfile
                fclose(outptr);
                fseek(inptr, -512, SEEK_CUR);
                count =0;
            }
        }
        else //如果不是文件开头或结束，直接继续写入。
        {
            if(count == 1)
            {
            fwrite(buffer, 512, 1, outptr);
            }
        }

    }

}



