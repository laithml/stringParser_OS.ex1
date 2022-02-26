#include <stdio.h>
#include <string.h>

void history();

const char *count(char[], int *, int *);

int countLine();

int main() {
    char str[510];
    FILE *writeFile;
    writeFile = fopen("history.txt", "a");
    int i = countLine();
    while (-1) {
        int charCount = 0, wordCount = 0;
        printf("Enter string, or \"exit\" to end program:\n");
        fgets(str, 510, stdin);
        str[strlen(str) - 1] = '\0';
        if (strcmp(str, "exit") == 0) break;
        else if (strcmp(str, "history") == 0) {
            fclose(writeFile);
            history();
            writeFile = fopen("history.txt", "a");
        } else {
            const char *word = count(str, &charCount, &wordCount);
            if (wordCount != 0) {
                if (wordCount == 1 && strcmp(word, "exit") == 0)
                    break;
                else if (wordCount == 1 && strcmp(word, "history") == 0) {
                    fclose(writeFile);
                    history();
                    writeFile = fopen("history.txt", "a");
                } else {
                    printf("%d words\n%d chars\n", wordCount, charCount);
                    fprintf(writeFile, "%d: %s\n", i, str);
                    i++;
                }
            }
        }
    }

    fclose(writeFile);

    return 0;
}

void history() {
    FILE *readFile;
    readFile = fopen("history.txt", "r");
    if (readFile == NULL) {
        perror("file doesn't exist");
    } else {
        char c = fgetc(readFile);;
        while (c != EOF) {
            printf("%c", c);
            c = fgetc(readFile);
        }
        fclose(readFile);
    }
}

int countLine() {
    FILE *readFile;
    readFile = fopen("history.txt", "r");
    if (readFile == NULL) {
        perror("file doesn't exist");
    } else {
        int counter = 0;
        char c = fgetc(readFile);;
        while (c != EOF) {
            if (c == '\n') counter++;
            c = fgetc(readFile);

        }
        fclose(readFile);
        return counter;
    }
}

const char* count(char str[], int *charCount, int *wordCount) {
    int i = 0;
    int len = strlen(str);
    char word[7];
    int wordInd = 0;

    while (i < len) {
        if (str[i] != ' ') {
            (*charCount)++;
            if ((*wordCount) < 2 && (*charCount) < 8){
                word[wordInd] = str[i];
                wordInd++;
            }

        } else if ((*charCount) != 0 && str[i + 1] != ' ' && str[i + 1] != '\0')
            (*wordCount)++;
        i++;
    }
    if ((*charCount) > 0)
        (*wordCount)++;
    word[wordInd]='\0';
    if(strcmp(word,"exit")==0)
        return "exit";
    if(strcmp(word,"history")==0)
        return "history";

    return "";
}