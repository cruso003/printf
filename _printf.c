#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * handle_format_specifier - Handles a specific format specifier character.
 * @format_char: The format specifier character(e.g., 'c', 's', 'd', etc.).
 * @args: Argument list for the format specifier( va_list).
 * Return: 1.
 */
int handle_format_specifier(const char format_char, va_list args)
{
	FormatSpecifier formatSpecifiers[] = {
		{'c', handle_char},
		{'s', handle_string},
		{'d', handle_d},
		{'i', handle_i},
		{'b', handle_bin},
		{'u', handle_unsigned_int},
		{'o', handle_octal},
		{'x', handle_hex_lowercase},
		{'X', handle_hex_uppercase},
		{'S', handle_non_printable},
		{'p', handle_addr},
		{'r', handle_revs},
		{'R', handle_rot13},
	};
	size_t i;

	for (i = 0; i < sizeof(formatSpecifiers) / sizeof(formatSpecifiers[0]); i++)
	{
		if (formatSpecifiers[i].specifier == format_char)
		{
			return (formatSpecifiers[i].handler(args));
		}
	}
	_putchar('%');
	_putchar(format_char);
	return (2);
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
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if ((!format[2] && format[0] == '%' && format[1] == ' '))
		return (-1);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}
			if (format[i] == '%')
			{
				_putchar('%');
				count++;
			}
			else
			{
				count += handle_format_specifier(format[i], args);
			}
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
