#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/stat.h>

int main()
{
	int fd;
	char s[30];

	char *myfifo = "/tmp/myfifo";

	mknod(myfifo,0666,0);

	fd = open(myfifo,O_RDONLY);
	read(fd,s,30);
	printf("Process 2 : %s\n",s);
	close(fd);

	fd = open(myfifo,O_WRONLY);
	printf("Enter the acknowledgement message = ");
	scanf("%s",s);
	write(fd,s,strlen(s)+1);
	close(fd);

	return 0;
}
