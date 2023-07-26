#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
extern char **environ;
int _putchar(char c);
void print_prompt(void);
char *read_input(void);
char **tokenize_args(char *lineptr);
#endif
