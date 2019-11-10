#include <stdlib.h>
#include <stdio.h>

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
// void FCFS(int blocks[]){

// 	int i = 0;
// 	int totalSeekAccumulator = 0;
// 	int add2Total = 0;

// 	for (i = 0; i < LIMIT; i++){

// 		printf("Currently at: %d\n", blocks[i]);
// 		if (blocks[i] > blocks[i+1]){
// 			add2Total = blocks[i] - blocks[i+1];
// 			// printf("add2total: %d\n", add2Total);  
// 		}
// 		else{
// 			add2Total = blocks[i+1] - blocks[i];
// 			// printf("add2total else: %d\n", add2Total);
// 		}
// 		totalSeekAccumulator = totalSeekAccumulator + add2Total;
// 		add2Total = 0;
// 	}
// 	printf("\nFCFS Total Seek: %d\n", totalSeekAccumulator);
// }

int main(int argc, char* argv[]){

	getFileContents(argc, argv[1]);

    // printf("\nblocks\n");
	// printf("------\n");
	// for (int i = 0; i < LIMIT; i++){
	// 	printf("%d\n", blockList[i]);
	// } 

	FCFS(blockList);

    printf("\n");
return 0;
}
