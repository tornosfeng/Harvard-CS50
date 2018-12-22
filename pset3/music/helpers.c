// Helper functions for music

#include <cs50.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int numerator = atoi(strtok(fraction, "/"));
    int denominator = atoi(strtok(NULL, "/"));
    int frac = numerator * 8 / denominator;
    return frac;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    char abc[6];
    for (int i = 0; i < strlen(note); i++)
    {
        abc[i] = note[i];
    }
    abc[strlen(note)] = '\0';

    int n = 0, b_n = 0;

    if (strlen(note) == 2) //like A4
    {
        if (abc[0] == 'A')
        {
            b_n = 0;
        }
        else if (abc[0] == 'B')
        {
            b_n = 2;
        }
        else if (abc[0] == 'C')
        {
            b_n = -9;
        }
        else if (abc[0] == 'D')
        {
            b_n = -7;
        }
        else if (abc[0] == 'E')
        {
            b_n = -5;
        }
        else if (abc[0] == 'F')
        {
            b_n = -4;
        }
        else if (abc[0] == 'G')
        {
            b_n = -2;
        }

        n = b_n + ((int)(abc[1] - '0') - 4) * 12;
    }
    else if (strlen(note) == 3) //like A#4
    {
        char black[6];
        black[0] = abc[0];
        black[1] = abc[1];
        black[2] = '\0';
        if (strcmp(black, "C#") == 0 || strcmp(black, "Db") == 0)
        {
            b_n = -8;
        }
        else if (strcmp(black, "D#") == 0 || strcmp(black, "Eb") == 0)
        {
            b_n = -6;
        }
        else if (strcmp(black, "F#") == 0 || strcmp(black, "Gb") == 0)
        {
            b_n = -3;
        }
        else if (strcmp(black, "G#") == 0 || strcmp(black, "Ab") == 0)
        {
            b_n = -1;
        }
        else if (strcmp(black, "A#") == 0 || strcmp(black, "Bb") == 0)
        {
            b_n = 1;
        }
        n = b_n + ((int)(abc[2] - '0') - 4) * 12;
    }



    int freq = round(pow(2, n / 12.0) * 440);

    return freq;

}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strcmp(s, "") == 0)
    {
        return 1;
    }// TODO
    else
    {
        return 0;
    }
}
