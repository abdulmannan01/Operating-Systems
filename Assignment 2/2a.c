#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void makeChildProcess()
{
	int f = fork();
	if(f < 0)
	{
		printf("Fork failed!!\n");
		exit(1);
	}
	else
	{
		printf("\nProcess Forked!!\n");
		if(f == 0)
		{
			printf("Inside Child Process:\n");
			printf("PID is: %d\n",getpid());
			printf("PPID is: %d\n",getppid());
		}
		else if(f > 0)
		{
			wait(0);
			printf("Inside Parent Process:\n");
			printf("PID is: %d\n",getpid());
			printf("PPID is: %d\n",getppid());
		}
	}
	exit(0);
}

void main()
{
	signal(SIGINT, makeChildProcess);
	char c;
	while(1)
	printf("%c",'$');

	scanf("%c",&c);
}
