#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<limits.h>
#include<sys/wait.h>

int main(int argc, char *argv[]){
    if(strcmp(argv[1], "-E") == 0){

    }
    else if(strcmp(argv[1], "-n") == 0){

    }
    else{
        for(int i = 1; i < argc; i++){
            FILE* ptr;
            ptr = fopen(argv[i], "r");
            if(ptr != NULL){
                do {
                ch = fgetc(ptr);
                printf("%c", ch);
                } while (ch != EOF);
                fclose(ptr);
            }
            else{
                printf("cat: %s : No such file or directory\n", argv[i]);
            }
        }
    }

}
