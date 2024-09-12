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

void sort_function(int file_count, struct dirent **entry)//sort my dir , modify my dir values, 
{
    int i, j;
   
    struct dirent *temp;
    for(i = 0; i < file_count; i++) //i = string1
    {
        for(j = i + 1; j < file_count; j++) //j = string2
        {
           
            if(strcmp(entry[i]->d_name, entry[j]->d_name) > 0)
            {
                printf("inside if statement\n");
                temp = entry[i];
                entry[i] = entry[j];
                entry[j] = temp;
                printf("end of if statement\n");
            }
        }
    }
    printf("number of files %i\n",file_count);
    for(int index = 0; index < file_count; index++)
    {
        printf("%s\n", entry[index]->d_name);
    }
    //free(temp);
}

void print_files(DIR *dir, bool a_flag, bool t_flag)
{
    struct dirent *entry;
    struct stat file_stat;
    int count = 0;
    while ((entry = readdir(dir)) != NULL)
    {
        count+=1;
        stat(entry->d_name, &file_stat);
        time_t modified = file_stat.st_mtim.tv_sec;
        if(a_flag)
        {
            printf("%s\n", entry->d_name);
        }
        else if(t_flag) 
        {
            printf("%s %s\n",entry->d_name, ctime(&modified));
        }
        else if(entry->d_name[0] != '.')
        {
            printf("%s\n", entry->d_name);
        }
    }
    printf("count %i\n", count);
    sort_function(count, &entry);
}

int main(int argc, char **argv)
{
    DIR *dir = opendir(".");
    bool a_flag = false;
    bool t_flag = false;
  
    if (dir == NULL)
    {
        printf("cannot open directory\n");
        return 1;
    }

    if (argc > 1)
    {
        if (strcmp(argv[1], "-t") == 0)
        {
           t_flag = true;
        }
        if (strcmp(argv[1], "-a") == 0)
        {
            a_flag = true;
        }
    }
    print_files(dir,a_flag, t_flag);
    //printf("file count in main: %i\n", file_count);
    closedir(dir);

    return 0;
}
