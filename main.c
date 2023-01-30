/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phunguye <phunguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:39:14 by phunguye          #+#    #+#             */
/*   Updated: 2023/01/23 15:13:59 by phunguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void assign_type(t_token *node){
    if ((strcmp(node->token_string, "cd") == 0) || ){
        node->type = 1;
    }
    else if ((strcmp(node->token_string, "vim") == 0) || (strcmp(node->token_string, "nano") == 0)
        || (strcmp(node->token_string, "cat") == 0) || (strcmp(node->token_string, "touch") == 0)){
        node->type = 2;
    }
    else if ((strcmp(node->token_string, "ls") == 0)){
        node->type = 2;
    }
}

int ft_attach_command_token(t_token *end_node, char *source)
{
	t_env *new_node;

	new_node = malloc(sizeof(t_env));
    new_node->env_variable = malloc(strlen(source));
	if(!strcpy(new_node->env_variable, source))
		return(-1);
    assign_type(new_node);
	end_node->next = new_node;
	return(1);
}

/* test function to print environment */
void print_env(t_msh *minishell){
    t_env *current_variable = minishell->environment_list;

    while (current_variable){
        printf("%s\n", current_variable->env_variable);
        current_variable = current_variable->next_pointer;
    }
}

int get_commands(t_msh *minishell, char *stdin)
{
    int i = 0;
    int status = 1;

    char *commmand  = readline("$ ");
    char *indiv_comms = strtok(command, " ");

    t_token *current_token;
    current_token = malloc(sizeof(t_token));
    current_token->token_string = malloc(strlen(indiv_comms[i]);
    strcpy(current_token->token_string, indiv_comms[i++]);
    minishell->token_list = current_token;


    while (indiv_comms[i]){
		status = ft_attach_command_token(current_token, indiv_comms[i++]);
		if(status == -1)
            return(-1);
		current_token = current_token->next;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_msh	minishell;
	int status;

	status = 1;
	status = get_environment(&minishell, env);
	while(status)
	{
		printf("$ ");
		status = get_commands(minishell, stdin);

		status = execute(minishell);

	}
	(void)argc;
	(void)argv;
	(void)status;
}
