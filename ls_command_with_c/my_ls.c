#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "headers.h"
#include <string.h>
// make output output in lexicographical order(a-z)
//-a include dir names that start with a (.)dot
//-t Sort by time modified (most recently modified first)
//^^ -t will be sorted by date modified first then lexicographical order
// makefile command will be my_ls -a or my_ls -t or my_ls or my_ls -a -t
/*
1.files get printed out including hidden in createlist function
2.ls and ls -a work as intended but are called in the main, 
3. can i call my -a option inside createlist function? 
4. can i call my createlist function inside main as well, printing is done according to parameters of project?
5. how does displaying files by time edited mesh into the flow of program?
*/

void my_strncpy(char *destination, char *source, int length)
{
    int i = 0;
    while (source[i] != '\0' && i < length)
    {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

int my_strcmp(char *str1, char *str2)
{
    while(*str1 && *str2 && *str1 == *str2)
    {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

int my_strlen(char *string)
{
    int length = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        length++;
    }
    // printf("str len: %i\n",length);
    return length;
}

void a_option(DIR *dir)
{
    struct dirent *entry;
    printf("-a option has been entered\n");
    while((entry = readdir(dir)))
    {
        printf("%s ", entry->d_name);
    }
}

void create_list(DIR *dir, int count_files)
{
    printf("entered create_list function\n");
    struct dirent *entry;  // pointer to all of the struct, pointer to all information in directory, RETURNS address of file struct
    char **filenames = malloc(count_files * sizeof(char *));

    int index = 0;
    while ((entry = readdir(dir)) && index < count_files)
    {
        // printf("while loop index %i\n", index);
        filenames[index] = malloc(my_strlen(entry->d_name) + 1);
        my_strncpy(filenames[index], entry->d_name,my_strlen(entry->d_name) + 1);
        index++;
    }
    
    // for(int i = 0; i < index; i++)
    // {
    //     printf("%s ", filenames[i]);
    // }
    // printf("\n");
    // printf("before free loop\n");
    for (int index = 0; index < count_files; index++)
    {
        // printf("entered free loop\n");
        free(filenames[index]);
    }
    // printf("after free loop\n");
    free(filenames);
    printf("end createlist function\n");
}

int main(int argc, char **argv)
{
    // opens current working dir
    DIR *dir = opendir(".");
    // structure holding data from directory stream
    struct dirent *entry_point;
    int file_count = 0;

    // if my directory is empty print error and return with error
    if (dir == NULL)
    {
        printf("cannot open directory\n");
        return 1;
    }

    if (argc > 1)
    {
        if (strcmp(argv[1], "-t") == 0)
        {
            printf("-t option has been entered\n");
        }
        if (strcmp(argv[1], "-a") == 0)
        {
            a_option(dir);
        }
    }

    // while my entry point to the current direcorty is not null print each file in directory
    while ((entry_point = readdir(dir)) != NULL)
    {
        if(entry_point->d_name[0] != '.')
        {
            printf("%s ", entry_point->d_name);
        }
        file_count += 1;
    }
    puts("\n");
    printf("file count in main: %i\n", file_count);
    closedir(dir);

    dir = opendir(".");
    create_list(dir, file_count);
    closedir(dir);

    return 0;
}