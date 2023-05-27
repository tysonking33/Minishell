#include "../includes/Minishell.h"

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