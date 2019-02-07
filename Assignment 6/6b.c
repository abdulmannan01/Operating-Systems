#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/times.h>
#include <time.h>
#include <unistd.h>

int main()
{
  struct tms before, after;
  time_t currtime;

  //times(&before);

  int pid;

	pid = fork();

	if(pid < 0)
	{
		printf("\nCould not create child process.");

		exit(1);
	}
	else if(pid == 0)
	{

		printf("\n\nThis is the child process.");
		printf("\nMy PID: %d", getpid());
		printf("\nMy Parent's PID: %d", getppid());

		exit(0);
	}
	else
	{
		wait(NULL);

		printf("\n\nThis is the parent process.");
		printf("\nMy PID: %d", getpid());
		printf("\nMy Child's PID: %d", pid);

    times(&after);

    printf("\n\nUser time: %ld seconds\n", before.tms_utime);
    printf("System time: %ld seconds\n", before.tms_stime);

		exit(0);
	}

  /*times(&after);

  printf("User time: %ld seconds\n", after.tms_utime, before.tms_utime);
  printf("System time: %ld seconds\n", after.tms_stime, before.tms_stime);*/

  return 0;
}
