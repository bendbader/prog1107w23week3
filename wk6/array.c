#include <stdio.h>
#include "helpers.h"
#include <stdbool.h>

int main()
{
    string name = get_string("What is your name?");

    printf("The second letter of your name is %c\n", name[1]);

    printf("The first letter of your name as an int is %i\n", name[0]);

    //Example of explicit casting
    int letterInt = (int)name[0]; 
    printf("The first letter of your name as a cast int is %i\n", letterInt);

    //The ASCII range for an upper case char is 65-90
    //The ASCII range for a lower case char is 97-122

    char str[]= "hello world";

    //How to figure out the size of data type array.
    int strLen = sizeof(str)/sizeof(str[0]);

    printf("The size of the \"hello world\" is %i elements.\n", strLen);

    //Iterating over every element of char array and printing the null char
    for (int i = 0; i< strLen;i++){
        if(str[i]== '\0'){
            printf("\\0\n");
        }else{
            printf("%c\n", str[i]);
        }
    }

    int i = 0;

    //Will print a string of any length until the null char
    while(str[i] != '\0'){
            printf("%c\n", str[i]);
            i++;
    }

    char the_letter_z = 'z';

    the_letter_z = the_letter_z +2;

    printf("The letter z incremented by 1 is %c\n", the_letter_z);


    return 0;
}