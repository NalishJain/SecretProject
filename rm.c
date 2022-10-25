#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<limits.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include <dirent.h>

int checkDirectory(const char* dName){
    struct stat p;
    stat(dName, &p);
    return S_ISREG(p.st_mode);
}


int main(int argc, char *argv[]){
    if(strcmp(argv[1], "-i") == 0){
        for(int i = 2; i < argc; i++){
            if(argv[i] != " "){
            int checker  = checkDirectory(argv[i]);
            if(checker == 0){
                DIR* dir = opendir(argv[i]);
                if(dir){
                    printf("rm : cannot remove %s ,is a directory\n", argv[i]);
                    closedir(dir);
                }
                else{
                    printf("rm : cannot remove %s , no such file or directory\n", argv[i]);
                }
            }
            else{
                FILE *fptr = fopen(argv[i], "r");
                if(fptr == NULL){
                    printf("rm : cannot remove %s , no such file or directory\n", argv[i]);
                }
                else{
                    printf("rm: remove regular file %s ?(y/n)", argv[i]);
                    char answer;
                    scanf("%c", &answer);
                    if(answer == 'y'){
                        remove(argv[i]);
                    }  
                }
            }
            }

        }


    }
    else if(strcmp(argv[1], "-r") == 0){
        for(int i = 2; i < argc; i++){
            if(argv[i] != " "){
            int checker  = checkDirectory(argv[i]);
            if(checker == 0){
                DIR* dir = opendir(argv[i]);
                if(dir){
                    rmdir(argv[i]);
                }
                else{
                    printf("rm : cannot remove %s , no such file or directory\n", argv[i]);
                }
            }
            else{
                FILE *fptr = fopen(argv[i], "r");
                if(fptr == NULL){
                    printf("rm : cannot remove %s , no such file or directory\n", argv[i]);
                }
                else{
                    remove(argv[i]);
                }          
            }
            }
        }


    }

    else if(argv[1][0] != '-'){
        printf("Invalid command\n");
    }
    else{
        for(int i = 1; i < argc; i++){
            if(argv[i] != " "){
            FILE *fptr = fopen(argv[i], "r");
            int checker  = checkDirectory(argv[i]);

            if(checker == 0){
                DIR* dir = opendir(argv[i]);
                if(dir){
                    printf("rm : cannot remove %s ,is a directory\n", argv[i]);
                    closedir(dir);
                }
                else{
                    printf("rm : cannot remove %s , no such file or directory\n", argv[i]);
                }
            }
            else{
                FILE *fptr = fopen(argv[i], "r");
                if(fptr == NULL){
                    printf("rm : cannot remove %s , no such file or directory\n", argv[i]);
                }
                else{
                    remove(argv[i]);
                }
            }
            }

        }

    }
}