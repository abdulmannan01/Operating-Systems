#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main(){
	int f = fork();
	int status;
	if(f==0){
		printf("Child Prcoess : \n");
		char *args[]={"./1c_1",NULL};
		execv(args[0],args);
	}
	else if(f>0)
	{
		wait(&status);
		if(WIFEXITED(status))
		{
			printf("Child executed successfully\n");
		}
		else
		{
			printf("Error !\n");
			exit(1);
		}
		printf("Parent Process : \n");
	}
	else
	{
		printf("FATAL ERROR");
	}
	return 0;
}
