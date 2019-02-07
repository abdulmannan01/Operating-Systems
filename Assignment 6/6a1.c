#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<unistd.h>

main()
{
	key_t key=ftok("shmfile",65);
	int shmid=shmget(key,1024,0666|IPC_CREAT);
	
	char *str=(char*)shmat(shmid,(void*)0,0);
	
	sprintf(str,"%d",getpid());
	printf("Data written in the shared memory:%s\n",str);
	shmdt(str);

	return 0;
}
