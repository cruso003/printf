#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int _putchar(char c);
int _strlen(const char *str);
int handle_percent(void);
int _printf(const char *format, ...);
int handle_format_specifier(const char format_char, va_list args, int *count);
int handle_string(va_list args);
int handle_char(va_list args);
int handle_int(va_list args, int *count);
int handle_bin(va_list args, int *count);
int handle_unsigned_int(va_list args, int *count);
int handle_octal(va_list args, int *count);
int handle_hexadecimal(va_list args, int *count, int uppercase);
int handle_non_printable(va_list args, int *count);
int handle_addr(va_list args, int *count);

#endif
