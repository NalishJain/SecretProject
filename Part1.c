#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <limits.h>
#include <math.h>
#include <sched.h>
#define BILLION  1000000000.0


void countA(){
    int count = 0;
    for(int i = 0; i < UINT_MAX; i++){
        count++;
    }
}

void countB(){
    int count = 0;
    for(int i = 0; i < UINT_MAX; i++){
        count++;
    }
}

void countC(){
    int count = 0;
    for(int i = 0; i < UINT_MAX; i++){
        count++;
    }
}

void* p1caller(void *f){
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);
    countA();
    clock_gettime(CLOCK_REALTIME, &end);
    pthread_exit(NULL);
    double *ptr = malloc(sizeof(double));
    *ptr = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
    return (void*)ptr;
}

void* p2caller(void *f){
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);
    countB();
    pthread_exit(NULL);
    clock_gettime(CLOCK_REALTIME, &end);
    pthread_exit(NULL);
    double *ptr = malloc(sizeof(double));
    *ptr = (end.tv_sec - start.tv_sec) +(end.tv_nsec - start.tv_nsec) / BILLION;
    return (void*)ptr;
}

void* p3caller(void *f){
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);
    countC();
    pthread_exit(NULL);
    clock_gettime(CLOCK_REALTIME, &end);
    pthread_exit(NULL);
    double *ptr = malloc(sizeof(double));
    *ptr = (end.tv_sec - start.tv_sec) +(end.tv_nsec - start.tv_nsec) / BILLION;
    return (void*)ptr;
}

int main(){
    pthread_t ThreadA, ThreadB, ThreadC;
    struct sched_param paramA, paramB, paramC;

    //Case1
    paramA.sched_priority = 0;
    paramB.sched_priority = 1;
    paramC.sched_priority = 1;

    pthread_setschedparam(ThreadA, SCHED_OTHER, &paramA);
    pthread_setschedparam(ThreadB, SCHED_RR, &paramB);
    pthread_setschedparam(ThreadC, SCHED_FIFO, &paramC);

    double r1,r2,r3;
    pthread_create(&ThreadA, NULL, &p1caller,NULL);
    pthread_create(&ThreadB, NULL, &p2caller, NULL);
    pthread_create(&ThreadC, NULL, &p3caller, NULL);
    pthread_join(ThreadA, (void **) &r1);
    pthread_join(ThreadB, (void **) &r2);
    pthread_join(ThreadC, (void **) &r3);

    printf("%lf %lf %lf",r1,r2,r3);



    // pthread_join(pid1, NULL);
}