#include <stdlib.h>
#include <stdio.h>

#include "blockalgorithms.h"

//Program 7 Block Access Algorithms

#define LIMIT 20

int blockList[LIMIT];

void getFileContents(int argc, char file[]){
	FILE *filePtr;
	char *filename = file;
	filePtr = fopen(filename, "r");

	if(argc < 2){
		printf("please give file name\n");
	}
	if (!filePtr){//if no file
		printf("No File Contents\n");
		//return 1;
		exit(0);
	}

	int a = 0;
	int num;
	//get each value from file
	while(fscanf(filePtr, "%d", &num) > 0){
        blockList[a] = num;
		a++;
	}
	
	fclose(filePtr);
}
/* void FCFS(int blocks[]){

// 	int i = 0;
// 	int combinedSeekTime = 0;
// 	int add2Total = 0;

// 	for (i = 0; i < LIMIT; i++){
// 		if (blocks[i] > )
// 		add2Total = blocks[i] - blocks[i+1];
// 		combinedSeekTime = combinedSeekTime + add2Total;
// 	}

// 	printf("FCFS Total Seek: %d\n", combinedSeekTime);
 }*/

int main(int argc, char* argv[]){

	getFileContents(argc, argv[1]);

    printf("\nblocks\n");
	printf("------\n");
	for (int i = 0; i < LIMIT; i++){
		printf("%d\n", blockList[i]);
	} 

//	FCFS(blockList);
	SST(blockList, LIMIT);

    printf("\n");
return 0;
}
