# Questions

## What's `stdint.h`?

stdint.h is a header file in the C standard library introduced in the C99 standard library section 7.18 to allow programmers to write more portable code by providing a set of typedefs that specify exact-width integer types, together with the defined minimum and maximum allowable values for each type, using macros .

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

To declare the data types of the four types.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

1,4,4,2

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

'BM'

## What's the difference between `bfSize` and `biSize`?

bfSize-The size, in bytes, of the bitmap file.
biSize-Specifies the number of bytes required by the structure.
This value does not include the size of the color table or the size of the color masks,
if they are appended to the end of structure. See Remarks.


## What does it mean if `biHeight` is negative?

For uncompressed RGB bitmaps, if biHeight is positive, the bitmap is a bottom-up DIB with the origin at the lower left corner. If biHeight is negative, the bitmap is a top-down DIB with the origin at the upper left corner.
For YUV bitmaps, the bitmap is always top-down, regardless of the sign of biHeight. Decoders should offer YUV formats with postive biHeight, but for backward compatibility they should accept YUV formats with either positive or negative biHeight.
For compressed formats, biHeight must be positive, regardless of image orientation.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

If biCompression equals BI_RGB and the bitmap uses 8 bpp or less, the bitmap has a color table immediatelly following the BITMAPINFOHEADER structure. The color table consists of an array of RGBQUAD values. The size of the array is given by the biClrUsed member. If biClrUsed is zero, the array contains the maximum number of colors for the given bitdepth; that is, 2^biBitCount colors.
If biCompression equals BI_BITFIELDS, the bitmap uses three DWORD color masks (red, green, and blue, respectively), which specify the byte layout of the pixels. The 1 bits in each mask indicate the bits for that color within the pixel.
If biCompression is a video FOURCC, the presence of a color table is implied by the video format. You should not assume that a color table exists when the bit depth is 8 bpp or less. However, some legacy components might assume that a color table is present. Therefore, if you are allocating a BITMAPINFOHEADER structure, it is recommended to allocate space for a color table when the bit depth is 8 bpp or less, even if the color table is not used.

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

If the file to read doesn't exist, or the file to write could not write.

## Why is the third argument to `fread` always `1` in our code?

fread reads in from file fp an element of size bytes blocks number of times. So, for example, if size is 50 and blocks 10, then fread will read in from fp 10 times, each time reading in 50 bytes (for a total of 500 bytes). On each fread, it will store the bytes in a buffer pointer to by ptr.

In our code, the size is equal to 'fp', so it only needs 1 time to read the file.

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3

## What does `fseek` do?

skip ove the padding in file to read.

## What is `SEEK_CUR`?

If you want to change the location of the pointer fp from its current location, set from_where to SEEK_CUR

## Whodunit?

It was Professor Plum with the candlestick in the library.
