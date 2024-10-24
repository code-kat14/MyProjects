#ifndef HEADER_H
#define HEADER_H
#include <bits/types/time_t.h>
#include <dirent.h>
void my_strncpy(char *destination, char *source, int length);
int my_strcmp(char *str1, char *str2);
int my_strlen(char *string);
void sort_function(int file_count, int tflag, char **filenames,time_t *modified_array);
int count_files(DIR *dir);
void printarray(int aflag, char **filenames, int num_of_files);
int main(int argc, char **argv);
#endif