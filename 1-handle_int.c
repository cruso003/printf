#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * handle_d - Handle the %d specifier.
 * @args: Argument list.
 * Return: Count of characters written.
 */
int handle_d(va_list args)
{
	int n = va_arg(args, int);
	int num, last_digit = n % 10, digit, mag = 1;
	int count = 1;

	n /= 10;
	num = n;
	if (last_digit < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last_digit = -last_digit;
		count++;
	}
	if (num == 0)
	{
		while (num / 10 != 0)
		{
			mag *= 10;
			num /= 10;
		}
		num = n;
		while (mag > 0)
		{
			digit = num / mag;
			_putchar(digit + '0');
			num -= (digit * mag);
			mag /= 10;
			count;
		}
	}
	_putchar(last_digit + '0');
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
