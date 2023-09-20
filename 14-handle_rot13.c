#include "main.h"
/**
 * handle_rot13 - Handle ROT13
 * @args: argument list
 * Return: count
 *
 */
int handle_rot13(va_list args)
{
	int i, j, count = 0;
	int c = 0;
	char *str = va_arg(args, char*);
	char alp[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char beta[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		c = 0;
		for (j = 0; alp[j] && !c; j++)
		{
			if (str[i] == alp[j])
			{
				_putchar(beta[j]);
				count++;
				c = 1;
			}
		}
		if (!c)
		{
			_putchar(str[i]);
			count++;
		}
	}
	return (count);
}