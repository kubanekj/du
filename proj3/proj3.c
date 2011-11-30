#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h> 
#include "du.h"

void callStat(char * name);

int
main(int argc, char ** argv){
    DIR *dirPtr;

    if(argc < 2){
	perror("You must provide a directory!");
    }else{
	//do stuff
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
    stat(name, &statBuf);
    if(S_ISDIR(statBuf.st_mode)){
	printf("%s\n", name);
    }else{
	size +=statBuf.st_size;
	printf("%d\t%s\n", statBuf.st_size, name);
    }
}
