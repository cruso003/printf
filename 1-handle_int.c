#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * handle_int - handling integers specifiers d and i
 * @args: argument list
 * @count: integer pointer count.
 * Return: len
 */
int handle_int(va_list args, int *count)
{
	int num = va_arg(args, int), i, j, len = 0, is_negative;
	char int_str[BUFFER_SIZE], temp;

	if (num == 0)
	{
		int_str[0] = '0';
		len = 1;
	}
	else
	{
		is_negative = 0;
		if (num < 0)
		{
			is_negative = 1;
			num = -num;
		}
		while (num > 0)
		{
			int_str[len] = '0' + (num % 10);
			num /= 10;
			len++;
		}
		if (is_negative)
		{
			int_str[len] = '-';
			len++;
		}
		for (i = 0, j = len - 1; i < j; i++, j--)
		{
			temp = int_str[i];
			int_str[i] = int_str[j];
			int_str[j] = temp;
		}
	}
	for (i = 0; i < len; i++)
	{
		_putchar(int_str[i]);
		(*count)++;
	}
	return (len);
}
