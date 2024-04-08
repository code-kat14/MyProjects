#include <cstdarg>
#ifndef headers_h
#define headers_h

//#include <cstdarg>


void int_to_string(int num, char *string, int base);
void string_reversed(char *original_str);
int my_printf(char *format, ...);
void d_decimal(va_list args);
void o_octal(va_list args);
void u_unsigned_decimal(va_list args);
void x_unsigned_hexadecimal(va_list args);
void c_character(va_list args);
void my_put_char(int int_arg);
void my_puts_string(char *string);
void s_string_char_array();
void *p_pointer_argument();

int main();


#endif