#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

// This will be the first excersize
int auebsh1(void)
{
	char str[255];
	char *cmd;
	int status;
	pid_t pid, waitPid;
	printf("\n--Welcome to auebsh1--\n");
	printf("auebsh1> ");

	while (fgets(str, 255, stdin)) {
		pid = fork();

		if (pid < 0) {

			perror("ERROR: Child couldnt be created!\n");
			return -1;
		} 
        if (pid == 0) {
			// When using fgets it also reads the newLine character.
			// We must remove it using strtok
			cmd = strtok(str, "\n");
			execlp(cmd, cmd, NULL);
			perror("There is no such instruction!!\n");
			return -1;
		}
        else {
			waitPid = wait(&status);

			if (waitPid == -1) {
				perror("Failed to wait for child to be executed! \n");
			}
			printf("\nauebsh1> ");
		}
	}

	printf("\nAuebsh1 Terminated!\n");
	return 1;
}

// Runs the certain Terminal
int main()
{
    auebsh1();

    printf("Terminal Finished...\nClosing...\n");
    return 0;
}