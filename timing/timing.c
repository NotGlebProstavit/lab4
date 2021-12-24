#include "timing.h"

double getAverage(int seed, int len, void*(*sort)(void*, size_t, size_t, int(*)(const void*, const void*)), int k){
    double sum = 0.0;
    Log* logs;
    for(int i = 0; i < k; i++){
        int n = len;
        logs = generateNLog(seed, len, logs);
        clock_t begin = clock();
        sort(logs, len, sizeof(Log), (int (*)(const void *, const void *)) compID);
        clock_t end = clock();
        sum += (double)(end-begin)/CLOCKS_PER_SEC;
        freeAll(&logs, &n);
    }
    return sum/k;
}

void timingOne(int seed, void*(*sort)(void*, size_t, size_t, int(*)(const void*, const void*)), char* s, int k){
    printf("len,avgTime,sorts\n");
    for(int i = 1; i <= 10; i++){
        int len = i*5000;
        printf("%d,%lf,%s\n",len, getAverage(seed, len, sort, k), s);
    }
}

void timing(){
    printf("What sort do you want to timing?\n");
    printf(" 1) Comb sort\n");
    printf(" 2) Insert sort with binary search\n");
    printf(" 3) Double selection sort\n");
    int n = validInput(1, 3);
    printf("How many dimensions do it do for a value?\nYour answer: ");
    int k;
    scanf("%d", &k);
    char *s = NULL;
    void*(*sort)(void*, size_t, size_t, int(*)(const void*, const void*)) = getSort(n);
    if(sort == combSort){
        s = "combSort";
    } else if(sort == insertWithBinarySearchSort){
        s = "insertWithBinarySearchSort";
    } else if(sort == doubleSelectionSort){
        s = "doubleSelectionSort";
    }
    printf("Enter seed for randomization: ");
    int seed;
    scanf("%d", &seed);
    timingOne(seed, sort, s, k);
}