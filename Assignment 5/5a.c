#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>


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
	char c;

	if((key=ftok("5.txt",'b')) == -1)
	{
		exit(1);
	}

	if((msgid=msgget(key,0644|IPC_CREAT)) == -1)
	{
		exit(1);
	}

	printf("The message id is %d",msgid);

	msg.mtype = 1;
	do
	{
		printf("\nEnter the message = ");
		scanf("%s",msg.msgtext);
		if(msgsnd(msgid,&msg,sizeof(msg),0) == -1)
		{
			exit(1);
		}
		printf("Do you want to add another message?(y/n) ");
		scanf(" %c",&c);
	}while(c!='n');

	if(msgctl(msgid,IPC_RMID,0) == -1)
	{
		exit(1);
	}

	return 0;
}
