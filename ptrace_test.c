#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/user.h>

int main(int argc, char argv)
{
	pid_t child = 0;
	long orig_eax = 0;
	long rv;
	
	child = fork();

	if(child == 0) {
		rv = ptrace(PTRACE_TRACEME, 0, NULL, NULL);
		if (rv == -1) {
			printf("ptrace(PTRACE_TRACEME, 0, NULL, NULL) failed...\n");
			exit(0);
		}
		printf("ptrace(PTRACE_TRACEME, 0, NULL, NULL) success!\n");
		execl("/bin/ls", "ls", NULL);
	}
	else {
		wait(NULL);
		ptrace(PTRACE_CONT, child, NULL, NULL);
	}
	return 0;
}
