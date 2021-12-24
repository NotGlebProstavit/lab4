#include "log.h"

int compID(const Log* log1, const Log* log2){
    return log1->ID - log2->ID;
}

int compLevel(const Log* log1, const Log* log2){
    return log1->level - log2->level;
}

int compText(const Log* log1, const Log* log2){
    return strcmp(log1->text, log2->text);
}

char* levelToString(ImportanceLevel level){
    switch (level) {
        case DEBUG:
            return "DEBUG";
        case INFO:
            return "INFO";
        case WARN:
            return "WARN";
        case ERROR:
            return "ERROR";
        case FATAL:
            return "FATAL";
        default:
            return "";
    }
}

ImportanceLevel stringToLevel(char* str){
	if(strcmp(str, "DEBUG") == 0) return DEBUG;
	if(strcmp(str, "INFO") == 0) return INFO;
	if(strcmp(str, "WARN") == 0) return WARN;
	if(strcmp(str, "ERROR") == 0) return ERROR;
	if(strcmp(str, "FATAL") == 0) return FATAL;
}

char* logToString(const Log* log){
    int ID = log->ID;
    int m = 1;
    while(ID){
        m++;
        ID /= 10;
    }
    char* level = levelToString(log->level);
    int level_len = strlen(level);
    int text_len = strlen(log->text);
    int len = m + 1 + level_len + 1 + text_len;
    char* p = calloc(len+1, sizeof(char));
    sprintf(p, "%d,%s,%s", log->ID, level, log->text);
    return p;
}

void copyLog(Log* dist, const Log* src){
    dist->ID = src->ID;
    dist->level = src->level;
    if(dist->text) free(dist->text);
    dist->text = (char*) calloc(strlen(src->text)+1, sizeof(char));
    strcpy(dist->text, src->text);
}

Log* stringToLog(char* data, Log* log){
    sscanf(strtok(data, ","), "%d", &(log->ID));
    log->level = stringToLevel(strtok(NULL, ","));
    char* text = strtok(NULL, ",");
    log->text = (char*) calloc(strlen(text)+1, sizeof(char));
    strcpy(log->text, text);
    return log;
}

int(*getComp(int n))(const Log*, const Log*){
    switch (n) {
        case 1: return compID;
        case 2: return compLevel;
        case 3: return compText;
        default: return compID;
    }
}
