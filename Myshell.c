#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<limits.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<pthread.h>

//pid null system absolutepath string copy 

//getlines

void* fcaller(void *f){
    char *f1 = (char *)f;
    system(f1);
    pthread_exit(NULL);
}
int main(){

    while(1){
    char str[1000];
    char *s1;
    fgets(str, 1000, stdin);
    char *found;
    char** string = (char**)malloc(sizeof(char)*100*1000);
    int i = 0;
    s1 = strdup(str);

    while((found = strsep(&s1, " ")) != NULL){
        string[i] = found;
        i++;
    } 



    if(strcmp(string[0], "echo") == 0){
        if(strcmp(string[1], "-n") == 0){
            for(int j = 2; j < i; j++){
                if(j != i - 1){
                    printf("%s", string[j]);
                    printf(" ");
                }
                else{
                    int k = 0;
                    while(string[j][k] != '\n'){
                        printf("%c", string[j][k]);
                        k++;
                    }
                }
            }
        }
        else if(strcmp(string[1], "--help") == 0){
            if(i == 3){
            FILE* ptr;
            char ch;
            ptr = fopen("echo.txt", "r");
            do {
             ch = fgetc(ptr);
            printf("%c", ch);
            } while (ch != EOF);
            fclose(ptr);}
            else{
                printf("Invalid command\n");
            }

        }
        else{
            for(int j = 1; j < i; j++){
                printf("%s", string[j]);
                printf(" ");
            }
            printf("\n");
        }
    }
    else if(strcmp(string[0], "cd") == 0){  
        char curpath[1000];
        char WD[1000];
        int k;
        // printf("%d\n", i);
        if(i == 2){
            k = chdir("/root");
        }
        else if(i > 4){
            printf("Invalid command \n");
        }
        else if(strcmp(string[1], "-P") == 0){
            char WD[1000];
            char buffer[PATH_MAX];
            char *result = realpath(getcwd(WD,sizeof(WD)) ,buffer);

            if(string[2][0] != '/'){
            strcat(buffer,"/");
            strcat(buffer, string[2]);
            }
            else{
               strcat(buffer, string[2]); 
            }

            k = chdir(buffer);

            if(k == -1){
                printf("cd : no such file or directory exists \n");
            }


        }
        else if(strcmp(string[1], "-L") == 0){
           k =  chdir(string[2]);
            if(k == -1){
                printf("cd : no such file or directory exists \n");
            }

        }

        else if(string[1][0] == '-'){
            printf("Invalid command\n");
        }


        else{
           k = chdir(string[1]);
            if(k == -1){
                printf("cd : no such file or directory exists \n");
            }
        }

    }
    else if(strcmp(string[0], "pwd") == 0){
        char WD[1000];

        if(i == 2){
            printf("%s\n", getcwd(WD,sizeof(WD)));
        }
        else{
            if(i == 3){
            if(strcmp(string[1], "-P") == 0){
                char buffer[PATH_MAX];
                char *result = realpath(getcwd(WD,sizeof(WD)) ,buffer);
                if(result){
                    printf("%s\n", buffer);
                }
            }
            else if(strcmp(string[1], "-L") == 0){
                printf("%s\n", getcwd(WD,sizeof(WD)));
            }
            else{
                printf("Invalid command!!!\n");
            }
            }
            else{
                printf("Invalid command\n");
            }
        }
    }
    else if(strcmp(string[0], "ls") == 0){
        // printf("Inside ls fork\n");
        int rc = fork();
        if(rc < 0){
            fprintf(stderr, "fork failed\n");
            exit(1);
        }
        else if(rc == 0){
            // printf("Inside else if\n");
            char *myargs[i+1];
            myargs[0] = strdup("/root/SecretProject/ls");
            for(int j1 = 1; j1 < i - 1; j1++ ){
                myargs[j1] = strdup(string[j1]);
            }
            myargs[i - 1] = NULL;
            execvp(myargs[0], myargs);
        }
        else{
            int rc_wait = wait(NULL);
        }       
    }
    else if(strcmp(string[0], "cat") == 0){
        // printf("Inside cat fork\n");
        int rc = fork();
        if(rc < 0){
            fprintf(stderr, "fork failed\n");
            exit(1);
        }
        else if(rc == 0){
            // printf("Inside else if\n");
            char *myargs[i+1];
            myargs[0] = strdup("/root/SecretProject/cat");
            for(int j1 = 1; j1 <  i - 1; j1++ ){
                myargs[j1] = strdup(string[j1]);
            }
            myargs[i - 1] = NULL;
            execvp(myargs[0], myargs);
        }
        else{
            int rc_wait = wait(NULL);
        }
    }
    else if(strcmp(string[0], "date") == 0){
        // printf("Inside date fork\n");
        int rc = fork();
        if(rc < 0){
            fprintf(stderr, "fork failed\n");
            exit(1);
        }
        else if(rc == 0){
            // printf("Inside date else if\n");
            char *myargs[i+1];
            myargs[0] = strdup("/root/SecretProject/date");
            for(int j1 = 1; j1 < i - 1; j1++ ){
                myargs[j1] = strdup(string[j1]);
            }
            myargs[i - 1] = NULL;
            execvp(myargs[0], myargs);
        }
        else{
            int rc_wait = wait(NULL);
        }
    }
    else if(strcmp(string[0], "rm") == 0){
        // printf("Inside rm fork\n");
        int rc = fork();
        if(rc < 0){
            fprintf(stderr, "fork failed\n");
            exit(1);
        }
        else if(rc == 0){
            // printf("Inside rm else if\n");
            char *myargs[i+1];
            myargs[0] = strdup("/root/SecretProject/rm");

            for(int j1 = 1; j1 < i - 1; j1++ ){
                myargs[j1] = strdup(string[j1]);
            }

            myargs[i -1] = NULL;
            execvp(myargs[0], myargs);
        }
        else{
            int rc_wait = wait(NULL);
        }
    }

    else if(strcmp(string[0], "mkdir") == 0){
        // printf("Inside mkdir fork\n");
        int rc = fork();

        if(rc < 0){
            fprintf(stderr, "fork failed\n");
            exit(1);
        }
        else if(rc == 0){
            // printf("Inside else if mkdir \n");
            char *myargs[i+1];
            myargs[0] = strdup("/root/SecretProject/mkdir");
            for(int j1 = 1; j1 < i - 1; j1++ ){
                myargs[j1] = strdup(string[j1]);
            }
            myargs[i - 1] = NULL;
            execvp(myargs[0], myargs);
        }
        else{
            int rc_wait = wait(NULL);
        }
    }
    else if(strcmp(string[0], "&tmkdir") == 0){
        pthread_t pid;
        char command[10000];
        strcpy(command, "/root/SecretProject/mkdir");
        for(int j1 = 1; j1 < i; j1++ ){
            strcat(command , " ");
            strcat(command, string[j1]);
        }
        // const char *command1 = command.c_str();
        
        pthread_create(&pid, NULL, &fcaller, command);
        pthread_join(pid, NULL);
    }
    else if(strcmp(string[0], "&trm") == 0){
        pthread_t pid;
        char command[10000];
        strcpy(command, "/root/SecretProject/rm");
        for(int j1 = 1; j1 < i; j1++ ){
            strcat(command , " ");
            strcat(command, string[j1]);
        }
        pthread_create(&pid, NULL, &fcaller, command);
        pthread_join(pid, NULL);
    }
    else if(strcmp(string[0], "&tdate") == 0){
        pthread_t pid;
        char command[10000];
        strcpy(command, "/root/SecretProject/date");
        for(int j1 = 1; j1 < i; j1++ ){
            strcat(command , " ");
            strcat(command, string[j1]);
        }
        pthread_create(&pid, NULL, &fcaller, command);
        pthread_join(pid, NULL);
    }
    else if(strcmp(string[0], "&tcat") == 0){
        pthread_t pid;
        char command[10000];
        strcpy(command, "/root/SecretProject/cat");
        for(int j1 = 1; j1 < i; j1++ ){
            strcat(command , " ");
            strcat(command, string[j1]);
        }
        pthread_create(&pid, NULL, &fcaller, command);
        pthread_join(pid, NULL);
    }
    else if(strcmp(string[0], "&tls") == 0){
        pthread_t pid;
        char command[10000];
        strcpy(command, "/root/SecretProject/ls");
        for(int j1 = 1; j1 < i; j1++ ){
            strcat(command , " ");
            strcat(command, string[j1]);
        }
        pthread_create(&pid, NULL, &fcaller, command);
        pthread_join(pid, NULL);
    }
    else{
        printf( "Invalid command\n");
    }
    }
}