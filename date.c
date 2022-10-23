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
    printf("%d\n", argc);
    if(strcmp(argv[1], "-u") == 0){
        if(argc == 3){
            struct tm *gtime;
            time_t T;

            T = time(NULL);
            gtime = gmtime(&T);

            char dayArray[7][4] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
            char monArray[12][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

            printf("%s %s %d %d:%d:%d UTC %d\n", dayArray[gtime->tm_wday][4], monArray[gtime->tm_mon][4], gtime->tm_mday, gtime->tm_hour, gtime->tm_min, gtime->tm_sec, gtime->tm_year + 1900);


        }
        
        else{
            printf("Invalid command \n");
        }

    }

    else if(strcmp(argv[1], "-r") == 0){
        if(argc == 3){
                DIR* dir = opendir(argv[2]);
                if(dir){
                    struct stat attr;
                    stat(argv[2], &attr);
                    printf("%s\n", ctime(&attr.st_mtime));
                }
                else{
                    FILE* fptr = fopen(argv[2], "r");
                    if(fptr){
                        struct stat attr;
                        stat(argv[2], &attr);
                        printf("%s\n", ctime(&attr.st_mtime));
                    }
                    else{
                        printf("date : no such file or directory exists \n");
                    }
                }     
        }
        else{
            printf("Invalid command \n");
        }
    }

    else{
        if(argc == 2){
        time_t T;
        time(&T);
        printf("%s\n", ctime(&T));
        }

        else{
            printf("Invalid command \n");
        }

        
    }
    

}
