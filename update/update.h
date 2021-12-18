#ifndef LAB4_UPDATE_H
#define LAB4_UPDATE_H

#include "../log/log.h"
#include "string.h"

void insertByIndex(Log**, int*, int, const Log*);
void insertToSorted(Log**, int*, const Log*, int(*)(const Log*, const Log*));
void deleteNFrom(Log**, int*, int, int);
void freeAll(Log**, int*);

#endif
