/*Girish Kumar Sahu*/
/*MT2024051*/

/*Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(void){
	struct flock lock;
	int fd;
	fd=open("db",O_RDWR);
	lock.l_type = F_RDLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=0;
	lock.l_len=0;
	lock.l_pid=getpid();
	printf("Before entering into critical section\n");
	fcntl(fd,F_SETLKW, &lock);
	printf("Inside the critical section...\n");
	printf("Enter to Unlock..\n");
	getchar();
	printf("unlocked\n");
	lock.l_type=F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
	printf("finish\n");
}
