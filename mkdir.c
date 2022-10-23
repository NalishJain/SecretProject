#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<limits.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include <dirent.h>

int main(int argc, char *argv[]){
    if(strcmp(argv[1], "-v") == 0){
        
    }
    else if(strcmp(argv[1], "-p") == 0){

    }
    else{
        for(int i = 0; i < argc - 1; i++){
                DIR* dir = opendir(argv[i]);
                if(dir){
                    printf("mkdir : cannot create directory %s , directory already exists\n", argv[i]);
                }
                else{
                    int r = mkdir(argv[i], 0755);
                    if(r != 0){
                        printf("Cannot create directory %s \n", argv[i]);
                    }
                }
        }

    }

}