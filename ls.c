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
}
