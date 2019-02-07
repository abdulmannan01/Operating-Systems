#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>


struct msgd
{
	
	long mtype;
	char msgtext[100];
};


int main()
{
	struct msgd msg;
	key_t key;
	int msgid;

	if((key=ftok("5.txt",'b')) == -1)
	{
		exit(1);
	}

	if((msgid=msgget(key,0644|IPC_CREAT)) == -1)
	{
		exit(1);
	}

	for(;;)
	{
		if(msgrcv(msgid,&msg,sizeof(msg),1,0) == -1)
		{
			exit(1);
		}
		printf("%s\n",msg.msgtext);
	}

	if((msgctl(msgid,IPC_RMID,NULL)) == -1)
	{
		exit(1);
	}

	return 0;
}
