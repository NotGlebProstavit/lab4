#include "output.h"

void consoleOutput(Log* logs, int len){
    for(int i = 0; i < len; i++){
        char* strLog = logToString(logs + i);
        printf("%s\n", strLog);
        free(strLog);
    }
}

void fileOutput(FILE* fm, Log* logs, int len){
    for(int i = 0; i < len; i++){
        char* strLog = logToString(logs + i);
        fprintf(fm,"%s\n", strLog);
        free(strLog);
    }
}

void output(Log* logs, int len){
    printOutputMenu();
    int n = validInput(1, 3);
    switch (n) {
        case 1:{
            consoleOutput(logs, len);
            break;
        }
        case 2:{
            printFileField(2);
            char* filename = readline("");
            FILE* fm = fopen(filename, "w");
            fileOutput(fm, logs, len);
            free(filename);
            fclose(fm);
            break;
        }
        default: return;
    }
}