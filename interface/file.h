#ifndef LAB4_FILE_H
#define LAB4_FILE_H
#define _POSIX_C_SOURCE 200809L

#include "stdio.h"
#include "unistd.h"
#include "../log/log.h"

int fileInput(Log**, const char*);
void fileOutput(const Log*, int, char*);

#endif
