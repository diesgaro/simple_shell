#ifndef HEADERS
#define HEADERS

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define BUFFERSIZE 1024

char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *_strcpy(char *dest, char *src);
char *_strdup(char *src);
int _strlen(char *str);

void prompt(char *buffer);
void own_shell(char **env);
char **parse_line(char *buffer);
int execution_line(char **args, char *buffer);
int process_path(char **args, char **env);
void insert_path(char *in_path, char *arg);
void enviroment(char **env);
int built_commands(char **args, char *buffer, char **env);
void get_value_enviroment(char **env, char *path_line, char *name_var);

#endif /* HEADERS */
