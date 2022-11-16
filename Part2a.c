#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    // for(int i = 0; i < 100; i++){
    // }
    system("cd linux-5.19.17");
    system("make mrproper");
    system("wget --no-check-certificate 'https://docs.google.com/uc?export=download&id=15wIy6KDTNTQ9zgok2mOErfGn8QsSvGZ3' -O .config");
    system("make -j2");
    printf("Exiting child\n");
}
