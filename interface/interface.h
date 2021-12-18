#ifndef LAB4_INTERFACE_H
#define LAB4_INTERFACE_H

#include "stdio.h"
#include "../log/log.h"
#include "../update/sorts.h"
#include "../update/update.h"
#include "console.h"
#include "file.h"
#include "../randomize/randomize.h"


void printMenu();
void printInputMenu();
void printOutputMenu();
void printUpdateMenu();
void printSortMenu();
void printParamSortMenu();
int inputPointMenu(int);
int inputIndex(int);
int(*getComp(int))(const void*, const void*);
void*(*getSort(int))(void*, size_t, size_t, int(*)(const void*, const void*));
void input(Log**, int*);
void output(Log*, int);
void update(Log**, int*, int*);

#endif
