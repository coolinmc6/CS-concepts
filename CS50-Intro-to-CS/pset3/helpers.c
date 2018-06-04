// Helper functions for music

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include "helpers.h"
#include <math.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // TODO
    // double numerator = fraction[0];
    // double denominator = fraction[2];


    // double duration = (8 / denominator) * numerator;
    // // printf("%d\n", duration);
    // return duration;


    int x = atoi(&fraction[0]);
    int y = atoi(&fraction[2]);
    int dur = (8./y)*x;
    //printf("%i",dur);
    return dur;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    char key = note[0];
    // printf("Key: %c\n", key);
	float semitone = 0;
	int octave;
	if (note[1] == '#' || note[1] == 'b')
	{
		octave = atoi(&note[2]);
		semitone += note[1] == '#' ? 1 : -1;
	}
	else
	{
		octave = atoi(&note[1]);
	}



	// Adjust semitone based on key
	// C - B
	if(key == 'C') {
		semitone += -9;
	} else if(key == 'D') {
		semitone += -7;
	} else if(key == 'E'){
		semitone += -5;
	} else if(key == 'F'){
		semitone += -4;
	} else if(key == 'G'){
		semitone += -2;
	} else if(key == 'B'){
		semitone += 2;
	}

	// Adjust semitone based on octave
	semitone += ((octave - 4)*12);

    // printf("Octave: %i\n", octave);
// 	printf("Semitone: %f\n", semitone);

	// Calculate frequency
	double frac = semitone/12;
// 	printf("Numerator: %f\n", frac);
	double frequency = round(440 * pow(2,frac));

    return frequency;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // TODO
    int rest = s[0];
    if(rest)
    {
        return 0;
    }
    return 1;
}
