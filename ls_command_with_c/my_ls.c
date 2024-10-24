
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "headers.h"
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <time.h>
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
    while (*str1 && *str2 && *str1 == *str2)
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
    return length;
}

void sort_function(int file_count, int tflag, char **filenames,time_t *modified_array) 
{
    int i, j;
    char *temp;
    time_t temp_modified;
    int swap;
    for (i = 0; i < file_count; i++)
    {
        for (j = i + 1; j < file_count; j++)
        {
            swap = 0;
            if (tflag)
            {
                if(modified_array[i] < modified_array[j])
                {
                    swap = 1;
                }
            }
            else
            {
                if (my_strcmp(filenames[i], filenames[j]) > 0)
                {
                    swap = 1;
                }
            }

            if (swap)
            {
                temp = filenames[i];
                filenames[i] = filenames[j];
                filenames[j] = temp;

                if(tflag)
                {
                    temp_modified = modified_array[i];
                    modified_array[i] = modified_array[j];
                    modified_array[j] = temp_modified;
                }
            }
        }
    }
}

int count_files(DIR *dir)
{
    struct dirent *ptr;
    int count = 0;
    while ((ptr = readdir(dir)))
    {
        count += 1;
    }
    return count;
}

void printarray(int aflag, char **filenames, int num_of_files)
{
    int index;
    for(index = 0; index < num_of_files; index++)
    {   
        if(aflag)
        {
            printf("%s\n", filenames[index]);
        }
        else 
        {
            if(filenames[index][0] != '.')
            {
                printf("%s\n",filenames[index]);
            }
        }
    }
}

void print_files(DIR *dir, bool a_flag, bool t_flag, int num_of_files)
{
    struct dirent *entry;
    struct stat file_stat;
    int file_count = num_of_files;
    char **filenames = malloc(sizeof(char *) * file_count);
    time_t *modified_array = malloc(sizeof(time_t) * file_count);
    if (filenames == NULL)
    {
        printf("malloc has failed\n");
    }

    int index = 0;
    while ((entry = readdir(dir)) != NULL)
    {
        stat(entry->d_name, &file_stat);
        time_t modified = file_stat.st_mtim.tv_sec;
        filenames[index] = malloc(sizeof(char) * my_strlen(entry->d_name) + 1);
        my_strncpy(filenames[index], entry->d_name, my_strlen(entry->d_name) + 1);

        modified_array[index] = modified;

        index++;
    }
    
    if (a_flag && t_flag)
    {
        sort_function(index, 1, filenames, modified_array);
        printarray(1, filenames, num_of_files);
    }
    else if(a_flag)
    {
        sort_function(index, 0, filenames, modified_array);
        printarray(1, filenames, num_of_files);
    }
    else if (t_flag)
    {   
        sort_function(index, 1, filenames, modified_array);
        printarray(0, filenames, num_of_files);
    }
    else
    {
        sort_function(index, 0, filenames, modified_array);
        printarray(0, filenames, num_of_files);
    } 

    for (int i = 0; i < index; i++)
    {
        free(filenames[i]);
    }
    free(filenames);
    free(modified_array);
}

int main(int argc, char **argv)
{
    bool a_flag = false;
    bool t_flag = false;

    int count = 1;
    if(argc > 2)
    {
        if (strcmp(argv[1], "-t") == 0 && strcmp(argv[2], "-a") == 0)
        {
            count = 3;
            t_flag = true;
            a_flag = true;
        }
        if (strcmp(argv[1], "-a") == 0 && strcmp(argv[2], "-t") == 0)
        {
            count = 3;
            a_flag = true;
            t_flag = true;
        }
        else if (strcmp(argv[1], "-a") == 0)
        {
            count = 2;
            a_flag = true;
        }
        else if (strcmp(argv[1], "-t") == 0)
        {
            count = 2;
            t_flag = true;
        }
    }
    else if (argc > 1)
    {
        if (strcmp(argv[1], "-t") == 0)
        {
            count = 2;
            t_flag = true;
        }
        if (strcmp(argv[1], "-a") == 0)
        {
            count = 2;
            a_flag = true;
        }
        if (strcmp(argv[1], "-at") == 0 || strcmp(argv[1], "-ta") == 0)
        {
            count = 2;
            a_flag = true;
            t_flag = true;
        }
    }

    DIR *dir = NULL;
    int num_of_files = 0;
    if (count == argc)
    {
        dir = opendir(".");
        num_of_files = count_files(dir);
        closedir(dir);

        dir = opendir(".");
        print_files(dir, a_flag, t_flag, num_of_files);
        closedir(dir);
    }
    else
    {
        for(int index = count; index < argc; index++)
        {
            dir = opendir(argv[index]);
            if(dir != NULL)
            {
                num_of_files = count_files(dir);
                closedir(dir);

                dir = opendir(argv[index]);
                print_files(dir, a_flag, t_flag, num_of_files);
                closedir(dir);
            }
        }
    }
   
    return 0;
}