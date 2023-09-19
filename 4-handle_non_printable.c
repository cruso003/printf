#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * handle_non_printable - handles d specifier 4 non-profitable chars using %S
 * @args: argument list
 * @count: argument count
 * Return: argument count pointer
 */
int handle_non_printable(va_list args, int *count)
{
	char *input = va_arg(args, char *);
	int i;
	char current_char;

	for (i = 0; input[i] != '\0'; i++)
	{
		current_char = input[i];
		if (current_char < 32 || current_char >= 127)
		{
			_putchar('\\');
			_putchar('x');
			_putchar((current_char / 16) < 10 ?
					(current_char / 16) + '0' : (current_char / 16) - 10 + 'A');
			_putchar((current_char % 16) < 10 ?
					(current_char % 16) + '0' : (current_char % 16) - 10 + 'A');
			(*count) += 4;
		}
		else
		{
			_putchar(current_char);
			(*count) += 1;
		}
	}
	return (*count);
}
