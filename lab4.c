#include "stdio.h"
#include "interface/interface.h"
#include "timing/timing.h"


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
                freeAll(&logs, &len);
                return 0;
            }
        }
    }
}
