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
 * Return: length.
 */
int handle_string(va_list args)
{
	char *str = va_arg(args, char *);
	int length;
	int i;

	if (!str)
	{
		str = "(null)";
		length = _strlen(str);
		for (i = 0; i < length; i++)
		{
			_putchar(str[i]);
		}
		return (length);
	}
	else
	{
		length = _strlen(str);
		for (i = 0; i < length; i++)
		{
			_putchar(str[i]);
		}
	}
	return (length);
}
/**
 * handle_percent - Handles percent specifier
 * @args: void argument
 * Return: 1.
*/
int handle_percent(va_list args)
{
	(void)args;

	_putchar('%');
	return (1);
}
