#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * handle_bin - Handling specifier for binaries.
 * @args: Argument list.
 * @count: Integer count.
 * Return: A pointer to the count.
 */
int handle_bin(va_list args, int *count)
{
	unsigned int num = va_arg(args, unsigned int);
	int index = 0;
	int i;
	char bin_digits[BUFFER_SIZE];

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
		(*count) += 1;
	}
	return (*count);
}
