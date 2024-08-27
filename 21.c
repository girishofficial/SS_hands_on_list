/*GIRISH KUMAR SAHU*/
/*MT2024051*/

/*Write a program, call fork and print the parent and child process id.*/

#include <stdio.h>
#include <unistd.h>


int main(){
	pid_t pid = fork();

	if(pid < 0){
		perror("Fork failed");
		return 1;
	}else if (pid == 0){
		printf("Child process : PID = %d, Parent PID = %d\n", getpid(), getpid());
	}else{
		printf("Parent Process : PID = %d, Child PID = %d\n", getpid(), getpid());
	}

	return 0;
}
