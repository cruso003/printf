#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
/**
 * handle_unsigned_int - Handling specifier for unsigned decimals.
 * @args: Argument list.
 * @count: Pointer to the counter.
 * Return: Count pointer.
 */
int handle_unsigned_int(va_list args, int *count)
{
	unsigned int num = va_arg(args, unsigned int);
	int i, j, len = 0;
	char buffer[BUFFER_SIZE], temp;

	if (num == 0)
	{
		buffer[0] = '0';
		len = 1;
	}
	else
	{
		while (num > 0)
		{
			buffer[len] = '0' + (num % 10);
			num /= 10;
			len++;
		}
	}
		for (i = 0, j = len - 1 ; i < j; i++, j--)
		{
			temp = buffer[i];
			buffer[i] = buffer[j];
			buffer[j] = temp;
		}
		for (i = 0; i < len; i++)
		{
			_putchar(buffer[i]);
			(*count)++;
		}
		return (*count);
}
/**
 * handle_octal - Handles specifier for octal notation.
 * @args: Argument list.
 * @count: A pointer to count.
 * Return: Pointer to count.
 */
int handle_octal(va_list args, int *count)
{
	unsigned int num = va_arg(args, unsigned int);
	char octal_str[BUFFER_SIZE];
	int index = 0;
	int i;

	do {
		octal_str[index++] = (num % 8) + '0';
		num /= 8;
	} while (num > 0);
	if (index == 0)
	{
		octal_str[index++] = '0';
	}
	for (i = index - 1; i >= 0; i--)
	{
		_putchar(octal_str[i]);
		(*count)++;
	}
	return (*count);
}
/**
 * handle_hexadecimal - Handles the specifier for printing
 * an integer in hexadecimal (base 16) notation.
 * @args: Argument list.
 * @count: Argument count.
 * @uppercase: Handle cases where the specifier is uppercase.
 * Return: Pointer to count.
 */
int handle_hexadecimal(va_list args, int *count, int uppercase)
{
	unsigned int num = va_arg(args, unsigned int);
	char hex_str[BUFFER_SIZE], temp;
	int len = 0, i, j;

	if (num == 0)
	{
		hex_str[0] = '0';
		len = 1;
	}
	else
	{
		while (num > 0)
		{
			if (uppercase)
			{
				hex_str[len] = "0123456789ABCDEF"[num % 16];
			}
			else
			{
				hex_str[len] = "0123456789abcdef"[num % 16];
			}
			num /= 16;
			len++;
		}
	}
	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		temp = hex_str[i];
		hex_str[i] = hex_str[j];
		hex_str[j] = temp;
	}
	for (i = 0; i < len; i++)
	{
		_putchar(hex_str[i]);
		(*count)++;
	}
	return (len);
}
