#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h> 

void callStat(char * name);

int
main(int argc, char ** argv){
    DIR *dirPtr;
    struct dirent *entryPtr;
    struct stat statBuf;

    if(argc < 2){
	perror("You must provide a directory!");
    }else{
	//do stuff
	dirPtr = opendir (argv[1]);
	while ((entryPtr = readdir (dirPtr))){
	    if (stat (entryPtr->d_name, &statBuf) < 0) {
		perror ("huh?  there is ");
		//exit(1);
	    }
	    callStat(entryPtr->d_name);
	}
	closedir (dirPtr); 
    }

return 1;
}
void callStat(char * name){

}
