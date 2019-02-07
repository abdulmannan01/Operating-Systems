#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<signal.h>
#include<string.h>

void signal_func(int x);

int main()
{
	signal(SIGINT,signal_func);
	while(1);
	return 0;
}


void signal_func(int x)
{
	int fd[2] , N;

	if(pipe(fd)<0)
	{
		exit(0);
	}

	printf("Enter the number of terms = ");
        scanf("%d",&N);

	int f = fork();

	if(f<0)
	{
		exit(0);
	}
	else if(f==0)
	{
		close(fd[0]);
	
		int p = getpid();
		write(fd[1],&p,sizeof(p));

		int a[N+1];
		a[0] = 0;
		write(fd[1],&a[0],sizeof(a[0]));
	        a[1] = 1;
		write(fd[1],&a[1],sizeof(a[1]));
		for(int i=2;i<N;i++)
		{
			a[i] = a[i-1]+a[i-2];
			write(fd[1],&a[i],sizeof(a[i]));
		}
		close(fd[1]);
		exit(1);
	}
	else
	{
		wait(NULL);
		close(fd[1]);
	        
		int p;
		read(fd[0],&p,sizeof(p));
		printf("The process id of the child is: %d\n",p);

		int b[N+1];
		printf("The fibbonacci series is : ");
		for(int i=0;i<N;i++)
		{
			read(fd[0],&b[i],sizeof(b[i]));
			printf("%d  ",b[i]);
		}
		printf("\nThe interrupt signal id is: %d\n",x);
		close(fd[0]);
		exit(1);
	}
}

