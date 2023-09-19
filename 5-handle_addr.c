#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>

/**
 * handle_addr - handle specifier for printing memory address
 * @args: argument list
 * @count: argument count
 * Return: count
 */
int handle_addr(va_list args, int *count)
{
	uintptr_t addr = va_arg(args, uintptr_t);
	char addr_str[BUFFER_SIZE], hex_digit;
	int len = 0, i, digit;

	_putchar('0');
	_putchar('x');
	if (addr == 0)
	{
		_putchar('0');
		len += 3;
	}
	else
	{
		while (addr != 0)
		{
			digit = addr % 16;
			hex_digit = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
			addr_str[len] = hex_digit;
			addr /= 16;
			len++;
		}
		for (i = len - 1; i >= 0; i--)
		{
			_putchar(addr_str[i]);
		}
		len += 2;
	}
	*count += len;
	return (*count);
}
