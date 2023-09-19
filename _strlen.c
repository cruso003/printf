#include "main.h"
/**
 * _strlen - Returns the length of a string.
 * @str: A pointer to type char.
 * Return: len (short for lenght).
 */
int _strlen(const char *str)
{
	int len;

	for (len = 0; str[len] != '\0'; len++)
		;
	return (len);
}

