//Author: Connor Paulson
#include <stdio.h>
#include <stdlib.h>
#include "blockalgorithms.h"

void nonCircular(int *locationArray, int num){

	const int NUM_LOCATIONS = num;
	int startLocation = 0;
	int largerArray[NUM_LOCATIONS];
	int smallerArray[NUM_LOCATIONS];
	int locations[NUM_LOCATIONS];

	for(int i = 0; i < NUM_LOCATIONS; i++){

		locations[i] = *locationArray;
		locationArray++;

	}

	largerArray[0] = locations[0];
	smallerArray[0] = 0;


	createUpperArray(locations, largerArray, NUM_LOCATIONS);
	createLowerArray(locations, smallerArray, largerArray, NUM_LOCATIONS);

	//calculate total seek
	int startingPosition = largerArray[0];
	int seek = 0;
	int totalSeek = 0;

	for(int i = 0; i < NUM_LOCATIONS; i++){

		if(largerArray[i] != 251){

			seek = largerArray[i] - startingPosition;
			totalSeek += seek;
			startingPosition = largerArray[i];
		}
	}
	for(int i = NUM_LOCATIONS - 1; i >= 0; i--){

		if(smallerArray[i] != largerArray[0]){

			seek = startingPosition - smallerArray[i];

			if(seek < 0){

				seek = seek * -1;
				totalSeek += seek;
				startingPosition = smallerArray[i];

			}
			else{

				totalSeek += seek;
				startingPosition = smallerArray[i];

			}

		}

	}
	printf("Look Total Seek: %d\n", totalSeek);
}