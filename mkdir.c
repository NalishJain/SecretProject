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
        for(int i = 2; i < argc; i++){
                if(argv[i] != " "){
                DIR* dir = opendir(argv[i]);
                if(dir){
                    printf("mkdir : cannot create directory %s , directory already exists\n", argv[i]);
                }
                else{
                    int r = mkdir(argv[i], 0755);
                    if(r != 0){
                        printf("Cannot create directory %s \n", argv[i]);
                    }
                    else{
                        printf("mkdir : created directory %s \n", argv[i]);
                    }
                }
                }
        }     
    }
    else if(strcmp(argv[1], "-p") == 0){
        for(int i = 2; i < argc; i++){
            if(argv[i] != " "){
            char copy[strlen(argv[i]) + 1];
            for(int j = 0; argv[i][j] != '\0'; j++){
                copy[j] = argv[i][j];
                if(argv[i][j] == '/'){
                    copy[j+1] = '\0';
                    DIR* dir = opendir(copy);
                    if(dir){
                    }
                    else{
                        int r = mkdir(copy, 0755);
                        if(r != 0){
                        printf("Cannot create directory %s \n", argv[i]);
                        }
                    }
                }
            }
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
    else if(argv[1][0] == '-'){
        printf("Invalid command \n");
    }
    else{
        for(int i = 1; i < argc; i++){
            if(argv[i] != " "){
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

}