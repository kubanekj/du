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
    DIR * subdir;
    struct dirent *entPtr;
    stat(name, &statBuf);
    if(S_ISDIR(statBuf.st_mode)){
	if(!strcmp(name, ".") ==0 && !strcmp(name, "..") ==0){
	    chdir(name);
	    subdir = opendir(name);
	    while ((entPtr = readdir(subdir))){
		callStat(entPtr->d_name);
	    }
	}
	printf("%s\n", name);
    }else{
	size +=statBuf.st_size;
	printf("%d\t%s\n",(int) statBuf.st_size, name);
    }
}
