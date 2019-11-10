//Author: Connor Paulson
#include <stdio.h>
#include <stdlib.h>

#include "blockalgorithms.h"

void FCFS(int blocks[], int num){

	int i = 0;
	int totalSeekAccumulator = 0;
	int add2Total = 0;

 	for (i = 0; i < num; i++){

 		//printf("Currently at: %d\n", blocks[i]);
 		if (blocks[i] > blocks[i+1]){
 			add2Total = blocks[i] - blocks[i+1];
 			// printf("add2total: %d\n", add2Total);  
 		}
 		else{
 			add2Total = blocks[i+1] - blocks[i];
 			// printf("add2total else: %d\n", add2Total);
 		}
		totalSeekAccumulator = totalSeekAccumulator + add2Total;
		add2Total = 0;
	}
 	printf("\nFCFS Total Seek: %d\n", totalSeekAccumulator);
}