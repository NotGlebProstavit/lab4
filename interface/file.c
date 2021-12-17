#include "file.h"

void fileInput(Log** logs, int* n){
    char* filename;
    scanf("%*c");
    printf("Enter name of file:\n");
    printf(" - file must be near source file\n");
    printf(" - Every string must be ID,LEVEL,TEXT\n");
    filename = readline("Your answer: ");

	int len = 0;
	char* buf;
	FILE* fm;
	if((fm=fopen(filename, "r")) == NULL){
		printf("Cannot open file\n");
        *n = 0;
		return;
	}
	if(*logs != NULL) free(*logs);

	while(!feof(fm)){
		if(!freadline(fm)) break;
		len++;
	}
	*logs = (Log*) malloc(len*sizeof(Log));
	rewind(fm);
	int i = 0;
	while(!feof(fm)){
		if((buf = freadline(fm)) != NULL){
		
			char* cLine = strdup(buf);
			cLine[strlen(cLine)-1] = '\0';
			char* strID = strtok(cLine, ",");
			char* strLevel = strtok(NULL, ",");
			char* text = strtok(NULL, ",");

			int ID;
			sscanf(strID, "%d", &ID);
			ImportanceLevel level = stringToLevel(strLevel);
			(*logs)[i].ID = ID;
			(*logs)[i].level = level;
			(*logs)[i].text = strdup(text);
			i++;
			free(cLine);
		}
	}
	fclose(fm);
	printf("Read file is finished\n");
	*n = len;
}

void fileOutput(const Log* logs, int n){
    char* filename;

    printf("Enter name of file:\n");
    printf(" - file must be near source file or it will be create near\n");
    filename = readline("Your answer: ");

	FILE* fm = fopen(filename, "w");
	if(fm == NULL){
		printf("ERROR\n");
		return;
	}
	for(int i = 0; i < n; i++){
		char* str = logToString(&logs[i]);
		fprintf(fm, "%s\n", str);
		free(str);
	}
	fclose(fm);
}
