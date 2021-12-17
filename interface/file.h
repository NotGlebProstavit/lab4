#ifndef LAB4_FILE_H
#define LAB4_FILE_H
#define _POSIX_C_SOURCE 200809L

#include "stdio.h"
#include "unistd.h"
#include "../log/log.h"
#include "freadline/freadline.h"
#include "readline/readline.h"
#include "../update/update.h"

void fileInput(Log**, int*);
void fileOutput(const Log*, int);

#endif
