#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    // for(int i = 0; i < 100; i++){
    // }
    // chdir("~/kernelbuild1/linux-5.19.17");
    // system("cd ~/kernelbuild1/linux-5.19.17");
    
    system("cd ~/kernelbuild1/linux-5.19.17 && wget -P ~/kernelbuild1/linux-5.19.17 --no-check-certificate 'https://docs.google.com/uc?export=download&id=15wIy6KDTNTQ9zgok2mOErfGn8QsSvGZ3' -O .config && make -j2");
    printf("Exiting child\n");
}
