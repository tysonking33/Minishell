#include "../includes/Minishell.h"

/* find the next start of the next argument*/
int nextStart(char *src, int currentStart)
{
	int nextStart = currentStart + 1;
	while (src[nextStart] && src[nextStart] != ' ' && src[nextStart] != '\n')
	{
		nextStart++;
	}
	return nextStart;
}

/* get the current argument */
char *wordDup(char *src, int startidx)
{
	char *dest = (char *)malloc(ft_strlen(src) * sizeof(char *));
	int i = startidx;
	int dest_counter = 0;
	while (src[i] != ' ' && src[i] != '\n' && src[i])
	{
		dest[dest_counter] = src[i];
		//printf("dest[%d]: %c, src[%d]: %c\n", dest_counter, dest[dest_counter], i, src[i]);
		i++;
		dest_counter++;
	}
	dest[dest_counter] = '\0';
	//printf("dest: %s\n", dest);
	return dest;
}

/* split the whole string into arguments*/
char		**ft_split_string(char *src)
{
	int argument_count;

	argument_count = argCount(src);
	//printf("arguement_count = %d\n", argument_count);

	char **splitString = (char **)malloc((argument_count + 1) * sizeof(char **));
	int i = 0;
	while (i < argument_count + 1)
	{
		splitString[i] = (char *)malloc(1000 * sizeof(char *));
		//printf("splitString[%d]: %s", i, splitString[i]);
		i++;
	}
	int currentStartIdx = 0;
	int current_argument = 0;
	while (current_argument < (argument_count))
	{
		printf("currentStartIdx: %d\n", currentStartIdx);
		splitString[current_argument] = wordDup(src, currentStartIdx);
		currentStartIdx = nextStart(src, currentStartIdx)+1;
		current_argument++;
	}
	splitString[current_argument] = NULL;


	i = 0;
	while (i < (argument_count +1)){
		printf("splitString[%d]: %s\n", i, splitString[i]);
		i++;
	}
	return splitString;
}
