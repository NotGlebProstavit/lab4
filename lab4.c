#include "stdio.h"
#include "interface/interface.h"
#include "interface/file.h"
#include "update/sorts.h"
#include "update/update.h"
#include "interface/console.h"
#include "randomize/randomize.h"
#include "timing/timing.h"

int(*getComp(int n))(const void*, const void*){
    int(*comp)(const void*, const void*);
    switch (n) {
        case 1: comp = (int (*)(const void *, const void *)) compID; break;
        case 2: comp = (int (*)(const void *, const void *)) compLevel; break;
        case 3: comp = (int (*)(const void *, const void *)) compText; break;
    }
    return comp;
}

void input(Log** logs, int* len){
    printInputMenu();
    int n = inputPointMenu(4);
    switch (n) {
        case 1:{
            consoleInput(logs, len);
            break;
        }
        case 2:{
            fileInput(logs, len);
            break;
        }
        case 3:{
            printf("Enter len of massive: ");
            scanf("%d", len);
            printf("Enter seed of randomize: ");
            int seed; scanf("%d", &seed);
            *logs = (Log*) malloc(*len * sizeof(Log));
            generateNLog(seed, *len, *logs);
            break;
        }
    }
}

void output(Log* logs, int len){
    printOutputMenu();
    int n = inputPointMenu(3);
    switch (n) {
        case 1: {
            consoleOutput(logs, len);
            break;
        }
        case 2:{
            fileOutput(logs, len);
            break;
        }
    }
}

void update(Log** logs, int* len, int* sorted){
    printUpdateMenu();
    int n = inputPointMenu(5);
    switch (n) {
        case 1:{
            Log log;
            consoleInputLog(&log);
            printf("What index do you want insert?\nYour answer: ");
            int index = inputIndex(*len);
            insertByIndex(logs, len, index, &log);
            *sorted = 0;
            break;
        }
        case 2:{
            if(sorted == 0){
                printf("Massive is not sorted\n");
                break;
            }
            Log log;
            consoleInputLog(&log);
            insertToSorted(logs, len, &log, (int (*)(const Log *, const Log *)) getComp(*sorted));
            break;
        }
        case 3:{
            int m, from;
            do {
                printf("How many elements do you want to delete?\n");
                printf("Your answer: ");
                scanf("%d", &m);
                printf("Which index do you want to delete from?\n");
                printf("Your answer: ");
                scanf("%d", &from);
                if(m + from < *len) break;
                printf("How many elements don't exist\n");
            }while(1);
            deleteNFrom(logs, len, from, m);
            *sorted = -1;
            break;
        }
        case 4:{
            printSortMenu();
            int sort = inputPointMenu(3);
            printParamSortMenu();
            int param = inputPointMenu(3);
            switch (sort) {
                case 1: {
                    combSort(*logs, *len, sizeof(Log), getComp(param));
                    break;
                }
                case 2:{
                    insertWithBinarySearchSort(*logs, *len, sizeof(Log), getComp(param));
                    break;
                }
                case 3:{
                    doubleSelectionSort(*logs, *len, sizeof(Log), getComp(param));
                    break;
                }
            }
            *sorted = param;
            break;
        }
    }
}

int main(){
    Log* logs = NULL; int len = 0;
    int sorted = 0;
    while(1){
        printMenu();
        int n = inputPointMenu(5);
        switch (n) {
            case 1:{
                printf("<------------------------------------------------>\n");
                input(&logs, &len);
                sorted = 0;
                printf("<------------------------------------------------>\n");
                break;
            }
            case 2:{
                printf("<------------------------------------------------>\n");
                output(logs, len);
                printf("<------------------------------------------------>\n");
                break;
            }
            case 3:{
                printf("<------------------------------------------------>\n");
                update(&logs, &len, &sorted);
                printf("<------------------------------------------------>\n");
                break;
            }
            case 4:{
                printf("<------------------------------------------------>\n");
                timing();
                printf("<------------------------------------------------>\n");
                break;
            }
            case 5:{
                freeAll(&logs, len);
                return 0;
            }
        }
    }
}
