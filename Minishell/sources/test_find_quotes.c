#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h> //readline
#include <readline/history.h>   //readline
#include <stdlib.h>             //malloc
#include <sys/wait.h>            //wait

/* if single or double quotes are found and fully complete, return 1 */
/* if single or double quotes are found and incomplete, return 2 */
/* if single or double quotes are not found, return 3 */
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
    if ((count_double_quote % 2 == 0) && (count_single_quote % 2 == 0)){
        return 1;
    }
    if ((count_double_quote % 2 != 0) || (count_single_quote % 2 != 0)){
        return 2;
    }

    return 3;
}


int main(){
    {
        char *src = " \" abd \" ";
        printf("src: %s", src);
        if (find_quotes(src) == 1){
            printf("✓\n");
        }
        else{
            printf("X\n");
        }
    }
    {
        char *src = " abd \" ";
        printf("src: %s", src);
        if (find_quotes(src) == 2){
            printf("✓\n");
        }
        else{
            printf("X\n");
        }
    }
    {
        char *src = " \" abd ";
        printf("src: %s", src);
        if (find_quotes(src) == 2){
            printf("✓\n");
        }
        else{
            printf("X\n");
        }
    }
    {
        char *src = " \" abd \' ";
        printf("src: %s", src);
        if (find_quotes(src) == 2){
            printf("✓\n");
        }
        else{
            printf("X\n");
        }
    }
    {
        char *src = " \' abd \" ";
        printf("src: %s", src);
        if (find_quotes(src) == 2){
            printf("✓\n");
        }
        else{
            printf("X\n");
        }
    }
    {
        char *src = "abd ";
        printf("src: %s", src);
        if (find_quotes(src) == 3){
            printf("✓\n");
        }
        else{
            printf("X\n");
        }
    }
    return 0;
}
