#include "interface.h"

void printMenu(){
	printf("Enter number of menu point\n");
	printf(" 1) Input data\n");
	printf(" 2) Output data\n");
	printf(" 3) Update data\n");
	printf(" 4) Timing\n");
	printf(" 5) Exit program\n");
}

void printInputMenu(){
	printf("Enter number of input-menu point\n");
	printf(" 1) Console input\n");
	printf(" 2) File input\n");
	printf(" 3) Randomize\n");
	printf(" 4) Previous menu\n");
}

void printOutputMenu(){
	printf("Enter number of output-menu point\n");
	printf(" 1) Console output\n");
	printf(" 2) File output\n");
	printf(" 3) Previous menu\n");
}

void printUpdateMenu(){
	printf("Enter number of update-menu point\n");
	printf(" 1) Insert by index\n");
	printf(" 2) Insert to sorted massive\n");
	printf(" 3) Delete N elements start from index\n");
	printf(" 4) Sorting\n");
	printf(" 5) Previous menu\n");
}

void printSortMenu(){
	printf("Choose what typy of sort massive will be sorted\n");
	printf(" 1) Comb sort\n");
	printf(" 2) Insert sort with binary search\n");
	printf(" 3) Double selection sort\n");
	printf(" 4) Previous menu\n");
}

void printParamSortMenu(){
	printf("Choode sorting param\n");
	printf(" 1) ID\n");
	printf(" 2) LEVEL\n");
	printf(" 3) TEXT\n");
}

int inputPointMenu(int maxPoint){
	while(1){
		int cmd;
		printf("Your answer: ");
		scanf("%d", &cmd);
		if(cmd >= 1 && cmd <= maxPoint) return cmd;

		printf("This point don't exit\n");
	}
}
