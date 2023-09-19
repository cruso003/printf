#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * handle_bin - Handling specifier for binaries.
 * @args: Argument list.
 * Return: Count of characters written.
 */
int handle_bin(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int index = 0;
	char bin_digits[BUFFER_SIZE];
	int count = 0, i;

	while (num > 0)
	{
		bin_digits[index++] = (num % 2) + '0';
		num /= 2;
	}
	if (index == 0)
	{
		bin_digits[index++] = '0';
	}
	for (i = index - 1; i >= 0; i--)
	{
		_putchar(bin_digits[i]);
		count++;
	}
	return (count);
}
