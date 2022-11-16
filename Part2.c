#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include<unistd.h>
#include <time.h>

#define BILLION  1000000000.0

int main(){

    system("mkdir ~/kernelbuild1");
    system("cd ~/kernelbuild1");
    system("wget -P ~/kernelbuild1/ https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.19.17.tar.xz");
    system("unxz linux-5.19.17.tar.xz");
    system("tar -xvf linux-5.19.17.tar");
    system("chown -R $USER:$USER linux-5.19.17");



    //Process1
    struct timespec p1start, p1end;
    clock_gettime(CLOCK_REALTIME, &p1start);
    int rc1 = fork();
    double p1time;

    if(rc1 < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if(rc1 == 0){

        char *myargs[2];
        myargs[0] = strdup("/root/SecretProject/Part2a");
        myargs[1] = NULL;
        execvp(myargs[0], myargs);

    }
    else{
        int rc1_wait = wait(NULL);

    }
    clock_gettime(CLOCK_REALTIME, &p1end);
    p1time = (p1end.tv_sec - p1start.tv_sec) +(p1end.tv_nsec - p1start.tv_nsec) / BILLION;
    printf("%lf \n", p1time);
}
