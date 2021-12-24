#ifndef LAB4_OUTPUT_H
#define LAB4_OUTPUT_H

#include "stdio.h"
#include "../log/log.h"
#include "menu.h"
#include "input.h"

void output(Log*, int);

void consoleOutput(Log*, int);
void fileOutput(FILE*, Log*, int);

#endif //LAB4_OUTPUT_H
