#ifndef HEADERS
#define HEADERS

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFERSIZE 1024

void prompt(char *buffer);
void own_shell(void);
char **parse_line(char *buffer);
int execution_line(char **args);

#endif /* HEADERS */
