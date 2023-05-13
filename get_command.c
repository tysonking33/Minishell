# include "includes/minishell.h"

void assign_type(t_token *node)
{
	//detect built ins --> type = 1;
	char *built_ins[8] = {"echo", "echo -n", "cd", "pwd", "export", "unset", "env", "exit"};
		int i;
	i = 0;
	while(built_ins[i]) {
		if (ft_strncmp(node->token_string, built_ins[i], ft_strlen(built_ins[i])) == 0) {
			node->type = BUILT_IN;
			break;
		}
		i++;
	}
	if (ft_strncmp(node->token_string, "", 1) == 0)
		node->type = EMPTY; // might not need this one
	else if (ft_strncmp(node->token_string, "<", 1) == 0)
		node->type = REDIR_INPUT;
	else if (ft_strncmp(node->token_string, ">", 1) == 0) //writes to file and deletes existing
		node->type = REDIR_TRUNCATE;
	else if (ft_strncmp(node->token_string, ">>", 1) == 0)
		node->type = REDIR_APPEND;
	else if (ft_strncmp(node->token_string, "|", 1) == 0)
		node->type = PIPE;
	else if (ft_strncmp(node->token_string, ";", 1) == 0)
		node->type = END_LINE;
	else
		node->type = UNKNOWN;
	
	// might need some more here such as determining if something is an arg or a cmd
}

int ft_attach_command_token(t_token *end_node, char *str_command)
{
	t_token *new_node;

	new_node = malloc(sizeof(t_token));
    new_node->token_string = malloc(ft_strlen(str_command));
	if(!ft_strlcpy(new_node->token_string, str_command, ft_strlen(str_command)))
		return(-1);
    assign_type(new_node);
	new_node->prev = end_node;
	end_node->next = new_node;
	return(1);
}

/* test function to print environment */
void print_cmd(t_msh *minishell)
{
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
	add_history(command);
	//if(ft_strlen(command) == 0)
	//	return(1);
	if(command == NULL || command[0] == '\0')
		return(1);
	char **indiv_comms = ft_split(command, ' ');
	t_token *current_token; 										//declare and make first token
	current_token = malloc(sizeof(t_token));						//allocate memory
	current_token->token_string = malloc(ft_strlen(indiv_comms[i]));
	ft_strlcpy(current_token->token_string, indiv_comms[i], ft_strlen(indiv_comms[i])); //fill token_string
	i++;
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