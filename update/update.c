#include "update.h"

void freeAll(Log** logs, int* len){
    for(int i = 0; i < *len; i++){
        free((*logs)[i].text);
    }
    free(*logs);
    *len = 0;
}

Log* insertByIndex(Log* logs, int* len, const Log* log, int index){
    logs = (Log*) realloc(logs, (*len + 1)* sizeof(Log));
    for(int i = *len; i > index; i--){
        copyLog(logs + i, logs + i - 1);
    }
    copyLog(logs + index, log);
    *len += 1;
    return logs;
}

Log* insertSorted(Log* logs, int* len, const Log* log, int(*comp)(const Log*, const Log*)){
    if(comp(log, logs) < 0) logs = insertByIndex(logs, len, log, 0);
    else if(comp(log, logs + *len - 1) > 0) logs = insertByIndex(logs, len, log, *len);
    else {
        int index = 0;
        for (; index < *len - 1; index++) {
            if (comp(logs + index, log) < 0 && comp(log, logs + index + 1) < 0) break;
        }
        logs = insertByIndex(logs, len, log, index + 1);
    }
    return logs;
}

Log* deleteNM(Log* logs, int* len, int count, int index){
    for(int i = 0; i < count; i++){
        for(int k = index; k < *len - 1; k++){
            copyLog(logs + k, logs + k + 1);
        }
        free(logs[*len-1].text);
        *len -= 1;
    }
    logs = (Log*) realloc(logs, (*len) * sizeof(Log));
    return logs;
}

Log* update(Log* logs, int* len, int* sorted){
    printUpdateMenu();
    int n = validInput(1, 5);
    switch (n) {
        case 1:{
            printf("Where are you input new element?\n");
            int index = validInput(0, *len);
            Log log;
            consoleInputOne(&log);
            logs = insertByIndex(logs, len, &log, index);
            free(log.text);
            break;
        }
        case 2:{
            if(*sorted == 0){
                printf("Array isn't sorted\n");
                break;
            }
            int(*comp)(const Log*, const Log*) = getComp(*sorted);
            Log log;
            consoleInputOne(&log);
            logs = insertSorted(logs, len, &log, comp);
            free(log.text);
            break;
        }
        case 3:{
            printf("How many elements do you want delete?\n");
            int count = validInput(1, *len);
            printf("Which index of element do you want delete from?\n");
            int index = validInput(0, *len - 1 - count);
            logs = deleteNM(logs, len, count, index);
            break;
        }
        case 4:{
            printParamSortMenu();
            int(*comp)(const Log*, const Log*) = getComp(validInput(1, 3));
            printSortMenu();
            *sorted = validInput(1, 3);
            void*(*sort)(void*, size_t, size_t, int(*)(const void*, const void*)) = getSort(*sorted);
            sort(logs, *len, sizeof(Log), (int (*)(const void *, const void *)) comp);
            break;
        }
        default: return logs;
    }
    return logs;
}
