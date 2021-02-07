#include <stdio.h> 
#include <sys/types.h> 
#include<unistd.h>

int main() 
{ 
	int pid = fork(); 
	int pid2 = fork(); 
	int pid3 = fork(); 
	printf("hello world, %d %d %d\n", pid, pid2, pid3); 
	return 0; 
} 


