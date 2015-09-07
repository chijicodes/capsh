//
//  main.c
//  capsh
//
//  Created by samson ugwuodo on 6/22/15.
//  Copyright (c) 2015 mobiletalks. All rights reserved.
//

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/param.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "findfile.h"
#include <sys/capability.h>

extern char **environ;

int main(int argc, char *argv[])
{
    char *fullPath;
    fullPath = getenv("PATH");
    int i= 0, fd;
    
    if(argc < 2){
        printf("no argument passed \n");
        return 1;
    }
     //*Passing argument to parameters of function find_executable and returning the              	value of the executable file as to file discriptor*//
        fd = find_executable(fullPath, argv[1]);
	if (fd < 0)
	err(-1, "failed to find %s in %s", argv[1], fullPath);
	printf("Executing FD: %d\n", fd);
	cap_enter();//*Enabling Capsicum capability mode*// 
        fexecve(fd, argv + 1, environ);
	err(-1, "fexecve() failed");

}
