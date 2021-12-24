#include "randomize.h"

Log* generateLog(int seed, Log* dist){
    srand(seed);
    dist->ID = rand() % 100000;
    dist->level = rand() % 5;
    int text_len = rand() % 20 + 1;
    dist->text = calloc(text_len+1, sizeof(char));
    for(int i = 0; i < text_len; i++){
        dist->text[i] = (char)((rand() % (0x5A - 0x41) + 0x41) + (rand()%2)*0x20);
    }
    return dist;
}

Log* generateNLog(int seed, int len, Log* dist){
//    if(dist != NULL) dist = freeAll(dist);
    for(int i = 0; i < len; i++){
        generateLog(seed+((i * len * 1234) % seed) , dist + i);
    }
    return dist;
}