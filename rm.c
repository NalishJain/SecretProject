#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<limits.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>

int checkDirectory(const char* dName){
    struct stat p;
    stat(dName, &p);
    return S_ISREG(p.st_mode);
}


int main(int argc, char *argv[]){
    if(strcmp(argv[1], "-i") == 0){
        for(int i = 2; i < argc - 1; i++){
            int checker  = checkDirectory(argv[i]);
            if(checker == 0){
                printf("rm : cannot remove %s ,is a directory\n");
            }
            else{
                FILE *fptr = fopen(argv[i], "r");
                if(fptr == NULL){
                    printf("rm : cannot remove %s , no such file or directory\n");
                }
                else{
                    printf("rm: remove regular file %s ?(y/n)");
                    char answer;
                    scanf("%c", &answer);
                    if(answer == 'y'){
                        remove(argv[i]);
                    }  
                }
            }

        }


    }
    else if(strcmp(argv[1], "-r") == 0){
        for(int i = 2; i < argc - 1; i++){
            int checker  = checkDirectory(argv[i]);
            if(checker == 0){
                rmdir(argv[i]);
            }
            else{
                FILE *fptr = fopen(argv[i], "r");
                if(fptr == NULL){
                    printf("rm : cannot remove %s , no such file or directory\n");
                }
                else{
                    remove(argv[i]);
                }          
            }
        }


    }
    else{
        for(int i = 1; i < argc -1; i++){
            int checker  = checkDirectory(argv[i]);

            if(checker == 0){
                printf("rm : cannot remove %s ,is a directory\n");
            }
            else{
                FILE *fptr = fopen(argv[i], "r");
                if(fptr == NULL){
                    printf("rm : cannot remove %s , no such file or directory\n");
                }
                else{
                    remove(argv[i]);
                }
            }

        }

    }
}