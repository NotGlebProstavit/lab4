#include "randomize.h"

void generateLog(int seed, Log* dist){
    srand(seed);
    dist->ID = rand() % 100000;
    dist->level = rand() % 5;
    int text_len = rand() % 20 + 1;
    dist->text = calloc(text_len, sizeof(char));
    for(int i = 0; i < text_len; i++){
        dist->text[i] = (char)((rand() % (0x5A - 0x41) + 0x41) + (rand()%2)*0x20);
    }
}

void generateNLog(int seed, int len, Log* dist){
    for(int i = 0; i < len; i++){
        generateLog(seed+i, dist + i);
    }
}