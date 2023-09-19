#include "monty.h"
/**
 * is_valid_integer - check number if integer or not
 * @str:string
 * Return:1 or 0
 */
int is_valid_integer(const char *str)
{
    if (*str == '\0')
        return (0);

    if (*str == '-' || *str == '+')
        str++;

    while (*str != '\0')
    {
        if (!_isdigit(str))  // Pass the string directly, not a single character
            return (0);
        str++;
    }

    return (1);
}

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 * Return: converted integer
 */
int _atoi(const char *s)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	if (s[0] == '-')
	{
		sign = -1;
		i++;
	}

	while (s[i] != '\0')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}

	return (sign * result);
}
/**
 * _isdigit - defines if string passed is a number
 *
 * @s: input string
 * Return: 1 if string is a number. 0 in other case.
 */
int _isdigit(const char *s)
{
    unsigned int i;

    for (i = 0; s[i]; i++)
    {
        if (s[i] < '0' || s[i] > '9')
            return (0);
    }
    return (1);
}
