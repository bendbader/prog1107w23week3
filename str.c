#include <stdio.h>
#include <stdbool.h>
#include "helpers.h"

int main () {

    string wrd = get_string("Enter a word:\t");
    int num = get_int("Enter the number to shift by:\t");

    int arrLen = sizeof(wrd) / sizeof(wrd[0]);

    for(int i = 0; i < arrLen; i++) {

        wrd[i] += num;

    }

    printf("%s\n", wrd);

return 0;

}