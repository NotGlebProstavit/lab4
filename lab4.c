#include "stdio.h"
#include "interface/interface.h"
#include "interface/file.h"
#include "log/log.h"
#include "sorts/sorts.h"
#include "readline/readline.h"

int main(){
	int len = 0; int size = sizeof(Log);
	Log* logs = NULL;
	printMenu();
	int cmd = inputPointMenu(5);
	switch(cmd){
		case 1:
			printInputMenu();
			cmd = inputPointMenu(4);
			switch(cmd){
				case 2:
					printf("Enter file name\n");
					printf("WARNING!!!\n");
					printf(" 1) File must be near source code\n");
					printf(" 2) Every line in file must be like ID,LEVEL,TEXT\n");
					printf("    ID - integer number\n");
					printf("    LEVEL - DEBUG, INFO, WARN, ERROR, FATAL\n");
					printf("    TEXT - any text\n");
					printf("    Between part of line must be , without SPACE\n");
					char* filename = readline("Your answer: ");
					len = fileInput(logs, filename);
					printf("--> %p\n", logs);
					fileOutput(logs, len, "output.txt");
					free(filename);
					break;
			}
			break;
		case 2:
			printOutputMenu();
			cmd = inputPointMenu(3);
			switch(cmd){
				case 2:
					printf("Enter file name\n");
					printf("WARNING!!!\n");
					printf(" 1) File must be near source code\n");
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
				case 4:
					printSortMenu();
					cmd = inputPointMenu(4);
					printParamSortMenu();
					int param = inputPointMenu(3);
					int(*comp)(const Log*, const Log*);
					switch(param){
						case 1: comp = compID; break;
						case 2: comp = compLevel; break;
						case 3: comp = compText; break;
					}
					switch(cmd){
						case 1: combSort(logs, len, size, (int(*)(const void*, const void*))comp); break;
						case 2: insertWithBinarySearchSort(logs, len, size, (int(*)(const void*, const void*))comp); break;
						case 3: doubleSelectionSort(logs, len, size, (int(*)(const void*, const void*))comp); break;
							
					}
					break;
			}
			break;
	}
}
