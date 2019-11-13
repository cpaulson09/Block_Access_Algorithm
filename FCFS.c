//Author: Connor Paulson
#include <stdio.h>
#include <stdlib.h>

#include "blockalgorithms.h"

void FCFS(int blocks[], int numBlocks){

	int i = 0;
	int totalSeek = 0;

 	for (i = 0; i < numBlocks - 1; i++){

 		// printf("Currently at: %d\n\n", blocks[i]);
 		if (blocks[i] > blocks[i+1]){
 			totalSeek += blocks[i] - blocks[i+1];
 		}
 		else{
 			totalSeek += blocks[i+1] - blocks[i];
 		}
	}
 	printf("\nFCFS Total Seek: %d\n", totalSeek);
}