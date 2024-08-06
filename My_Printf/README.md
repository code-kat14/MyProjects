# Welcome to My Printf
***
## Description
The my_printf() function will produce output according to a format as described below. The my_printf() functions write output to stdout, the standard output stream.<br>

Each conversion specification is introduced by the PERCENT character. The arguments must correspond properly with the conversion specifier. After the PERCENT, the following appear in sequence:<br>

doux The int (or appropriate variant) argument is converted to signed decimal (d). unsigned octal (o), unsigned decimal (u), unsigned hexadecimal (x).<br>
c The int argument is converted to an unsigned char, and the resulting character is written.<br>
s The char * argument is expected to be a pointer to an array of character type (pointer to a string). Characters from the array are written up to (but not including) a terminating NUL character.<br>
p The void * pointer argument is printed in hexadecimal.<br>

## Installation
1. Make sure you have proper dependacies<br>
    -make<br>
    -gcc compiler<br>

## Usage
If your not using Makefile:<br>
Compile using 
```
gcc my_printf.c -o my_printf
```
<br>
```
-> $ ./my_printf
```
<br>

### The Core Team


<span><i>Made at <a href="https://qwasar.io">Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt="Qwasar SV -- Software Engineering School's Logo" src="https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png" width='20px'></span>