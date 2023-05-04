#include "includes/minishell.h"

int ft_attach_node(t_env *end_node, char *source)
{
	t_env *new_node;

	new_node = malloc(sizeof(t_env));
    new_node->env_variable = malloc(strlen(source));
	if(!strcpy(new_node->env_variable, source))
		return(-1);
	end_node->next_pointer = new_node;
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

int	get_environment(t_msh *minishell, char **env)
{
	int	status;
	t_env *current_variable;
	int i;

	status = 1;
	i = 0;
	
	current_variable = malloc(sizeof(t_env));
    current_variable->env_variable = malloc(strlen(env[i]));
	strcpy(current_variable->env_variable, env[i++]);
	minishell->environment_list = current_variable;
	while(env[i])
	{
		status = ft_attach_node(current_variable, env[i++]);
		if(status == -1)
            return(-1);
		current_variable = current_variable->next_pointer;
	}
	return(1);
}