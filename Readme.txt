String parser
Authored by Laith Al-mouhtaseb
211353297

==Description==
The program start in infinite loop that stopped when the user enter "exit" to the input,
The program get a string input from the user and count how many words and letters in the words
after that save the input string in a text file I named "file.txt",
and if the user entered "history",the program print all the strings that the user have entered it.

functions:
history: its void function with no input args, that open the txt file "file.txt" and print the file to the console.

count: the parameters that require it is  string, pointer of int and another pointer of int, and return a string,
the function edit the value of the two ints that were given to it,it takes ints by reference.
one int to count how many words in the string,
and the second one to count how many letters in the string,
the string that given to the function is the string that the user give in the main.

how it works: define a new string with length of 8 because the longest word that wil return is "history" and the '\0' at the end of it.
it runs throw the string and if the char at index i isn't space " " so it's a legal char so the letter counter++.
if the char at index i is space " " and there's 1 or more legal chars so the word count++ and at the end if the char counter is larger than 1.
add 1 for the word counter, because the word count actually count the splits between words.
at the end the function check if the first word equal "exit" or "history" and return what is if its else return ""
and in main they check if the returned value of count function equal "exit" or "history" and the wordcount equal to 1 so the main do what the word have to do.
and if it equals to "" so that a normal input, and we have to add it to history file.


countLine: function that run throw the file and count how many rows in the history file.

==Program Files==
main.c

==How to compile==
compile: gcc main.c -o main
run: ./main

==input==
string from user

==output==
history.txt file
words count for every input
chars count for every input