#include "file.h"

int fileInput(Log* logs, char* filename){
	if(access(filename, F_OK) != 0){
		printf("This file doesn't exist\n");
		return 0;
	}
	int len = 0;
	char buf[BUFSIZ];
	FILE* mf = fopen(filename, "r");
	char* line;
	if(mf == NULL){
		printf("ERROR\n");
		return 0;
	}
	if(logs != NULL) free(logs);
	while(1){
		line = fgets(buf, BUFSIZ, mf);
		if(line == NULL){
			if(feof(mf) != 0){
				printf("Read the file is finished\n");
				fclose(mf);
				return len;
			} else {
				printf("ERROR\n");
				if(logs != NULL) free(logs);
				return 0;
			}
		}
		char* copy_line = strdup(line);
		char* strID = strtok(copy_line, ",");
		int ID;
		char* strLevel = strtok(NULL, ",");
		int level;
		char* text = strtok(NULL, ",");
		sscanf(strID, "%d", &ID);
		if(!strcmp(strLevel, "DEBUG")) level = 0;
		else if(!strcmp(strLevel, "INFO")) level = 1;
		else if(!strcmp(strLevel, "WARN")) level = 2;
		else if(!strcmp(strLevel, "ERROR")) level = 3;
		else if(!strcmp(strLevel, "FATAL")) level = 4;
		else {
			printf("Incorrect line: %s\n", line);
			if(logs != NULL) free(logs);
			return 0;
		}
		Log log = {ID, level, strdup(text)};
		logs = realloc(logs, (len+1)*sizeof(Log));
		memcpy(logs+len*sizeof(Log), &log, sizeof(Log));
		len++;
	}
}

void fileOutput(const Log* logs, int n, char* filename){
	FILE* fm = fopen(filename, "w");
	if(fm == NULL){
		printf("ERROR\n");
		return;
	}
	for(int i = 0; i < n; i++){
		fprintf(fm, "%s\n", logToString(&logs[i]));
	}
	fclose(fm);
}
