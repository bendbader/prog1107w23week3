#include <stdio.h>
#include "helpers.h"

int main() {

    // char array[] = {};

    string name = get_string("What is your name?\t");


    for(int i = 0; i < 10; i++)
    {
        printf("%c", name[i]);
    }

    return 0;

}
