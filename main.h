#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024

/**
 * struct FormatSpecifier - Format specifier character and its handler.
 * @specifier: The format specifier character (e.g., 'c', 's', 'd', etc.).
 * @handler: A pointer to the handler function.
 */
typedef struct FormatSpecifier
{
	char specifier;
	int (*handler)(va_list args);
} FormatSpecifier;

int _putchar(char c);
int _strlen(const char *str);
int _printf(const char *format, ...);
int handle_format_specifier(const char format_char, va_list args);
int handle_string(va_list args);
int handle_char(va_list args);
int handle_percent(va_list args);
int handle_d(va_list args);
int handle_i(va_list args);
int handle_bin(va_list args);
int handle_unsigned_int(va_list args);
int handle_octal(va_list args);
int handle_hex_lowercase(va_list args);
int handle_hex_uppercase(va_list args);
int handle_non_printable(va_list args);
int handle_addr(va_list args);
int handle_revs(va_list args);

#endif
