#include "sorts.h"

void swap(void* a, void* b, size_t size){
    void* t = malloc(size);
    memcpy(t, a, size);
    memcpy(a, b, size);
    memcpy(b, t, size);
    free(t);
}

void* combSort(void* base, size_t n, size_t size, int(*comp)(const void*, const void*)){
    double factor = 1.2473309;
    int step = n - 1;
    while(step >= 1){
        for(int i = 0; i+step < n; i++){
            if(comp(base+i*size, base+(i+step)*size) > 0){
                swap(base+i*size, base+(i+step)*size, size);
            }
        }
        step = (int)(step/factor);
    }
    return base;
}

int binarySearch(void* base, size_t n, size_t size, int(*comp)(const void*, const void*), void* x){
    int L = -1;
    int R = n;
    while(R - L > 1){
        int M = (R+L)/2;
        if(comp(base+M*size, x) < 0){
            L = M;
        } else {
            R = M;
        }
    }
    return R;
}

void* insertWithBinarySearchSort(void* base, size_t n, size_t size, int(*comp)(const void*, const void*)){
    for(int i = 1; i < n; i++){
        int k = binarySearch(base, i, size, comp, base+i*size);
        if(k < 0) continue;
        for(int j = i; j > k; j--){
            swap(base+(j-1)*size, base+(j)*size, size);
        }
    }
    return base;
}

int minIndex(void* base, int start, int end, size_t size, int(*comp)(const void*, const void*)){
    int minId = start;
    for(int i = start; i < end; i++){
        if(comp(base+i*size, base+minId*size) < 0) minId = i;
    }
    return minId;
}

int maxIndex(void* base, int start, int end, size_t size, int(*comp)(const void*, const void*)){
    int maxId = start;
    for(int i = start; i < end; i++){
        if(comp(base+i*size, base+maxId*size) > 0) maxId = i;
    }
    return maxId;
}

void* doubleSelectionSort(void* base, size_t n, size_t size, int(*comp)(const void*, const void*)){
    for(int i = 0; i < n/2; i++){
        int minId = minIndex(base, i, n-i, size, comp);
        if(minId != i){
            swap(base+i*size, base+minId*size, size);
        }
        int maxId = maxIndex(base, i, n-i, size, comp);
        if(maxId != n-1-i){
            swap(base+(n-1-i)*size, base+maxId*size, size);
        }
    }
    return base;
}

void*(*getSort(int n))(void*, size_t, size_t, int(*)(const void*, const void*)){
    switch (n) {
        case 1: return combSort;
        case 2: return insertWithBinarySearchSort;
        case 3: return doubleSelectionSort;
        default: return combSort;
    }
}
