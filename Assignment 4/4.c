# include<stdio.h>
# include<string.h>
# include<unistd.h>
# include<fcntl.h>

int main() {

   struct flock obj;
   char msg[80];
   int fp = open("4.txt",O_RDWR);   
   
   if(fp == -1){
      printf("Error In File Opening\n");
      return 0;
   }

   obj.l_type = F_WRLCK;
   obj.l_whence = SEEK_SET;
   obj.l_start = 0;
   obj.l_len = 0;
   obj.l_pid = getpid();

   if(fcntl(fp, F_SETLK, &obj) == -1) {

      printf("Can't Block Terminal 1!!");

      while(obj.l_type != F_UNLCK)
         fcntl(fp, F_GETLK, &obj);
      
      read(fp, msg, 80);
      printf("\nMessage Read From The File Is : %s", msg);

   }  else {

      printf("Terminal 2 Blocked");

      read(fp, msg, 80);

      printf("\nMessage Read From File Is : %s", msg);
      getchar();

      obj.l_type = F_UNLCK;  
      fcntl(fp, F_SETLK, &obj);
   }
   

   close(fp);
   return 0;
}
