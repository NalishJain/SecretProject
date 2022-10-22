#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<limits.h>
#include<sys/wait.h>

int main(int argc, char *argv[]){
    
    for(int i = 0; i < argc; i++){
        printf("%s\n", argv[i]);
    }

}
