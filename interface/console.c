#include "console.h"

void consoleInput(Log** logs, int* len){
	if(*logs != NULL){
		freeAll(logs, len);
	}

	printf("How many logs do you input?\n");
	printf("Your answer: ");
	scanf("%d", len);
	*logs = (Log*) malloc((*len)*sizeof(Log));
	for(int i = 0; i < (*len); i++){
		printf("-------------------------------\n");
		Log log;
        consoleInputLog(&log);
        copyLog(*logs + i, &log);
        free(log.text);
	}
	printf("-------------------------------\n");
}

void consoleOutput(const Log* logs, int n){
	printf("-------------------------------\n");
	for(int i = 0; i < n; i++){
		char* text = logToString(logs+i);
		printf("%s\n", text);
		free(text);
	}
	printf("-------------------------------\n");
}

void consoleInputLog(Log* log){
	printf("Insert data:\n");
	printf(" ID: ");
	int ID;
	scanf("%d", &ID);
	log->ID = ID;
	char* strLine = readline(" LEVEL (DEBUG, INFO, WARN, ERROR, FATAL): ");
	ImportanceLevel level = stringToLevel(strLine);
	log->level = level;
	free(strLine);
	log->text = readline(" TEXT: ");
}
