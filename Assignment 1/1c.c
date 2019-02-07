#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
int main()
{
        int pid;
        int s;
        pid = fork();

        if (pid<0)
        {
                fprintf(stderr,"Fork Failed !");
                exit(1);
        }
        else if(pid ==0)
        {
                printf("Child Process. .\n");
                char *args[]={"./1c_1",NULL};
                execv("./1c_1",args);
                exit(0);
        }
        else
        {
                wait(&s);
                if (WIFEXITED(s))
                        printf("Normal Exit !\n");
                else
                        printf("Abnormal Exit\n");
                printf("Hello! I am parent, I am after child.\n");
        }
}
