#include "main.h"
/**
 * _strncpy - a function that copies a string.
 * @dest: Pointer to the destination buffer where characters will be copied.
 * @src:  Pointer to the source string from which characters will be copied.
 * @n:  Maximum number of characters to copy from src to dest.
 * Return: dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	char *ptr = dest;

	while (*src != '\0' && n > 0)
	{
		*ptr = *src;
		ptr++;
		src++;
		n--;
	}
	while (n > 0)
	{
		*ptr = '\0';
		ptr++;
		n--;
	}
	return (dest);
}
