#include <stdio.h>
#include <string.h>

void history();

void count(char[], int *, int *);

int countLine();

int main() {
    char str[510];
    FILE *writeFile;
    writeFile = fopen("history.txt", "a");
    int i = countLine();
    while (-1) {
        int charCount = 0, wordCount = 0;
        printf("Enter string, or \"exit\" to end program:\n");
        gets(str);
        if (strcmp(str, "exit") == 0) break;
        else if (strcmp(str, "history") == 0) {
            fclose(writeFile);
            history();
            writeFile = fopen("history.txt", "a");
        } else {
            fprintf(writeFile, "%d: %s\n", i, str);
            i++;
            count(str, &charCount, &wordCount);
            printf("%d words\n%d chars\n", wordCount, charCount);
        }
    }

    fclose(writeFile);

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
    int i = 0;
    int len = strlen(str);

    while (i < len) {
        if (str[i] != ' ')
            (*charCount)++;
        else if ((*charCount)!=0 &&str[i + 1] != ' ' && str[i + 1] != '\0')
            (*wordCount)++;
        i++;
    }
    if((*charCount)>1)
    (*wordCount)++;
}