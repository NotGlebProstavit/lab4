#ifndef LAB4_INPUT_H
#define LAB4_INPUT_H

#include "stdio.h"
#include "readline/readline.h"
#include "freadline/freadline.h"
#include "../log/log.h"
#include "menu.h"
#include "../randomize/randomize.h"
#include "../update/update.h"

Log* input(Log*, int*);

Log* consoleInput(Log*, int*);
Log* consoleInputOne(Log*);

Log* fileInput(FILE*, Log*, int*);

int validInput(int, int);
char* validInputLevel();
FILE* validFile();

#endif //LAB4_INPUT_H
