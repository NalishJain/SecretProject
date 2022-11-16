#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    // for(int i = 0; i < 100; i++){
    // }

    system("make -j2");
    printf("Exiting child\n");
}
