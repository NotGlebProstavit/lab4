#include "log.h"

int compID(const Log* log1, const Log* log2){
    return log1->ID - log2->ID;
}

int compLevel(const Log* log1, const Log* log2){
    return log1->level - log2->level;
}

int compText(const Log* log1, const Log* log2){
    int len1 = strlen(log1->text), len2 = strlen(log2->text);
    int len = len1 < len2? len1: len2;
    for(int i = 0; i < len; i++){
        if(log1->text[i] < log2->text[i]) return -1;
        else if(log1->text[i] > log2->text[i]) return 1;
    }
    return len1 < len2? -1: len1 == len2? 0: 1;
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
