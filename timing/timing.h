#ifndef LAB4_TIMING_H
#define LAB4_TIMING_H

#include "stdio.h"
#include "../log/log.h"
#include "../randomize/randomize.h"
#include "time.h"
#include "../update/update.h"
#include "../update/sorts.h"

double getAverage(int, void*(*)(void*, size_t, size_t, int(*)(const void*, const void*)));
void timingOne(void*(*)(void*, size_t, size_t, int(*)(const void*, const void*)), char*);
void timing();

#endif //LAB4_TIMING_H
