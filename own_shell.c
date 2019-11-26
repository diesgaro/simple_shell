#include "holberton.h"
/**
 * enviroment - print the enviroment variables
 * @env: enviroment variables
 *
 * Description: print the enviroment variables in simple shell
 * Return: void
 */
void enviroment(char **env)
{
        int env_i = 0;

        while (env[env_i] != NULL)
        {
		write(STDOUT_FILENO, env[env_i], _strlen(env[env_i]));
		write(STDOUT_FILENO, "\n", 1);
                env_i++;
        }
}


/**
 * own_shell - Simple Shell
 *
 * Description: Own Simple Shell
 *
 * Return: void
 */
void own_shell(char **env)
{
	char *input_buff;
	char **args;
	int status = 1, compare;
	struct stat stat_var;

	while (status)
	{
		input_buff = malloc(sizeof(input_buff) * BUFFERSIZE);

		if (input_buff == NULL)
		{
			write(STDERR_FILENO, "Error assign memory\n", 50);
			free(input_buff);
			exit(EXIT_FAILURE);
		}

		prompt(input_buff);
		args = parse_line(input_buff);

		compare = _strcmp(args[0], "env");
		if (compare == 0)
			enviroment(env);

		compare = _strcmp(args[0], "exit");
		if (compare == 0)
		{
			free(input_buff);
			free(args);
			exit(0);
		}

		if (stat(args[0], &stat_var) == -1)
		{
			if (process_path(args, env) == -1)
			{
				free(input_buff);
				free(args);
				exit(EXIT_FAILURE);
			}
		}

		status = execution_line(args, input_buff);

		/*if (isatty(!STDIN_FILENO))
		  exit(0);*/

	}
}
