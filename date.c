#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<limits.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include <dirent.h>
#include<time.h>

int main(int argc, char *argv[]){
    printf("%d\n", argc)
    if(strcmp(argv[1], "-v") == 0){

    }

    else if(strcmp(argv[1], "-v") == 0){

    }

    else{
        
        time_t T;
        time(&T);
        printf("%s\n", ctime(&T));

        
    }
    

}