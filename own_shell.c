#include "holberton.h"
/**
 * own_shell - Simple Shell
 *
 * Description: Own Simple Shell
 * Return: void
 */
void own_shell(void)
{
	char *input_buff;
	char **args;
	int status = 1;
	size_t buffer_size = BUFFERSIZE;

	
/*
	if (isatty(STDIN_FILENO) == 0)
	{
		prompt(input_buff);
		execution_line(parse_line(input_buff, args));
		exit(0);
	}
*/
	while (status)
	{
		input_buff = malloc(sizeof(char*) * buffer_size);
		args = malloc(sizeof(args) * buffer_size);

		if (input_buff == NULL || args == NULL)
		{
			write(STDERR_FILENO, "Error assign memory\n", 50);
			free(input_buff);
			free(args);
			exit(0);
		}

		write(STDOUT_FILENO, "$ ", 2);

		prompt(input_buff);
		parse_line(input_buff, args);
		status = execution_line(args);

		free(input_buff);
		free(args);
	}
}
