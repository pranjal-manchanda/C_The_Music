// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    //convert string to numerator and denominator int values
    int numerator = fraction[0] - '0';
    int denominator = fraction[2] - '0';

    return (int)(((double)numerator / (double) denominator) * 8);
}


// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    //Factor is the number of keystrokes by which the current note is separated from A4
    //Begin by initializing factor to 0
    int factor = 0;
    //If the note contains an accidental or flat, increment or decrement
    if (strlen(note) == 3)
    {
        if (note[1] == '#')
        {
            factor++;
            //printf("Accidental: %i\n", factor);
        }
        if (note[1] == 'b')
        {
            factor--;
            //printf("Accidental: %i\n", factor);
        }
    }

    //Increment or Decrement factor based on the note
    switch (note[0])
    {
        case 'A':
            break;
        case 'B':
            factor = factor + 2;
            //printf("Letter: %i\n", factor);
            break;
        case 'C':
            factor = factor - 9;
            //printf("Letter: %i\n", factor);
            break;
        case 'D':
            factor = factor - 7;
            //printf("Letter: %i\n", factor);
            break;
        case 'E':
            factor = factor - 5;
            //printf("Letter: %i\n", factor);
            break;
        case 'F':
            factor = factor - 4;
            //printf("Letter: %i\n", factor);
            break;
        case 'G':
            factor = factor - 2;
            //printf("Letter: %i\n", factor);
            break;
    }

    //Calculate Octave of Note
    int octave = note[(strlen(note) - 1)] - '0';
    //printf("Octave Value: %i\n", octave);
    octave = octave - 4;
    //printf("Octave Difference: %i\n", octave);

    //For each shift in octave, increment or decrement factor by 12
    factor = factor + (12 * octave);
    //printf("Octave + Factor: %i\n", factor);

    return (round(440 * pow(2, (factor / 12.0))));
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    //Check for a blank line
    if (strcmp(s, "") == 0)
    {
        return true;
    }

    else
    {
        return false;
    }
}
