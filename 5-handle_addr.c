#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>

/**
 * handle_addr - Handle specifier for printing memory address.
 * @args: Argument list.
 * Return: Count of characters written.
 */
int handle_addr(va_list args)
{
	uintptr_t addr = va_arg(args, uintptr_t);
	char addr_str[BUFFER_SIZE], hex_digit;
	int length = 0, digit, i;
	int count = 0;

	if (addr == 0)
	{
		_putchar('0');
		_putchar('x');
		_putchar('0');
		return (3);
	}
	while (addr != 0)
	{
		digit = addr % 16;
		hex_digit = (digit < 10) ? ('0' + digit)
		: ('a' + digit - 10);
		addr_str[length] = hex_digit;
		addr /= 16;
		length++;
	}
	_putchar('0');
	_putchar('x');
	for (i = length - 1; i >= 0; i--)
	{
		_putchar(addr_str[i]);
		count++;
	}
	return (count + 2);
}
