#ifndef headers_h
#define headers_h 
#include <stdbool.h>

bool check_input(int digit[]);
void generate_code(int secret_code[], int size);
void get_user_input(int user_guess[], int *eof_checker);
int calculate_user_input(int user_guess[], int secret_code[]);
int main(int ac, char **argv);

#endif