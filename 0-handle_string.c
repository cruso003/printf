#include "main.h"
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
/**
 * handle_char - Helper function to write a character to stdout.
 * @args: The argument list.
 * Return: 1.
 */
int handle_char(va_list args)
{
	char _char = (char)va_arg(args, int);

	_putchar(_char);
	return (1);
}
/**
 * handle_string - Helper function to write a string to stdout.
 * @args: The argument list.
 * Return: len.
 */
int handle_string(va_list args)
{
	char *str = va_arg(args, char *);
	int len;
	int i;

	if (!str)
	{
		str = "(null)";
		len = _strlen(str);
		for (i = 0; i < len; i++)
		{
			_putchar(str[i]);
		}
	}
	else
	{
		len = _strlen(str);
		for (i = 0; i < len; i++)
		{
			_putchar(str[i]);
		}
	}
	return (len);
}
/**
 * handle_percent - Handles percent specifier
 * Return: 1.
*/
int handle_percent(void)
{
	_putchar('%');
	return (1);
}
