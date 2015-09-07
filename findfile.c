//
//  findfile.c
//  capsh
//
//  Created by samson ugwuodo on 7/24/15.
//  Copyright (c) 2015 mobiletalks. All rights reserved.
//
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/param.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "findfile.h"
#include <malloc_np.h>
#include <stdlib.h>

int find_executable(const char *Path, const char *name)
{
    char NewPath[MAXPATHLEN];
    char *currentdir;
    char* MainPath = strdup(Path);
    currentdir = strsep(&MainPath,":");
    
    while(currentdir != NULL)
        {   //*creating a new path with the current path and the argument passed*//
	    strcpy(NewPath,currentdir);
            strcpy(NewPath+strlen(NewPath), "/");
            strcpy(NewPath+strlen(NewPath),name);
            //* Passing statment condition to check if created path is existing*//
            if(access(NewPath,X_OK)== 0)
            {
                printf("Newpath is: %s\n", NewPath);
                return open(NewPath, O_RDONLY | S_IEXEC);
                
            }else
		{
		currentdir = strsep(&MainPath, ":"); 
		}  
        }
	return 0;   
}
