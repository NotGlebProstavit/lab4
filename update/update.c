#include "update.h"

void insertByIndex(Log** logs, int* n, int index, const Log* log){
	int len = *n;
	*logs = (Log*) realloc(*logs, (len+1)*sizeof(Log));
	for(int i = len; i > index; i--){
		(*logs)[i].ID = (*logs)[i-1].ID;
		(*logs)[i].level = (*logs)[i-1].level;
		char* buf = strdup((*logs)[i-1].text);
		(*logs)[i].text = buf;
		free((*logs)[i-1].text);
	}
	(*logs)[index].ID = log->ID;
	(*logs)[index].level = log->level;
	char* text = strdup(log->text);
	(*logs)[index].text = text;
	(*n)++;
}

void insertToSorted(Log** logs, int* n, const Log* log, int(*comp)(const Log*, const Log*)){
	int i = 0;
	for(; i < *n-1; i++){
		if(comp(*logs + i, log) < 0 && comp(log, *logs + i + 1) < 0){
			break;
		}
	}	
	insertByIndex(logs, n, i, log);
}
