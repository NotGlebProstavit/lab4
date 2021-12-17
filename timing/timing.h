//
// Created by vpust on 16.12.2021.
//

#ifndef LAB4_TIMING_H
#define LAB4_TIMING_H
#include "stdio.h"
#include "../log/log.h"
#include "../randomize/randomize.h"
#include "time.h"
#include "../update/update.h"
#include "../update/sorts.h"

double getAverage(int, void*(*sort)(void*, size_t, size_t, int(*)(const void*, const void*)));
void timing();

#endif //LAB4_TIMING_H
