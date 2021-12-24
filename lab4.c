#include "stdio.h"
#include "timing/timing.h"
#include "interface/menu.h"
#include "interface/input.h"
#include "interface/output.h"
#include "update/update.h"


int main(){
    Log* logs = NULL; int len = 0;
    int sorted = 0;
    while(1){
        printMenu();
        int n = validInput(1, 5);
        switch (n) {
            case 1:{
                printf("<------------------------------------------------>\n");
                logs = input(logs, &len);
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
                logs = update(logs, &len, &sorted);
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
                freeAll(&logs, &len);
                return 0;
            }
            default:{
                printf("This point doesn't exist\n");
            }
        }
    }
}
