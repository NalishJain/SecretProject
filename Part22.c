#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include<unistd.h>
#include <time.h>

#define BILLION  1000000000.0

int main(){

  
    //Process1
    struct timespec p1start, p1end;
    struct timespec p2start, p2end;
    struct timespec p3start, p3end;

    clock_gettime(CLOCK_REALTIME, &p1start);
    int rc1 = fork();
    clock_gettime(CLOCK_REALTIME, &p2start);
    int rc2 = fork();
    clock_gettime(CLOCK_REALTIME, &p3start);
    int rc3 = fork();


    double p1time;
    double p2time;
    double p3time;

    if(rc1 < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if(rc1 == 0){

        char *myargs[2];
        myargs[0] = strdup("/home/SecretProject/bashscript.sh");
        myargs[1] = NULL;
        execvp(myargs[0], myargs);

    }
    if(rc2 < 0){
            fprintf(stderr, "fork failed\n");
            exit(1);
    }
    else if(rc2 == 0){

        char *myargs2[2];
        myargs2[0] = strdup("/home/SecretProject/bashscript2.sh");
        myargs2[1] = NULL;
        execvp(myargs2[0], myargs2);

    }  
    if(rc3 < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if(rc3 == 0){
        char *myargs3[2];
        myargs3[0] = strdup("/home/SecretProject/bashscript3.sh");
        myargs3[1] = NULL;
        execvp(myargs3[0], myargs3);
    }

    int rc1_wait = wait(null);
    clock_gettime(CLOCK_REALTIME, &p1end);
    p1time = (p1end.tv_sec - p1start.tv_sec) +(p1end.tv_nsec - p1start.tv_nsec) / BILLION; 

    int rc2_wait = wait(null);
    clock_gettime(CLOCK_REALTIME, &p2end);         
    p2time = (p2end.tv_sec - p2start.tv_sec) +(p2end.tv_nsec - p2start.tv_nsec) / BILLION;
          
    int rc3_wait = wait(NULL); 
    clock_gettime(CLOCK_REALTIME, &p3end);         
    p3time = (p3end.tv_sec - p3start.tv_sec) + (p3end.tv_nsec - p3start.tv_nsec) / BILLION;
           
    printf("%lf %lf %lf \n", p1time, p2time, p3time);
}
