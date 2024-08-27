/*GIRISH KUMAR SAHU*/
/*MT2024051*/

/*Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(){
	int fd = open("text.txt", O_WRONLY | O_CREAT);
	if(fd < 0){
		perror("failed to open file");
		return 1;
	}
	else if(fd == 0){
		const char *child_msg = "This is written by child process";
		write(fd,child_msg,sizeof(child_msg)*strlen(child_msg));
	}else{
		const char *parent_msg = "This is written by Parent Process";
		write(fd,parent_msg,sizeof(parent_msg)*strlen(parent_msg));
	}

	close(fd);

	return 0;
}
