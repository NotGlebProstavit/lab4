#include "stdio.h"
#include "interface/interface.h"
#include "interface/file.h"
#include "log/log.h"
#include "update/sorts.h"
#include "update/update.h"
#include "readline/readline.h"
#include "interface/console.h"

int main(){
	int len = 0; int size = sizeof(Log);
	Log* logs = NULL;
	int sorted = -1;
	while(1){
		printMenu();
		int cmd = inputPointMenu(5);
		switch(cmd){
			case 1:
				printInputMenu();
				cmd = inputPointMenu(4);
				switch(cmd){
					case 1:
						consoleInput(&logs, &len);
						break;
					case 2:
						printf("Enter file name\n");
						printf("WARNING!!!\n");
						printf(" -> File must be near source code\n");
						printf(" -> Every line in file must be like ID,LEVEL,TEXT\n");
						printf("    ID - integer number\n");
						printf("    LEVEL - DEBUG, INFO, WARN, ERROR, FATAL\n");
						printf("    TEXT - any text\n");
						printf(" -> Between part of line must be , without SPACE\n");
						char* filename = readline("Your answer: ");
						len = fileInput(&logs, filename);
						free(filename);
						break;
				}
				break;
			case 2:
				printOutputMenu();
				cmd = inputPointMenu(3);
				switch(cmd){
					case 1:
						consoleOutput(logs, len);
						break;
					case 2:
						printf("Enter file name\n");
						printf("WARNING!!!\n");
						printf(" -> File must be near source code\n");
						char* filename = readline("Your answer: ");
						fileOutput(logs, len,  filename);
						free(filename);
						break;
				}
				break;
			case 3:
				printUpdateMenu();
				cmd = inputPointMenu(5);
				switch(cmd){
					case 1:{
						printf("Enter index for insert\n");
						int index;
						while(1){
							printf("Your answer: ");
							scanf("%d", &index);
							if(index >= 0 && index <= len) break;
							printf("You can insert by index [0, %d]", len);
						}
						Log log;
						consoleInputLog(&log);
						sorted = -1;
						break;
					}
					case 2:{
						if(sorted < 1) {
							printf("Massive isn't sorted\n");
							break;
						}
						Log log;
						consoleInputLog(&log);
						int(*comp)(const Log*, const Log*);
						switch(sorted){
							case 1: comp = compID; break;
							case 2: comp = compLevel; break;
							case 3: comp = compText; break;
						}
						insertToSorted(&logs, &len, &log, comp);
						break;
					}
					case 4:
						printSortMenu();
						cmd = inputPointMenu(4);
						printParamSortMenu();
						int param = inputPointMenu(3);
						sorted = param;
						int(*comp)(const Log*, const Log*);
						switch(param){
							case 1: comp = compID; break;
							case 2: comp = compLevel; break;
							case 3: comp = compText; break;
						}
						switch(cmd){
							case 1: combSort(logs, len, size, (int(*)(const void*, const void*))comp); sorted=1; break;
							case 2: insertWithBinarySearchSort(logs, len, size, (int(*)(const void*, const void*))comp); sorted=2; break;
							case 3: doubleSelectionSort(logs, len, size, (int(*)(const void*, const void*))comp); sorted=3; break;	
						}
						break;
				}
				break;
			case 5:
				if(logs != NULL){
					for(int i = 0; i < len; i++){
						free(logs[i].text);
					}
					free(logs);
				}
				return 0;
		}
	}	
}
