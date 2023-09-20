#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>


/**
 * handle_d - Handle the %d specifier.
 * @args: Argument list.
 * Return: Count of characters written.
 */
int handle_d(va_list args);
int handle_d(va_list args)
{
	long num = va_arg(args, int);
	int i, j, len = 0, is_negative = 0, count = 0;
	char int_str[BUFFER_SIZE], temp;

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	if (num == 0)
	{
		int_str[0] = '0';
		len = 1;
	}
	else
	{
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
		count++;
	}
	return (count);
}

/**
 * handle_i - Handle the %i specifier.
 * @args: Argument list.
 * Return: Count of characters written.
 */
int handle_i(va_list args)
{
	return (handle_d(args));
}

