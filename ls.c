#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<limits.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, const char *argv[]){
    if(argc == 1){
       struct dirent *e1;
       DIR *directory = opendir(".");
       while((e1 = readdir(directory)) != NULL){
        if(e1->d_name[0] == '.'){
            continue;
        }
        printf("%s ", e1->d_name);
       } 
       printf("\n");     
    }

    if(argc == 2){
        if(strcmp(argv[1], "-1") == 0){
            struct dirent *e1;
            DIR *directory = opendir(".");
            while((e1 = readdir(directory)) != NULL){
                if(e1->d_name[0] == '.'){
                continue;
                }
                printf("%s ", e1->d_name);
                printf("\n");
            } 
        }

        else if(strcmp(argv[1], "-a") == 0){
            struct dirent *e1;
            DIR *directory = opendir(".");
            while((e1 = readdir(directory)) != NULL){
            printf("%s ", e1->d_name);
            } 
            printf("\n");            
        }

        else if(!argv[1]){
            printf("Invalid command \n")
        }      
    }
    if(argc == 2){
       struct dirent *e1;
       DIR *directory = opendir(".");
       while((e1 = readdir(directory)) != NULL){
        if(e1->d_name[0] == '.'){
            continue;
        }
        printf("%s ", e1->d_name);
       } 
       printf("\n");
    }
    else if(argc == 3){

        if(strcmp(argv[1], "-1") == 0){
            struct dirent *e1;
            DIR *directory = opendir(".");
            while((e1 = readdir(directory)) != NULL){
                if(e1->d_name[0] == '.'){
                continue;
                }
                printf("%s ", e1->d_name);
                printf("\n");
            } 
        }

        else if(strcmp(argv[1], "-a") == 0){
            struct dirent *e1;
            DIR *directory = opendir(".");
            while((e1 = readdir(directory)) != NULL){
            printf("%s ", e1->d_name);
            } 
            printf("\n");            
        }

        else{
            printf("Invalid command\n");
        }

    }
    else{
        printf("Invalid command\n");
    }
}
