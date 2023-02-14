#include <stdio.h>
#include <string.h>

int main () {

    char key[] = {'k', 'e', 'y'};

    char mess[] = {'b', 'e', 'n', 'b', 'a', 'd'};

    int keyLen = strlen(key);
    int messLen = strlen(mess);

    printf("%s", key);

    for(int i = 0; i < messLen; i++){


        key[i + keyLen] = key[i];

        printf("%c\n", key[i]);
    }
    

    return 0;
}