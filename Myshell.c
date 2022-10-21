#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main(){
    char str[1000];
    char *s1;
    fgets(str, 1000, stdin);
    char *found;
    char** string = (char**)malloc(sizeof(char)*100*1000);
    int i = 0;
    s1 = strdup(str);

    while((found = strsep(&s1, " ")) != NULL){
        string[i] = found;
        i++;
    } 



    if(strcmp(string[0], "echo") == 0){
        if(strcmp(string[1], "-n") == 0){
            for(int j = 2; j < i; j++){
                if(j != i - 1){
                    printf("%s", string[j]);
                    printf(" ");
                }
                else{
                    int k = 0;
                    while(string[j][k] != '\n'){
                        printf("%c", string[j][k]);
                        k++;
                    }
                }
            }
        }
        if(strcmp(string[1], "--help") == 0){
            FILE* ptr;
            char ch;
            ptr = fopen("echo.txt", "r");
            do {
             ch = fgetc(ptr);
            printf("%c", ch);
            } while (ch != EOF);
            fclose(ptr);
        }
        else{
            for(int j = 1; j < i; j++){
                printf("%s", string[j]);
                printf(" ")
            }
            printf("\n");
        }
    }
    else if(strcmp(string[0], "cd") == 0){   
    }
    else if(strcmp(string[0], "pwd") == 0){}
    else if(strcmp(string[0], "ls") == 0){}
    else if(strcmp(string[0], "cat") == 0){}
    else if(strcmp(string[0], "date") == 0){}
    else if(strcmp(string[0], "rm") == 0){}
    else if(strcmp(string[0], "mkdir") == 0){}
}