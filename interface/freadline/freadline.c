#include "freadline.h"

char* freadline(FILE* fm){
    char buf[81] = {0};  // BUFSIZ - константа для длины буфера
    char *res = NULL;
    int len = 0;
    int n = 0;
    do {
        n = fscanf(fm,"%80[^\n]", buf);
        if (n < 0) {
            if (!res) {
                return NULL;
            }
        }
        else if (n > 0) {
            int chunk_len = strlen(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            memcpy(res + len, buf, chunk_len);
            len = str_len;
        }
        else {
            fscanf(fm, "%*c");
        }
    } while (n > 0);

    if (len > 0) {
        res[len] = '\0';
    }
    else {
        res = calloc(1, sizeof(char));
    }
    return res;
}