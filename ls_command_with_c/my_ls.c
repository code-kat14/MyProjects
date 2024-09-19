#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "headers.h"
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <time.h>

void print_files(DIR *dir, bool a_flag, bool t_flag)
{
    struct dirent *entry;
    struct stat file_stat;
    while ((entry = readdir(dir)) != NULL)
    {
        stat(entry->d_name, &file_stat);
        time_t modified = file_stat.st_mtim.tv_sec;
        if(a_flag)
        {
            printf("%s\n", entry->d_name);
        }
        else if(t_flag) 
        {
            printf("%s -- %s",entry->d_name, ctime(&modified));
        }
        else if(entry->d_name[0] != '.')
        {
            printf("%s\n", entry->d_name);
        }
        
    }
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
    closedir(dir);

    return 0;
}