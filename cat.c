#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<limits.h>
#include<sys/wait.h>

int main(int argc, char *argv[]){
    if(strcmp(argv[1], "-E") == 0){

        for(int i = 2; i < argc -1; i++){
            FILE* ptr;
            ptr = fopen(argv[i], "r");
            if(ptr != NULL){
                char ch;
                do {
                ch = fgetc(ptr);
                if (ch != '\n'){
                    printf("%c", ch);
                }
                else{
                    printf("$%c", ch);
                }

                } while (ch != EOF);
                printf("\n");
                fclose(ptr);
            }
            else{
                printf("cat: %s : No such file or directory\n", argv[i]);
            }
        }
    }
    else if(strcmp(argv[1], "-n") == 0){
        int counter = 1;
        for(int i = 2; i < argc -1; i++){
            FILE* ptr;
            ptr = fopen(argv[i], "r");
            if(ptr != NULL){
                char ch;
                printf("%d ", counter);
                do {
                ch = fgetc(ptr);
                printf("%c", ch);
                if(ch == '\n'){
                    printf("%d ", counter++);
                }
                } while (ch != EOF);
                printf("\n");
                fclose(ptr);
            }
            else{
                printf("cat: %s : No such file or directory\n", argv[i]);
            }
        }
    }
    else{
        
        for(int i = 1; i < argc -1; i++){
            FILE* ptr;
            ptr = fopen(argv[i], "r");
            if(ptr != NULL){
                char ch;

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
