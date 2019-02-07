#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
	int f = fork();
	if(f == 0){
		printf("In child process:  pid: %d , ppid: %d\n",getpid(),getppid());
		exit(0);
	}else if(f > 0 ){
		wait(NULL);
		printf("In Parent process: pid: %d , ppid: %d\n",getpid(),getppid());
		exit(0);
	}
	else
	{
		printf("Fork system call not executed\n");
		exit(1);
	}
	return 0;
}
