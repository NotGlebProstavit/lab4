#ifndef LAB4_SORTS_H
#define LAB4_SORTS_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void* combSort(void* base, size_t n, size_t size, int(*comp)(const void*, const void*));
void* insertWithBinarySearchSort(void* base, size_t n, size_t size, int(*comp)(const void*, const void*));
void* doubleSelectionSort(void* base, size_t n, size_t size, int(*comp)(const void*, const void*));

void swap(void* a, void* b, size_t size);
int binarySearch(void* base, size_t n, size_t size, int(*comp)(const void*, const void*), void* x);
int minIndex(void* base, int start, int end, size_t size, int(*comp)(const void*, const void*));
int maxIndex(void* base, int start, int end, size_t size, int(*comp)(const void*, const void*));

void*(*getSort(int))(void*, size_t, size_t, int(*)(const void*, const void*));

#endif
