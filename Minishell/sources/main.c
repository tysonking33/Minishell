#include "../includes/Minishell.h"

/* show the initalisation of the shell */
void init_shell()
{
    printf("|-------------------------------------------------------|\n");
    printf("|                                                       |\n");
    printf("|                 Welcome to the shell                  |\n");
    printf("|                                                       |\n");
    printf("|-------------------------------------------------------|\n");
    char *username = getenv("USER");
    printf("User is %s\n", username);

}

/* take input */
int takeInput(char *inputString)
{
    char* buff;

    buff = readline("\n>>> ");
    if (strlen(buff) != 0){
        add_history(buff);
        strcpy(inputString, buff);
        //printf("%s\n", inputString);
        int i = 0;
        while (inputString[i]){
            if (inputString[i] == '\n')
                inputString[i] = '\0';
            i++;
        }
        return 0;
    }
    else{
        return 1;
    }
}

/* find number of arguments (cmd) = 1, (cmd arg1) = 2*/
int argCount(char *src)
{
    int i;
    int arg_count;

    i = 0;
    arg_count = 0;
    while (src[i])
    {
        if (src[i] == ' '){
            arg_count++;
        }
        i++;
    }
    return (arg_count + 1);
}

/* parse commands */
char **parse_commands(char *src)
{
    int arg_count;

    arg_count = argCount(src);
    char **parsed = (char **)malloc(arg_count*sizeof(char **));
    int i = 0;
    while (i < arg_count)
    {
        parsed[i] = (char *)malloc(1000*sizeof(char *));
        i++;
    }
    parsed = ft_split_string(src);
    /*i = 0;

    while (i < arg_count+1){
        printf("wagwan %s\n", parsed[i]);
        i++;
    }*/
    return parsed;
}

/* string compare */
int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		++i;
	}
	return (s1[i] - s2[i]);
}

/* find presetablished commands, e.g. echo, cd*/
void change_to_preestablished_loc(char **parsedCommands)
{
    char *current_command = parsedCommands[0];
    if (ft_strcmp(current_command, "echo") == 0){
        parsedCommands[0] = "/usr/bin/echo";
    }
    else if (ft_strcmp(current_command, "sudo") == 0){
        parsedCommands[0] = "/usr/bin/sudo";
    }
    else if (ft_strcmp(current_command, "man") == 0){
        parsedCommands[0] = "/usr/bin/man";
    }
    else if (ft_strcmp(current_command, "pwd") == 0){
        parsedCommands[0] = "/usr/bin/pwd";
    }
    else if (ft_strcmp(current_command, "mkdir") == 0){
        parsedCommands[0] = "/usr/bin/mkdir";
    }
    else if (ft_strcmp(current_command, "ls") == 0){
        parsedCommands[0] = "/usr/bin/ls";
    }
    else if (ft_strcmp(current_command, "cat") == 0){
        parsedCommands[0] = "/usr/bin/cat";
    }
    else if (ft_strcmp(current_command, "cd") == 0){                    //not yet working
        parsedCommands[0] = "cd:";
    }
    else if (ft_strcmp(current_command, "clear") == 0){                 //not yet working
        parsedCommands[0] = "/usr/bin/clear";
    }

    printf("no no seggy fault\n");
}

/* execute arguments*/
void execute_arguments(char **parsedCommands)
{
    pid_t pid = fork();
    //printf("currentdir: %s\n",currentdir);
    char *newenvironment[] = { NULL };
    /*char **fullParseCommand = (char **)malloc((arg_count+1)*sizeof(char **));
    int i = 0;
    while (i < arg_count +1)
    {
        fullParseCommand[i] = (char *)malloc(1000*sizeof(char *));
        i++;
    }*/
    change_to_preestablished_loc(parsedCommands);
    /*int i = 0;
    printf("not seg fault0\n");
    while (parsedCommands[i]){
        printf("parsedCommands[%d]: %s\n", i, parsedCommands[i]);
        i++;
    }
    printf("not seg fault1\n");*/
    if (pid <= -1)
    {
        //printf("failed fork\n");
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
        //printf("in parent process\n");
        wait(NULL);
    }
}


int main()
{
    char inputString[1000];
    int arg_count;


    init_shell();
    while (1)
    {
        if (takeInput(inputString) == 1){
            break;
        }
        arg_count = argCount(inputString);
        //printf("ddawg\n");
        char **parsedArgString = (char **)malloc((arg_count+1)*sizeof(char **));
        int i = 0;
        while (i < arg_count +1)
        {
            parsedArgString[i] = (char *)malloc(1000*sizeof(char *));
            i++;
        }
        parsedArgString = parse_commands(inputString);
        //char *newenvironment[] = { NULL };
        i = 0;
        while (i < arg_count + 1){
            printf("bigbruh %s\n", parsedArgString[i]);
            i++;
        }
        int toggle = 0;
        if (toggle == 0){
            execute_arguments(parsedArgString);
            toggle = 1;
        }
        //break ;


    }

    return 0;
}