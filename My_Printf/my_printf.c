#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h> 
#include <unistd.h>

#define max_size 2048
/*reverses int to string back to original order*/
void string_reversed(char *original_str)
{
    char temp;
    char *start = original_str;
    char *end = start + strlen(original_str) - 1;
    
    while(end > start)
    {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }    
}

/*converts integer arg to string*/
void int_to_string(int num, int base, char* string)
{
    int i = 0;
    int temp_num = num;
 
    if(num < 0)
    {
        num *= -1;
    }

    while(num != 0 || i == 0)
    {
        int remainder = num % base;
        if(remainder > 9)
        {
            string[i] = (remainder - 10) + 'a';
            //printf("greater than base 10 string[%i]\n",i);
        } 
        else
        {
            string[i] = remainder + '0';
            //printf("base 10 string[%i]\n",i);
        }
        num = num / base;
        i++;
    }

    if(temp_num < 0)
    {
        string[i] = '-';
        i += 1;
    }    
    string[i] = '\0';

    string_reversed(string);
}

/*used to print string to console*/
void my_puts_string(char *s_string)
{
    char output_string[max_size] = {'\0'};

    int i = 0;
    int str_length = strlen(s_string);
   
    while(s_string[i] != '\0')
    {
        output_string[i] = s_string[i];
        i++;   
    }
    output_string[i] =  '\0';

    write(1, output_string, str_length);   
}

void hexadecimal_pointer_address(long num, int base, char *hex_string)
{
    int i = 0;   
    while(num != 0)
    {
        int hex_remainder = num % base;
       
        if(hex_remainder > 9)
        {
            hex_string[i] = (hex_remainder - 10) + 'a';
        }
        else 
        {
            hex_string[i] = hex_remainder + '0';
        }
        num = num / base;
        i++;
    }
    hex_string[i] = '\0';

    string_reversed(hex_string);
}

/*Specifier functions*/
int d_decimal(va_list args)
{   
    char d_string[max_size] = {'\0'};
    int d = va_arg(args, int);

    int_to_string(d, 10, d_string);
    return write(1, &d_string, strlen(d_string));
}

int o_octal(va_list args)
{
    char o_string[max_size] = {'\0'};
    long int o = va_arg(args, long int);

    int_to_string(o, 8, o_string);
    return write(1, &o_string, strlen(o_string));
}

int u_unsigned_decimal(va_list args)
{
    char u_string[max_size] = {'\0'};
    unsigned int u = va_arg(args, unsigned int);

    int_to_string(u, 10, u_string);
    return write(1, &u_string, strlen(u_string));
}

int x_unsigned_hexadecimal(va_list args) 
{
    char unsigned_hex_string[max_size] = {'\0'};
    unsigned long x = va_arg(args, unsigned long);
  
    int_to_string(x, 16, unsigned_hex_string);
    return write(1, &unsigned_hex_string, strlen(unsigned_hex_string));
}

int c_character(va_list args)
{
    int c = va_arg(args, int);
    return write(1,&c,1);
}

int s_string_char_array(va_list args)
{
    char *char_str = va_arg(args, char*);

    if(char_str == NULL)
    {
        char_str = "(null)";
    }

    my_puts_string(char_str);
    return strlen(char_str);
}

int p_pointer_argument(va_list args)
{ 
    void *ptr = va_arg(args, void*);
    char hex_string[max_size] = {'\0'};

    hexadecimal_pointer_address((long)ptr,16, hex_string);
    return write(1,hex_string, strlen(hex_string));
}

/*start my_printf function & main*/
int my_printf(char *restrict format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;
    int i = 0;

    while(format[i] != '\0')
    {
        if(format[i] == '%')
        {
            i++;
            switch(format[i])
            {
                case 'd':
                {
                    count += d_decimal(args);
                }
                break;
                case 'o':
                {
                    count += o_octal(args);
                }
                break;
                case 'u':
                {
                    count += u_unsigned_decimal(args);
                }
                break;
                case 'x':
                {
                    count += x_unsigned_hexadecimal(args);
                }
                break;
                case 'c':
                {
                    count += c_character(args);
                }
                break;
                case 's':
                {
                    count += s_string_char_array(args);
                    
                }
                break;
                case 'p':
                {
                    count += write(1, "0x", 2);
                    count += p_pointer_argument(args);
                }
            }
        }
        else
        {
            write(1, &format[i], 1);
            count++;  
        }
        i++;

    }
    va_end(args);

    return count;
}

int main()
{
    /*int test*/
    my_printf("katie D: %d %d %d\n", 1234, 0, -9874); 
    printf("D: %d %d %d\n\n", 1234, 0, -9874);

    my_printf("katie O: %o %o\n", 9283, 83744);
    printf("O: %o %o\n\n", 9283, 83744);

    my_printf("katie U: %u %u\n", 1526, 63);
    printf("U: %u %u\n\n", 1526, 63);

    my_printf("katie X: %x\n", 14);
    printf("X: %x\n\n", 14);
    
    /*string & char test*/
    my_printf("test 00 - katie NULL STRING %s!\n\n", (char *)NULL);

    int my_test_01 = my_printf("%c%c%c%c%c\n", 'H', 'e', 'l', 'l', 'o'); 
    printf("amount of characters printed: %d\n\n", my_test_01);

    int test_01 = my_printf("Hello %s!\n", "QWASAR.IO");
    printf("test 01 - Amount of characters printed is %d\n\n", test_01);

    int test_02 = my_printf("123%s\n", "456789");
    printf("Amount of chars printed %d\n\n",test_02);

    int test_warren = my_printf("abc%s\n", "def");
    printf("amount of chars printed [%d]\n\n", test_warren);

    /*pointer test*/
    int variable = 12;
    char test_string[6] = "hello";

    my_printf("katie P: %p\n", &variable);
    printf("P: %p!\n\n", &variable);

    my_printf("katie P: %p\n", &test_string);
    printf("P: %p!\n\n", &test_string);

return 0;
}