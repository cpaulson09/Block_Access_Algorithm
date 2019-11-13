//Author Conner Williams
#include <stdio.h>
#include <stdlib.h>
#include "blockalgorithms.h"

void circular(int *locationArray, int num){

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
	for(int i = 0; i < NUM_LOCATIONS; i++){

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
	printf("C-Look Total Seek: %d\n", totalSeek);

}






//Function to create upper array
void createUpperArray(int *locationArray, int *greaterThanArray, int num){

	const int NUM_LOCATIONS = num;
	int lowerLimit = greaterThanArray[0];
	int upperLimit = 250;
	locationArray[0] = -1;

	for(int i = 1; i < NUM_LOCATIONS; i++){

		int smallest = 251;
		int smallestPosition = 0;

		for(int i = 0; i < NUM_LOCATIONS; i++){

			if(locationArray[i] >= lowerLimit && locationArray[i] <= upperLimit && locationArray[i] < smallest){

				smallest = locationArray[i];
				smallestPosition = i;

			}

		}

		locationArray[smallestPosition] = -1;
		greaterThanArray[i] = smallest;
		lowerLimit = smallest;

	}

}






//Function to create lower array
void createLowerArray(int *locationArray, int *lessThanArray, int *greaterThanArray, int num){

	int NUM_LOCATIONS = num;
	int lowerLimit = 0;
	int upperLimit = greaterThanArray[0];
	int smallest = locationArray[1];
	int smallestPosition = 1;

	for(int i = 1; i < NUM_LOCATIONS; i++){

		if(locationArray[i] > -1 && locationArray[i] < smallest){

			smallest = locationArray[i];
			smallestPosition = i;

		}
	}

	lowerLimit = smallest;
	lessThanArray[0] = smallest;
	locationArray[smallestPosition] = -1;



	for(int i = 1; i < NUM_LOCATIONS; i++){

		smallest = greaterThanArray[0];
		smallestPosition = 0;

		for(int j = 0; j < NUM_LOCATIONS; j++){

			if(locationArray[j] > lowerLimit && locationArray[j] < upperLimit && locationArray[j] < smallest){

				smallest = locationArray[j];
				smallestPosition = j;

			}
		}

		locationArray[smallestPosition] = -1;
		lessThanArray[i] = smallest;
		lowerLimit = smallest;

	}


}
