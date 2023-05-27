#include "../includes/Minishell.h"

/* implementation of the cd command. It changes the current directory*/
int execute_cd(char **parsed_commands) {
	if (parsed_commands[1] == NULL) {
			// No argument provided, change to the home directory
			const char *home_dir = getenv("HOME");
			if (home_dir == NULL) {
					// Home directory not found
					printf("cd: No home directory\n");
					return(0);
			}
			if (chdir(home_dir) != 0) {
					// Failed to change directory
					perror("cd");
			}
	} else {
			// Change to the specified directory
			if (chdir(parsed_commands[1]) != 0) {
					// Failed to change directory
					perror("cd");
					return(-1);
			}
	}
	return(1);
}