#include <stdio.h>
#include <string.h>

void history();

const char *count(char[], int *, int *);

int countLine();

int main() {
    char str[512];//I added 2 to the length because there's '\n\0' at the end of the str
    FILE *writeFile;
    writeFile = fopen("history.txt", "a");
    if(writeFile==NULL){
        perror("cant create a new file");
        return 1;
    }else {
        int i = countLine();
        while (-1) {
            int charCount = 0, wordCount = 0;
            printf("Enter string, or \"exit\" to end program:\n");
            fgets(str, 510, stdin);
            str[strlen(str) - 1] = '\0';    //because the user press enter so '\n' enter to the input string in the last index, so we put '\0'
            if (strcmp(str, "exit") == 0) break;
            else if (strcmp(str, "history") == 0) {
                fclose(writeFile);//close the file to save every input before "history" to the file, to can read it in the history function
                history();
                writeFile = fopen("history.txt", "a");//open the file again to continue to append new input in it
            } else {
                const char *word = count(str, &charCount, &wordCount);
                if (wordCount != 0) {
                    if (wordCount == 1 && strcmp(word, "exit") == 0) // if their only one word, so I have to check if it "exit" or "history"
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
}

void history() {
    FILE *readFile;
    readFile = fopen("history.txt", "r");
    if (readFile == NULL) {
        perror("file doesn't exist");
    } else {
        char c = fgetc(readFile);//read character by character and print it to the
        while (c != EOF) {
            printf("%c", c);
            c = fgetc(readFile);
        }
        fclose(readFile);
    }
}

int countLine() {
    //count how many lines in the file
    int counter = 0;
    FILE *readFile;
    readFile = fopen("history.txt", "r");
    if (readFile == NULL) {
        perror("file doesn't exist");
    } else {
        char c = fgetc(readFile);
        while (c != EOF) {
            if (c == '\n') counter++;
            c = fgetc(readFile);

        }
        fclose(readFile);
    }
    return counter;
}

const char* count(char str[], int *charCount, int *wordCount) {
    int i = 0;
    int len = strlen(str);
    char word[7];
    int wordInd = 0;

    while (i < len) {
        if (str[i] != ' ') {//if the char is not ' ' so we have to count iy
            (*charCount)++;
            if ((*wordCount) < 1 && (*charCount) < 8){ // if we are in the first word we enter the first 8 chars to the word to check if it "exit" or "history"
                word[wordInd] = str[i];
                wordInd++;
            }

        } else if ((*charCount) != 0 && str[i + 1] != ' ' && str[i + 1] != '\0')//if the str[i] is ' ' and the next element isn't ' ' or '\0' so it's an legal char for a new word
            (*wordCount)++;
        i++;
    }
    if ((*charCount) > 0)//because we count the splits so the number of splits is more than 0, so there is (1+splits) words
        (*wordCount)++;
    word[wordInd]='\0';// to finish the string if it less than 7 chars like "exit"
    if(strcmp(word,"exit")==0)// if the first word in the input is "exit" return  "exit"
        return "exit";
    if(strcmp(word,"history")==0)// if the first word in the input is "history" return  "history"
        return "history";
//else return ""
    return "";
}