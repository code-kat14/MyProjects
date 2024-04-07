#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h>
//#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <fcntl.h>
#include "headers.h"

#define MIN_VALUE 0
#define MAX_VALUE 9 
#define DEFAULT_SIZE 4

//checking that input is a valid number
bool check_input(int digit[])
{     
    int i = 0;
    while (i < DEFAULT_SIZE)
    {
        if(digit[i] < MIN_VALUE || digit[i] > MAX_VALUE) //or if userguess != min value or max value? 
        {
            return false;
        }
      
        i++;
    }
    return true;
}

//generates a random 4 digit code one by one with unique digits
void generate_code(int secret_code[], int size) //46 output tests, no repeats
{
    srand(time(NULL));
    bool unique;

    int i = 0;
    while(i < size)
    {
        do 
        {
            secret_code[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;

            unique = true;
            for(int j = 0; j < i; j++)
            {
               if(secret_code[i] == secret_code[j]) //if generated digit matches next digit, set unique to false and break out of loop to start generating process 
               {
                   unique = false;
                   break;
               }
            }

        } while (!unique);//while digit is not unique keep doing do statement until each digit is unique

        i++;
    }
}

//takes in user input from stdin
void get_user_input(int user_guess[], int *eof_checker) 
{
    char digit = 0;
    int i = 0;
    *eof_checker = 0;

    while (read(0, &digit, 1) > 0 && digit != '\n' )
    {
        user_guess[i] = digit - '0';
        i++;
        *eof_checker = 1;
    }
    
    if (*eof_checker == 0) {
        return;
    }

    if(i != DEFAULT_SIZE || !check_input(user_guess)) {

        printf("Wrong input!\n");
    }   
}

//compares guess to secret_code displays pieces in right and wrong place
int calculate_user_input(int user_guess[], int secret_code[])
{
    int x  = 0;//keep track of correct numbers
    int y = 0; //keep track of numbers in array
    int secretcode_index[DEFAULT_SIZE] = {0}; //keeps track of digits matched at each index of secret code
    int userguess_index[DEFAULT_SIZE] = {0};//tracks digits not matched when comparing secetcode and userguess at each index of userguess  

    //for loop to compare userguess[i] to secretcode[i] for x 
    for(int i = 0; i < DEFAULT_SIZE; i++)
    {
        if(user_guess[i] == secret_code[i])
        {
            x += 1;
            secretcode_index[i] = 1;
        }
    }
    //for loop checks for y (incorrect position) by comparing both arrays
    for(int i = 0; i < DEFAULT_SIZE; i++)//represents userguess array
    {
        if(user_guess[i] != secret_code[i])
        {
             for(int j = 0; j < DEFAULT_SIZE; j++)//represents secretcode array 
            {
                if(user_guess[i] == secret_code[j] && secretcode_index[j] == 0)
                {
                    y += 1;
                    userguess_index[i] += 1;
                    secretcode_index[j] += 1;
                    break;
                }
            }
        }   
    }
    //condition statement for checking if all numbers are in correct place
    if(x != 4)
    {
        printf("Well placed pieces: %i\nMisplaced pieces: %i\n", x, y);     
    } 
    
    return x;
}


int main(int ac, char **argv)
{
    printf("Will you find the secret code?\nPlease enter a valid guess\n");

    int round = 0;
    int attempts = 10; 
    bool game_over = false;
    int user_guess[DEFAULT_SIZE]; 
    int secret_code[DEFAULT_SIZE];
    int calculated_correct_guess;
    bool custom_code = false;

    //setting custom number of attempts
    for(int i = 1; i < ac; i++)
    {
        if(strcmp(argv[i], "-t") == 0)
        {
            attempts = atoi(argv[i + 1]);

        }
    }

    //flags for setting your own seceret code
    for(int i = 1; i < ac; i++) //starting at the second argument. 
    {
        if(strcmp(argv[i], "-c") == 0)
        {
            custom_code = true;
            i++;
            for(int j = 0; j < DEFAULT_SIZE && i < ac ; j++)//finds each digit inside string input
            {
                if (i < ac)
                {
                    secret_code[j] = argv[i][j] - '0';
                }
            }
        }
    }

    if(custom_code != true)
    {
        generate_code(secret_code, DEFAULT_SIZE);    
    }

    int eof_checker = 0;
    //game flow
    while(round < attempts && !game_over)
    {
        printf("---\nRound %i\n", round);
        get_user_input(user_guess, &eof_checker);
        
        if (eof_checker == 0) {
            printf("exit");
            return 1;
        }

        calculated_correct_guess = calculate_user_input(user_guess, secret_code);

        if(calculated_correct_guess == 4)
        {
            printf("Congratz! You did it!");
            game_over = true;
            break;
        }      
        round++;
    }
    return 0;
}


