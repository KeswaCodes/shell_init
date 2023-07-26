#include "main.h"
/* function tokenizes arguments */
char **tokenize_args(char *lineptr, int lineptr_len);

/* function prints a prompt*/
void print_prompt(void);

/*function reads input*/
char *read_input(void);

/**
 *main- simple shell by zinksw@gmail.com
 *@argc: argument count
 *@argv: array of arguments
 *Return: 1 - success, -1 failure
 */
int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
int i, status, process, k = 0;
char *lineptr = NULL, **env_var = environ, **args;

for (i = 0; ; i++)
{
print_prompt();
lineptr = read_input();
while (lineptr[k] != '\0')
k++;

k += 1;
args = tokenize_args(lineptr, k);
process = fork();
if (process == 0)
{
execve(args[0], args, env_var);
perror("./hsh");
free(args);
exit(EXIT_FAILURE);
}

else if (process > 0)
wait(&status);

else
return (-1);
}
free(lineptr);
return (0);
}
/**
 *print_prompt- prints a prompt "$ "
 *Return: void
 */
void print_prompt(void)
{
char *data = "$ ";

write(1, data, 3);
}
/**
 *read_input- reads input from stdin
 *Return: line read
 */
char *read_input(void)
{

char *lineptr = NULL;
size_t n = 0;
ssize_t input;

input = getline(&lineptr, &n, stdin);

if (input == -1)
return (NULL);

if (lineptr != NULL)
{
if (lineptr[input - 1] == '\n')
lineptr[input - 1] = '\0';
}
return (lineptr);
}
/**
 *tokenize_args- tokenizes the arguments
 *@lineptr: line read from stdin
 *@lineptr_len: length of the line read
 *Return: pointer to pointer of tokenized string
 */
char **tokenize_args(char *lineptr, int lineptr_len)
{
char **args, *tokens;
int j = 0;
/*malloc the space for the arguments*/
args = malloc(sizeof(char *) * lineptr_len);
if (args == NULL)
return (NULL);

/*tokenize arguments*/
tokens = strtok(lineptr, "");
while (tokens != NULL)
{
args[j] = tokens;
tokens = strtok(NULL, "");
j++;
}
args[j] = NULL;

return (args);
}
