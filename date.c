#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<limits.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include <dirent.h>
#include<time.h>

int main(int argc, char *argv[]){
    // printf("%d\n", argc);
    if(strcmp(argv[1], "-u") == 0){
        if(argc == 3 || argc == 2){
            int flag = 1;
            if(argc == 3){
                if(!argv[2]){
                }
                else{
                    flag = 0;
                    printf("Invalid Command\n");
                }
            }

            if(flag == 1){
            struct tm *gtime;
            time_t T;

            T = time(NULL);
            gtime = gmtime(&T);

            char dayArray[7][4] = {"Sun","Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
            char monArray[12][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

            for(int k = 0; k < 3; k++){
                printf("%c", dayArray[gtime->tm_wday][k]);
            }
            printf(" ");
            for(int k = 0; k < 3; k++){
                printf("%c", monArray[gtime->tm_mon][k]);
            }
            printf(" ");
            printf("%d %d:%d:%d UTC %d\n", gtime->tm_mday, gtime->tm_hour, gtime->tm_min, gtime->tm_sec, gtime->tm_year + 1900);
            }

        }
        
        else{
            printf("Invalid command \n");
        }

    }

    else if(strcmp(argv[1], "-r") == 0){
        int flag = 1;
        if(argc == 4 || argc == 3){
            if(argc == 4){
                if(!argv[3]){
                }
                else{
                    flag = 0;
                    printf("Invalid Command\n");
                }
            }

            if(flag == 1){
                DIR* dir = opendir(argv[2]);
                if(dir){
                    struct stat tr;
                    stat(argv[2], &tr);
                    printf("%s\n", ctime(&tr.st_mtime));
                }
                else{
                    FILE* fptr = fopen(argv[2], "r");
                    if(fptr){
                        struct stat tr;
                        stat(argv[2], &tr);
                        printf("%s\n", ctime(&tr.st_mtime));
                    }
                    else{
                        printf("date : no such file or directory exists \n");
                    }
                } 
                }    
        }
        else{
            printf("Invalid command \n");
        }
    }

    else{
        if((argc == 2 && argv[1] == NULL) || argc == 1){
        time_t T;
        time(&T);
        printf("%s\n", ctime(&T));
        }

        else{
            printf("Invalid command \n");
        }

        
    }
    

}