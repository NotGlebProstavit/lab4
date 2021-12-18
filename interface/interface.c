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
	printf("Choose what type of sort massive will be sorted\n");
	printf(" 1) Comb sort\n");
	printf(" 2) Insert sort with binary search\n");
	printf(" 3) Double selection sort\n");
}

void printParamSortMenu(){
	printf("Choose sorting param\n");
	printf(" 1) ID\n");
	printf(" 2) LEVEL\n");
	printf(" 3) TEXT\n");
}

int inputIndex(int maxLen){
    while(1){
        int cmd;
        printf("Your answer: ");
        scanf("%d", &cmd);
        if(cmd >= 1 && cmd <= maxLen) return cmd;

        printf("You can insert from 0 to %d\n", maxLen);
    }
}

int inputPointMenu(int maxLen){
    while(1){
        int cmd;
        printf("Your answer: ");
        scanf("%d", &cmd);
        if(cmd >= 1 && cmd <= maxLen) return cmd;

        printf("This point don't exist\n", maxLen);
    }
}

int(*getComp(int n))(const void*, const void*){
    int(*comp)(const void*, const void*);
    switch (n) {
        case 1: comp = (int (*)(const void *, const void *)) compID; break;
        case 2: comp = (int (*)(const void *, const void *)) compLevel; break;
        case 3: comp = (int (*)(const void *, const void *)) compText; break;
    }
    return comp;
}

void input(Log** logs, int* len){
    printInputMenu();
    int n = inputPointMenu(4);
    switch (n) {
        case 1:{
            consoleInput(logs, len);
            break;
        }
        case 2:{
            fileInput(logs, len);
            break;
        }
        case 3:{
            if(*logs != NULL)
                freeAll(logs, len);
            printf("Enter len of massive: ");
            scanf("%d", len);
            printf("Enter seed of randomize: ");
            int seed; scanf("%d", &seed);
            *logs = (Log*) malloc(*len * sizeof(Log));
            generateNLog(seed, *len, *logs);
            break;
        }
    }
}

void output(Log* logs, int len){
    printOutputMenu();
    int n = inputPointMenu(3);
    switch (n) {
        case 1: {
            consoleOutput(logs, len);
            break;
        }
        case 2:{
            fileOutput(logs, len);
            break;
        }
    }
}

void update(Log** logs, int* len, int* sorted){
    printUpdateMenu();
    int n = inputPointMenu(5);
    switch (n) {
        case 1:{
            Log log;
            consoleInputLog(&log);
            printf("What index do you want insert?\nYour answer: ");
            int index = inputIndex(*len);
            insertByIndex(logs, len, index, &log);
            *sorted = 0;
            break;
        }
        case 2:{
            if(sorted == 0){
                printf("Massive is not sorted\n");
                break;
            }
            Log log;
            consoleInputLog(&log);
            insertToSorted(logs, len, &log, (int (*)(const Log *, const Log *)) getComp(*sorted));
            break;
        }
        case 3:{
            int m, from;
            do {
                printf("How many elements do you want to delete?\n");
                printf("Your answer: ");
                scanf("%d", &m);
                printf("Which index do you want to delete from?\n");
                printf("Your answer: ");
                scanf("%d", &from);
                if(m + from < *len) break;
                printf("How many elements don't exist\n");
            }while(1);
            deleteNFrom(logs, len, from, m);
            *sorted = -1;
            break;
        }
        case 4:{
            printSortMenu();
            int sort = inputPointMenu(3);
            printParamSortMenu();
            int param = inputPointMenu(3);
            getSort(sort)(*logs, *len, sizeof(Log), getComp(param));
            *sorted = param;
            break;
        }
    }
}

void*(*getSort(int n))(void*, size_t, size_t, int(*)(const void*, const void*)){
    switch (n) {
        case 1: {
            return combSort;
        }
        case 2:{
            return insertWithBinarySearchSort;
        }
        case 3:{
            return doubleSelectionSort;
        }
    }
}
