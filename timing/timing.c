//
// Created by vpust on 16.12.2021.
//

#include "timing.h"

double getAverage(int len, void*(*sort)(void*, size_t, size_t, int(*)(const void*, const void*))){
    double sum = 0.0;
    Log* logs = (Log*) malloc(len* sizeof(Log));
    generateNLog(time(NULL), len, &logs);
    for(int k = 0; k < 8; k++){
        clock_t begin = clock();
        sort(logs, len, sizeof(Log), (int (*)(const void *, const void *)) compID);
        clock_t end = clock();
        sum += (double)(end-begin)/CLOCKS_PER_SEC;
    }
    freeAll(&logs, len);
    return sum/8;
}

void timing(){
    printf("len,avgTime,sorts\n");
    for(int i = 1; i <= 10; i++){
        int len = i*10000;
        printf("%d,%lf,%s\n",len, getAverage(len,combSort), "combSort");
    }
    for(int i = 1; i <= 10; i++){
        int len = i*10000;
        printf("%d,%lf,%s\n",len, getAverage(len,insertWithBinarySearchSort), "insertWithBinarySearchSort");
    }
    for(int i = 1; i <= 10; i++){
        int len = i*10000;
        printf("%d,%lf,%s\n",len, getAverage(len,doubleSelectionSort), "doubleSelectionSort");
    }

}