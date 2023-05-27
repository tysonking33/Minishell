#include "../includes/Minishell.h"

/* if single are found and fully complete, return 1 */
/* if double are found and fully complete, return 2 */

/* if single or double quotes are found and incomplete, return 3 */
/* if single or double quotes are not found, return 4 */
int find_quotes(char *src){
    int i = 0;

    int count_single_quote = 0;
    int count_double_quote = 0;

    while (src[i]){
        if (src[i] == 34){
            count_double_quote++;
        }
        else if (src[i] == 39){
            count_single_quote++;
        }
        i++;
    }
    if ((count_double_quote == 0) && (count_single_quote == 0)){
        return 3;
    }
    if ((count_double_quote % 2 == 0) || (count_single_quote % 2 == 0)){
        return 1;
    }
    if ((count_double_quote % 2 != 0) || (count_single_quote % 2 != 0)){
        return 2;
    }
    return 3;
}