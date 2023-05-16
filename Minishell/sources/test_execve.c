#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h> //readline
#include <readline/history.h>   //readline
#include <stdlib.h>             //malloc
#include<sys/wait.h>            //wait


int main(){
    pid_t pid = fork();
    char *currentdir = (char *)malloc(1000 * sizeof(char *));
    getcwd(currentdir, sizeof(currentdir));
    char *newenvironment[] = { NULL };
    char *parsedCommands[] = {"/usr/bin/echo", "a", "b", NULL};
    if (pid <= -1)
    {
        perror("failed forking\n");
    }
    else if (pid == 0)
    {
        printf("in child process\n");
        int execute = execve(parsedCommands[0], parsedCommands, newenvironment);
        printf("execute: %d\n", execute);
    }
    else
    {
        wait(NULL);
    }
    return 0;
}