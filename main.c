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

# include "includes/minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

void assign_type(t_token *node){
    if (strcmp(node->token_string, "cd") == 0 || strcmp(node->token_string, "pwd") == 0){
        node->type = 1;
    }
    else if (strcmp(node->token_string, "vim") == 0 || strcmp(node->token_string, "nano") == 0
        || strcmp(node->token_string, "cat") == 0 || strcmp(node->token_string, "touch") == 0){
        node->type = 2;
    }
    else if ((strcmp(node->token_string, "ls") == 0)){
        node->type = 2;
    }
}

int ft_attach_command_token(t_token *end_node, char *str_command)
{
	t_token *new_node;

	new_node = malloc(sizeof(t_token));
    new_node->token_string = malloc(strlen(str_command));
	if(!strcpy(new_node->token_string, str_command))
		return(-1);
    assign_type(new_node);
	end_node->next = new_node;
	return(1);
}

/* test function to print environment */
void print_cmd(t_msh *minishell){
    t_token *current_variable = minishell->token_list;

    while (1){
        ft_printf("%s	type: %d\n", current_variable->token_string, current_variable->type);
		if (current_variable->next)
        	current_variable = current_variable->next;
		else
			break;
    }
}

int get_commands(t_msh *minishell, FILE* stdin)
{
    int i = 0;
    int status = 1;

    char *command  = readline("$ ");
	if(strlen(command) == 0)
		return(1);
    char **indiv_comms = ft_split(command, ' ');

    t_token *current_token; 										//assign first token
    current_token = malloc(sizeof(t_token));						//allocate memory
    current_token->token_string = malloc(strlen(indiv_comms[i]));
    strcpy(current_token->token_string, indiv_comms[i++]);
	assign_type(current_token);
    minishell->token_list = current_token;							//put into minishell struct

    while (indiv_comms[i]){
		status = ft_attach_command_token(current_token, indiv_comms[i++]);
		if(status == -1)
            return(-1);
		current_token = current_token->next;
	}
	current_token->next = NULL; 									//on the last one set the next pointer to NULL
	return(1);
}

int	main(int argc, char **argv, char **env)
{
	t_msh	minishell;
	int status;

	status = 1;
	status = get_environment(&minishell, env);
	while(status)
	{
		status = get_commands(&minishell, stdin);
		print_env(&minishell);
		print_cmd(&minishell);
		//status = execute(minishell);

	}
	(void)argc;
	(void)argv;
	(void)status;
}
