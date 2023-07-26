#include "main.h"

/**
 *print_env- prints the environmental variable using environ
 *Return: 0 - success
 */

int print_env(void)
{
int i = 0, j = 0;

while (environ[i] != NULL)
{
j = 0;
while (environ[i][j] != '\0')
{
if (_putchar(environ[i][j]))
j++;
else
perror("Error printing variable");
}
_putchar('\n');
i++;

}
return (0);
}
