#include "update.h"

void insertByIndex(Log** logs, int* n, int index, const Log* log){
	int len = *n;
	*logs = (Log*) realloc(*logs, (len+1)*sizeof(Log));
	for(int i = len; i > index; i--){
        copyLog(*logs + i, *logs + i - 1);
	}
    copyLog(*logs + index, log);
	(*n)++;
}

void insertToSorted(Log** logs, int* n, const Log* log, int(*comp)(const Log*, const Log*)){
	int i = 0;
	for(; i < *n-1; i++){
		if(comp(*logs + i, log) > 0 && comp(log, *logs + i + 1) < 0){
			break;
		}
	}	
	insertByIndex(logs, n, i, log);
}

void deleteNFrom(Log** logs, int* len, int from, int n){
    for(int k = 0; k < n; k++){
        for(int i = from; i < *len - 1; i++){
            copyLog(*logs + i, *logs + i + 1);
        }
        (*len)--;
    }
    *logs = (Log*) realloc(*logs, (*len)*sizeof(Log));
}

void freeAll(Log** logs, int *len){
    for(int i = 0; i < *len; i++){
        free((*logs)[i].text);
    }
    free(*logs);
    *len = 0;
}