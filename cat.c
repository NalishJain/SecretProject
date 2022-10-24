#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<limits.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>

int main(int argc, char *argv[]){
    if(strcmp(argv[1], "-E") == 0){

        for(int i = 2; i < argc; i++){
            if(argv[i]){
            FILE* ptr;
            ptr = fopen(argv[i], "r");
            char *l;
            size_t size = 1000;
            size_t c;
            l = (char*)malloc(size*sizeof(char));
            if(ptr != NULL){
                while(getline(&l, &size, ptr) != -1){
                    //printf("%s $ \n", l);
                    int i1 = 0;
                    while(l[i1] != '\n'){
                        printf("%c", l[i1]);
                        i1++;
                    }
                    printf("$");
                    printf("\n");
                }

            }
            else{
                printf("cat: %s : No such file or directory\n", argv[i]);
            }
        }
        }
    }
    else if(strcmp(argv[1], "-n") == 0){
        int counter = 1;
        for(int i = 2; i < argc; i++){
            if(argv[i]){
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
    }
    else{
        
        for(int i = 1; i < argc; i++){
            if(argv[i]){
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

}