#include "menu.h"

void printMenu(){
    printf("Enter number of menu point\n");
    printf("  1) Input data\n");
    printf("  2) Output data\n");
    printf("  3) Update data\n");
    printf("  4) Timing\n");
    printf("  5) Exit\n");
}

void printInputMenu(){
    printf("Enter number of input-menu point\n");
    printf("  1) Console\n");
    printf("  2) File\n");
    printf("  3) Random\n");
    printf("  4) Back\n");
}

void printOutputMenu(){
    printf("Enter number of output-menu point\n");
    printf("  1) Console\n");
    printf("  2) File\n");
    printf("  3) Back\n");
}

void printUpdateMenu(){
    printf("Enter number of update-menu\n");
    printf("  1) Insert by index\n");
    printf("  2) Insert in sorted\n");
    printf("  3) Delete N elements from M\n");
    printf("  4) Sorted\n");
    printf("  5) Back\n");
}

void printFileField(int mod){
    switch (mod) {
        case 1:{
            printf("!!!WARNING!!!\n");
            printf("  1) Input file must be near source file\n");
            printf("  2) Every line in input file must be like ID, LEVEL,TEXT\n");
            break;
        }
        case 2:{
            printf("!!!WARNING!!!\n");
            printf("  1) If file doesn't exist it will be create\n");
            break;
        }
    }
    printf("Enter file name: ");
}

void printParamSortMenu(){
    printf("Enter number of param point:\n");
    printf("  1) ID\n");
    printf("  2) LEVEL\n");
    printf("  3) TEXT\n");
}

void printSortMenu(){
    printf("Enter number of sort point:\n");
    printf("  1) Comb sort\n");
    printf("  2) Insert sort with binary search\n");
    printf("  3) Double selection sort\n");
}