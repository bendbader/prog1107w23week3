#include <stdio.h>
#include "helpers.h"

int main (int argc, char *argv[]) {

    if( argc == 2 ) {

        printf("\nHello, %s, welcome to the Cipher-Matic 3000!\n\n", argv[1]);

        // string name = get_string("Please enter your username:\t");

        // printf("\nHello, %s, welcome to the Cipher-Matic 3000!\n\n", name);

        char isRunning = 'y';

        while(isRunning != 'n' && isRunning != 'N') {
        
            int ende = get_int("What would you like to do?\n\n1. Encode\n2. Decode\n\nPlease enter 1 or 2:\t");

            switch(ende) {

                case 1: // Encode a message

                    printf("\nPlease choose the method of encryption:\n\n");
                    printf("1. Caesar\n2. Vigenère\n3. Salted Caesar\n\n");

                    int ciph = get_int("Please enter 1, 2, or 3:\t");

                    string mess = get_string("\n\nPlease enter the message you wish to encode:\t");

                    switch(ciph){

                        case 1: ; // Caesar

                            char LorR = get_char("\n\nPlease enter the direction to shift the message (L/R):\t");
                            int shift = get_int("\n\nPlease enter the number of positions you wish to offset your message:\t");

                            int messLength = strlen(mess);

                            // Turn all characters into uppercase

                            for(int j = 0; j < messLength; j++) {

                                if(mess[j] > 90) {

                                    mess[j] -= 32;

                                }

                            // If message shifts left

                            }
                            
                            if(LorR == 'l' || LorR == 'L') {

                                for(int i = 0; i < messLength; i++) {

                                    if(mess[i] != 32) {
                                        
                                        mess[i] -= shift;  

                                        if(mess[i] < 65) {

                                            mess[i] += 26;
                                        }

                                    }

                                }

                            // If message shifts right

                            } else if(LorR == 'r' || LorR == 'R') {

                                for(int i = 0; i < messLength; i++) {

                                    if(mess[i] != 32){
                                    
                                        mess[i] += shift;  

                                        if(mess[i] > 90) {

                                            mess[i] -= 26;
                                        }

                                    }

                                }

                            }

                            printf("\n\nYour encoded message is:\t%s\n\n", mess);

                            break;

                        case 2: ; // Vigenère

                            string keyV = get_string("\n\nPlease enter the encryption key you wish to use:\t");

                            messLength = strlen(mess);
                            int keyLength = strlen(keyV);

                            // Turn lowercase into uppercase

                            for(int j = 0; j < messLength; j++) {

                                if(mess[j] > 90) {

                                    mess[j] -= 32;

                                }

                                if(keyV[j] > 90) {

                                    keyV[j] -= 32;

                                }
                            
                            }

                            // Match keyLength with messLength using repeated key letters

                            if(keyLength < messLength) {

                                for(int k = 0; k < (messLength - keyLength); k++){

                                        keyV[k + keyLength] = keyV[k];
                                    
                                }

                            }

                            for(int v = 0; v < messLength; v++){

                                mess[v] = (mess[v] + keyV[v]) % 26;
                                mess[v] += 65;

                            }

                            printf("\n\nYour encoded message is:\t%s\n\n", mess);

                            break;

                        case 3: ; // Salted Caesar

                            LorR = get_char("\n\nPlease enter the direction to shift the message (L/R):\t");
                            shift = get_int("\n\nPlease enter the number of positions you wish to offset your message:\t");

                            messLength = strlen(mess);
                            keyV = argv[1];

                            // Turn all characters into uppercase

                            for(int j = 0; j < messLength; j++) {

                                if(mess[j] > 90) {

                                    mess[j] -= 32;

                                }

                                if(keyV[j] > 90) {

                                    keyV[j] -= 32;

                                }

                            // If message shifts left

                            }
                            
                            if(LorR == 'l' || LorR == 'L') {

                                for(int i = 0; i < messLength; i++) {

                                    mess[i] -= shift;  

                                    if(mess[i] < 65) {

                                        mess[i] += 26;
                                    }

                                }

                            // If message shifts right

                            } else if(LorR == 'r' || LorR == 'R') {

                                for(int i = 0; i < messLength; i++) {

                                    mess[i] += shift;  

                                    if(mess[i] > 90) {

                                        mess[i] -= 26;
                                    }

                                }

                            }

                            // Match keyLength with messLength using repeated key letters

                            keyLength = strlen(keyV);

                            if(keyLength < messLength) {

                                for(int k = 0; k < (messLength - keyLength); k++){

                                        keyV[k + keyLength] = keyV[k];
                                    
                                }

                            }

                            for(int v = 0; v < messLength; v++){

                                mess[v] = (mess[v] + keyV[v]) % 26;
                                mess[v] += 65;

                            }

                            printf("\n\nYour encoded message is:\t%s\n\n", mess);

                    }

                    break;

                    case 2: ;

                        printf("\nPlease choose the method of decryption:\n\n");
                        printf("1. Caesar\n2. Vigenère\n3. Salted Caesar\n\n");

                        ciph = get_int("Please enter 1, 2, or 3:\t");

                        mess = get_string("\n\nPlease enter the message you wish to decode:\t");

                        switch (ciph) {

                            case 1: ; // Caesar

                                char LorR = get_char("\n\nPlease enter the direction the message was shifted (L/R):\t");
                                int shift = get_int("\n\nPlease enter the number of positions the message was offset:\t");

                                int messLength = strlen(mess);

                                // Turn all characters into uppercase

                                for(int j = 0; j < messLength; j++) {

                                    if(mess[j] > 90) {

                                        mess[j] -= 32;

                                    }

                                // If message was shifted left

                                }
                                
                                if(LorR == 'l' || LorR == 'L') {

                                    for(int i = 0; i < messLength; i++) {

                                        if(mess[i] != 32) {

                                            mess[i] += shift;  
                                            
                                            if(mess[i] > 90) {

                                                mess[i] -= 26;
                                            }

                                        }

                                    }

                                // If message was shifted right

                                } else if(LorR == 'r' || LorR == 'R') {

                                    for(int i = 0; i < messLength; i++) {

                                        if(mess[i] != 32) {
                                            
                                            mess[i] -= shift;
                                        
                                            if(mess[i] < 65) {

                                                mess[i] += 26;
                                            }

                                        }

                                    }

                                }

                                printf("\n\nThe decoded message reads:\t%s\n\n", mess);

                                break;

                            case 2: ;

                                string keyV = get_string("\n\nPlease enter the encryption key for this message:\t");

                                messLength = strlen(mess);
                                int keyLength = strlen(keyV);

                                // Turn lowercase into uppercase

                                for(int j = 0; j < messLength; j++) {

                                    if(mess[j] > 90) {

                                        mess[j] -= 32;

                                    }

                                    if(keyV[j] > 90) {

                                        keyV[j] -= 32;

                                    }

                                }

                                // Match keyLength with messLength using repeated key letters

                                if(keyLength < messLength) {

                                    for(int k = 0; k < (messLength - keyLength); k++){

                                        keyV[k + keyLength] = keyV[k];
                                    
                                    }

                                }

                                // Convert encoded message to original text with key

                                for(int v = 0; v < messLength; v++){

                                    mess[v] = (mess[v] - keyV[v]) % 26;

                                    if(mess[v] < 0) {

                                        mess[v] += 26;

                                    }

                                    mess[v] += 65;

                                }

                                printf("\n\nYour decoded message is:\t%s\n\n", mess);

                                break;

                            case 3: ; // Salted Caesar

                                string uName = get_string("\n\nPlease enter the username of the sender:\t");
                                LorR = get_char("\n\nPlease enter the direction the message was shifted (L/R):\t");
                                shift = get_int("\n\nPlease enter the number of positions the message was offset:\t");

                                messLength = strlen(mess);
                                int uNameLength = strlen(uName);

                                // Turn all characters into uppercase

                                for(int j = 0; j < messLength; j++) {

                                    if(mess[j] > 90) {

                                        mess[j] -= 32;

                                    }

                                    if(uName[j] > 90) {

                                        uName[j] -= 32;

                                    }

                                }

                                // Match keyLength with messLength using repeated key letters

                                if(uNameLength < messLength) {

                                    for(int k = 0; k < (messLength - uNameLength); k++){

                                        uName[k + uNameLength] = uName[k];
                                    
                                    }

                                }

                                // Convert encoded message to original text with key

                                for(int v = 0; v < messLength; v++){

                                    mess[v] = (mess[v] - uName[v]) % 26;

                                    if(mess[v] < shift) {

                                        mess[v] += 26;

                                    }

                                    mess[v] += 65;

                                }

                                if(LorR == 'l' || LorR == 'L') {     // If message was shifted left

                                    for(int i = 0; i < messLength; i++) {

                                        mess[i] += shift;  
                                        
                                        if(mess[i] < 65) {

                                            mess[i] += 26;

                                        }else if(mess[i] > 90) {

                                            mess[i] -= 26;
                                        }

                                    }

                                } else if(LorR == 'r' || LorR == 'R') {     // If message was shifted right

                                    for(int i = 0; i < messLength; i++) {

                                        mess[i] -= shift;

                                        if(mess[i] < 65) {

                                            mess[i] += 26;
                                            
                                        }else if(mess[i] > 90) {

                                            mess[i] -= 26;
                                        }

                                    }

                                }

                                printf("\n\nThe decoded message reads:\t%s\n\n", mess);
                                 
                        }

                    break;

                    }

                    isRunning = get_char("\nWould you like to encode/decode another message? (y/n):\t");

                }

            printf("\n\nThank you for encryping with the Cipher-Matic 3000.\n\n");
            printf("This message will now self-destruct.\n\n");

    } else if( argc > 2 ) {

      printf("Too many usernames.\n");

    } else {

      printf("Username expected.\n");

    }

    return 0;

}