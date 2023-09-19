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
 * @count: argument count
 * Return: len.
 */
int handle_string(va_list args, int *count)
{
	char *str = va_arg(args, char *);
	int len = 0;

	if (!str)
	{
		str = "(null)";
	}
	while (str[len] != '\0')
	{
		_putchar(str[len]);
		len++;
	{

	*count += len;
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
