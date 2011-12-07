#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h> 
#include <unistd.h>
#include <string.h>
#include "du.h"

void callStat(char * name);

int
main(int argc, char ** argv){
    DIR *dirPtr;
    if(argc < 2){
	perror("You must provide a directory!");
    }else{
	callStat(argv[1]);
	dirPtr = opendir (argv[1]);
	while ((entryPtr = readdir (dirPtr))){
	    callStat(entryPtr->d_name);
	}
	printf("%lu\n", size);
	closedir (dirPtr); 
    }

return 1;
}
void callStat(char * name){    
    char help [512] = "./";
    unsigned long subsize;
    DIR * subdir;
    struct stat statBuf;
    struct dirent *entPtr;
    stat(name, &statBuf);
    if(S_ISDIR(statBuf.st_mode)){
	if(!strcmp(name, ".") ==0 && !strcmp(name, "..") ==0){
	    subsize = 0;
	    subdir = opendir(name);
	    subopen = 1;
	    chdir(name);
	    while ((entPtr = readdir(subdir))){
		strcat(help, entPtr->d_name);
		callStat(help);
	    }
	}
	if(!strcmp(name, ".") ==0 && !strcmp(name, "..") ==0){
	    if(subopen == 1){
		printf("%lu\t./%s\n", subsize,name);
	    }else{
		printf("%lu\t.%s\n", subsize,name);
	    }
	}
    }else{
	size +=statBuf.st_size;
    }
}
