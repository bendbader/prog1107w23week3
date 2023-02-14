#include <stdio.h>
#include "helpers.h"
#include <stdbool.h>

int main()
{
    //Ask for the client's name
    string name = get_string("Please enter your name.\n");

    printf("Welcome %s!\n", name);

    char isRunning = 'y';

    while(isRunning != 'n' && isRunning != 'N'){
        //How to ask for the amount of money to dispense
        int money = get_int("How much money would withdraw?\n");

        // int hundreds = 0, fifties =0, twenties= 0, tens =0, fives= 0;

        int bills [] = {100, 50, 20, 10, 5};
        int amount_of_bills[5];

        //bool isDispensable;
        // if(money % 5 == 0){
        //     isDispensable = true;
        // } else {
        //     isDispensable = false;
        // }

        bool isDispensable = money % 5 == 0 ? true : false;

        bool isEnough = money >= 5 ? true : false;

        if(isEnough && isDispensable){

            //For 150, money will equal 1

            /*
            amount_of_bills[0] = money / bills[0];

            int remainder= 0;
            remainder = money % bills[0]; 

            amount_of_bills[1] = remainder / bills[1];

            remainder = remainder %  bills[1];

            amount_of_bills[2] = remainder / bills[2];

            remainder = remainder % bills[2];

            amount_of_bills[3] = remainder / bills[3];

            remainder = remainder % bills[3];

            amount_of_bills[4] = remainder / bills[4];

            remainder = remainder % bills[4];
            */
            int array_length = sizeof(bills) / sizeof(bills[4]);

            printf("I will dispense:\n");
        
            for(int i = 0; i < array_length; i++) {

                amount_of_bills[i] = money / bills[i];
                int remainder = money % bills[i];
                money = remainder;
                printf("%dx $%d bill(s)\n", amount_of_bills[i], bills[i]);

           }

            /*
            printf("I will dispense:\n");
            printf("%dx $100 bill(s)\n", amount_of_bills[0]);
            printf("%dx $50 bill(s)\n", amount_of_bills[1]);
            printf("%dx $20 bill(s)\n", amount_of_bills[2]);
            printf("%dx $10 bill(s)\n", amount_of_bills[3]);
            printf("%dx $5 bill(s)\n", amount_of_bills[4]);
            printf("and I will eat your $%d\n", remainder);
            */

        }else{
            if(!isEnough){
            printf("The machine cannot dispense less than $5.\n");
            }

            if(!isDispensable){
            printf("The smallest denomination the machine can dispense is $5.\n");
            }

        }


        isRunning = get_char("Do you want to keep withdrawing?");
    }
   


    //get_string() will help you get a name
    //get_char() is a good way to ask if the machine should keep dispensing.
    
    return 0;
}
