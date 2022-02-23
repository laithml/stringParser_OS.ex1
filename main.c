#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void history();

void count(char[], int *, int *);

int countLine();

int main() {

    char str[510];

    while (-1) {
        int charCount = 0, wordCount = 0;
        printf("Enter string, or \"exit\" to end program:\n");
        gets(str);
        if (strcmp(str, "exit") == 0) break;
        else if (strcmp(str, "history") == 0) {

            history();
        } else {
            count(str, &charCount, &wordCount);

            printf("%d words\n%d chars\n", wordCount, charCount);
        }
    }


    return 0;
}

void history() {
    FILE *readFile;
    readFile = fopen("history.txt", "r");
    char c = fgetc(readFile);;
    while (c != EOF) {
        printf("%c", c);
        c = fgetc(readFile);
    }
    fclose(readFile);
}

int countLine() {
    FILE *readFile;
    readFile = fopen("history.txt", "r");
    int counter = 0;
    char c = fgetc(readFile);;
    while (c != EOF) {
        if (c == '\n') counter++;
        c = fgetc(readFile);

    }
    fclose(readFile);
    return counter;
}

void count(char str[], int *charCount, int *wordCount) {
    FILE *writeFile;
    writeFile = fopen("history.txt", "a");
    int lineCounter=countLine();
    int i = 0;
    int len = strlen(str);
    char *word;
    int start=0;
    int end=0;
    fprintf(writeFile,"%d: ",lineCounter);
    while (i < len+1) {
        if(end!=0){
            int length=(end-start+1);
            word=(char*) malloc (sizeof(char)*length);
            strncpy(word,&str[start],length);

            fprintf(writeFile,"%s",word);
            free(word);


            end=0;
        }
        if(i>0&&str[i]!=' '&&str[i-1]==' ')
            start=i;
        if(str[i]!=' '&&(str[i+1]==' '||str[i+1]=='\0'))
            end=i;

        if (str[i] != ' '){
            (*charCount)++;
        }
        else if ((*charCount)!=0 &&str[i + 1] != ' ' && str[i + 1] != '\0'){
            (*wordCount)++;
            fprintf(writeFile,"%c",str[i]);
        }
        i++;
    }
    fprintf(writeFile,"\n");

    if((*charCount)>1)
    (*wordCount)++;


    fclose(writeFile);
}