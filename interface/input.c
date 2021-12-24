#include "input.h"

Log* input(Log* logs, int* len){
    if(*len != 0) freeAll(logs, len);
    printInputMenu();
    int n = validInput(1, 4);
    switch (n) {
        case 1:{
            logs = consoleInput(logs, len);
            break;
        }
        case 2:{
            FILE* fm = validFile();
            logs = fileInput(fm, logs, len);
            fclose(fm);
            break;
        }
        case 3:{
            printf("Enter seed for generation: ");
            int seed = 31012004;
            scanf("%d", &seed);
            printf("Enter size massive: ");
            scanf("%d", len);
            logs = generateNLog(seed, *len, logs);
            break;
        }
        default:{
            return logs;
        }
    }
    return logs;
}

Log* consoleInput(Log* logs, int* len){
    int n;
    printf("How many elements do you want create?\n");
    printf("Your answer: ");
    scanf("%d", &n);
    logs = (Log*) realloc(logs, n);
    for(int i = 0; i < n; i++){
        consoleInputOne(logs + i);
    }
    *len = n;
    return logs;
}

Log* consoleInputOne(Log* log){
    printf("Input data:\n");
    printf("  ID: ");
    scanf("%d", &(log->ID));
    char* level = validInputLevel();
    log->level = stringToLevel(level);
    free(level);
    log->text = readline("  TEXT: ");
    return log;
}

int validInput(int min, int max){
    int n;
    while(1){
        printf("Your answer: ");
        scanf("%d", &n);
        if(n >= min && n <= max) return n;
        printf("You can enter from %d to %d\n", min, max);
    }
}

char* validInputLevel(){
    char* s;
    while(1){
        s = readline("  LEVEL (DEBUG, INFO, WARN, ERROR, FATAL):");
        if(!strcmp(s, "DEBUG") || !strcmp(s, "INFO") ||
        !strcmp(s, "WARN") || !strcmp(s, "ERROR") || !strcmp(s, "FATAL")) return s;
        printf("This level don't exist\n");
        free(s);
    }
}

FILE* validFile(){
    FILE* fm; char* filename;
    while(1){
        printFileField(1);
        filename = readline("");
        if((fm = fopen(filename, "r")) != NULL){
            free(filename);
            return fm;
        }
        printf("This file doesn't exist\n");
        fclose(fm);
        free(filename);
    }
}

Log* fileInput(FILE* fm, Log* logs, int* len){
    int n = 0;
    while(!feof(fm)){
        char* data = freadline(fm);
        if(data) {
            logs = (Log *) realloc(logs, (n + 1) * sizeof(Log));
            stringToLog(data, logs + n);
            n++;
        }
        free(data);
    }
    *len = n;
    return logs;
}
