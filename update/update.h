#ifndef LAB4_UPDATE_H
#define LAB4_UPDATE_H

#include "../log/log.h"
#include "sorts.h"
#include "../interface/input.h"

void freeAll(Log*, int*);

Log* insertByIndex(Log*, int*, const Log*, int);
Log* insertSorted(Log*, int*, const Log*, int(*)(const Log*, const Log*));
Log* deleteNM(Log*, int*, int, int);

Log* update(Log*, int*, int*);

#endif //LAB4_UPDATE_H
