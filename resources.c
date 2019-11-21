/**
 * _strcat - concatenates two strings
 * @src: first string
 * @dest: second string
 *
 * Description: function that concatenates two strings
 * Return: poninter with dest
 */

char *_strcat(char *dest, char *src)
{
	int dest_len = 0, i = 0;

	while (dest[dest_len] != '\0')
		dest_len++;

	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		if (src[i + 1] == '\0')
			dest[dest_len + i + 1] = src[i + 1];
		i++;
	}

	return (dest);
}

/**
 * _strcmp -  compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Description: function that compares two strings
 * Return: integer
 */

int _strcmp(char *s1, char *s2)
{
	int compare = 0, i = 0;

	while (s1[i] != '\0' || s2[i] != '\0')
	{
		compare = s1[i] - s2[i];
		if (s1[i] != s2[i])
			break;

		i++;
	}

	return (compare);
}

/**
 * _strcpy -  copies the string pointed to by src
 * @dest: destination char
 * @src: origin char
 *
 * Description:  function that copies the string pointed to by src
 * Return: dest
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	return (dest);
}
