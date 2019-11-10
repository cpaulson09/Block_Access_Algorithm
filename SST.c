#include <stdio.h>
#include <stdlib.h>

#include "blockalgorithms.h"

int findClosest(int blocks[], int completed[], int num, int current);
void SST(int blocks[], int num) {
	int completed[num];
	int seek = 0;
	int current = 0;
	int used = 0;
	int closest = 0;

	for(int i = 0; i < num; ++i) {
		completed[i] = 0;
	}
	
	completed[current] = 1;
	for (int i = 0; i < num - 1; ++i) {
		closest = findClosest(blocks, completed, num, current);
		seek += abs(blocks[current] - blocks[closest]);
		used++;
		current = closest;
		completed[current] = 1;
	}

	printf("SSTF Total Seek: %d\n", seek);
	
}

int findClosest(int blocks[], int completed[], int num, int current) {
	int closest = 0;
	int value = 0;
	for(int i = 0; i < num; ++i) {
		if(completed[i] == 0) {
			closest = i;
			value = abs(blocks[closest] - blocks[current]);
			break;
		}
	}

	for(int i = 0; i < num; ++i) {
		if(completed[i] == 0 && abs(blocks[i] - blocks[current]) < value) {
			value = abs(blocks[i] - blocks[current]);
			closest = i;
		}
	}
	return closest;
}
