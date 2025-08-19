/* A naive pattern-matchin program study */
/* use: prog [file] [pattern]            */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXLINE 512
#define RED "\033[1;31m"
#define RESET "\033[0m"

int my_getline(char*, int, FILE*);
int matcher(char *, char *);

int main(int argc, char *argv[]){
    FILE *fptr;
    char *pat, line[MAXLINE], *temp;
    int idx; // index of match
    int pat_len; // length of pattern

    fptr = fopen(argv[1], "r");
    if (!fptr){
        printf("%s: error opening the file: %s", argv[0], argv[1]);
        exit(EXIT_FAILURE);
    }
    pat = strdup(argv[2]);
    pat_len = strlen(pat);

    while ((my_getline(line, MAXLINE, fptr)) != EOF){
        idx = matcher(line, pat);
        if (idx >= 0){
            temp = line;
            line[idx] = '\0';
            temp = temp + (strlen(line) + pat_len);
            printf("%s%s%s%s%s\n", line, RED, pat, RESET, temp);
        }
    }
    
    fclose(fptr);
}

/*my_getline, return len of line*/

int my_getline(char *line, int max, FILE *fptr){
    int c, i = 0;

    while ((c = fgetc(fptr)) != '\n' && c != EOF)
        line[i++] = c;
    if (c == EOF && i == 0)
        return EOF;
    line[i] = '\0';
    return strlen(line);
}



/*matcher function, return index of match*/

int matcher(char *line, char *pat){
    int len = strlen(pat)-1, i = 0, ctr = 0, idx = 0;
    char *temp;

    while (*line != '\n' || *line != EOF){
        while (*line){
            if (*line == *pat){
                temp = strdup(pat);
                idx = ctr;
                for(i = 0; i <= len && *line == *temp; i++, ctr++){
                    if (i == len)
                        return idx;
                    *line++, temp++;
                }
            }
            line++, ctr++;
        }
    return -1;
    }
 }
