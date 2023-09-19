#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * handle_format_specifier - Handles a specific format specifier character.
 * @format_char: The format specifier character(e.g., 'c', 's', 'd', etc.).
 * @args: Argument list for the format specifier( va_list).
 * @count: A pointer to the count of characters written.
 * Return: The updated count.
 */
int handle_format_specifier(const char format_char, va_list args, int *count)
{
	switch (format_char)
	{
		case 'c':
			return (handle_char(args));
		case 's':
			return (handle_string(args));
		case '%':
			return (handle_percent());
		case 'd':
		case 'i':
			return (handle_int(args, count));
		case 'b':
			return (handle_bin(args, count));
		case 'u':
			return (handle_unsigned_int(args, count));
		case 'o':
			return (handle_octal(args, count));
		case 'x':
			return (handle_hexadecimal(args, count, 0));
		case 'X':
			return (handle_hexadecimal(args, count, 1));
		case 'S':
			return (handle_non_printable(args, count));
		case 'p':
			return (handle_addr(args, count));
		default:
			{
				_putchar('%');
				_putchar(format_char);
				*count += 2;
				return (*count);
			}
	}
}
/**
 * _printf - Custom printf that produces output according to a format.
 * @format: A character string containing format specifiers.
 * Return: Total count of characters written.
 */
int _printf(const char *format, ...)
{
	va_list args;
	unsigned int i;
	int count = 0;

	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			count += handle_format_specifier(format[i], args, &count);
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}
	va_end(args);
	return (count);
}
