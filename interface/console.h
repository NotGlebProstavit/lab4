#ifndef LAB4_CONSOLE_H
#define LAB4_CONSOLE_H

#include "stdio.h"
#include "../log/log.h"
#include "readline/readline.h"

void consoleInput(Log**, int*);
void consoleOutput(const Log*, int);

void consoleInputLog(Log*);

#endif
