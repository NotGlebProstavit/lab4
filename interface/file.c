#include "file.h"

int fileInput(Log** logs, const char* filename){
	int len = 0;
	char buf[BUFSIZ];
	FILE* fm;
	if((fm=fopen(filename, "r")) == NULL){
		printf("Cannot open file\n");
		return 0;
	}
	if(*logs != NULL) free(*logs);

	while(!feof(fm)){
		if(!fgets(buf, BUFSIZ, fm)) break;
		len++;
	}
	*logs = (Log*) malloc(len*sizeof(Log));
	rewind(fm);
	int i = 0;
	while(!feof(fm)){
		if(fgets(buf, BUFSIZ, fm)){
		
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
	return len;
}

void fileOutput(const Log* logs, int n, char* filename){
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
