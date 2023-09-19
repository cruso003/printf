#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Macro: WRITE_CHAR(c, count)
 * Description: Writes a single char 'c' to stdout & increments d 'count' variable
 * Parameters:
 * c - The character to write.
 *   count - A pointer to the count of characters written.
 * Usage:
 *   WRITE_CHAR('A', char_count);
 */
#define WRITE_CHAR(c, count) do { _putchar(c); (*(count))++; } while (0)

/* 
 * Macro: WRITE_STRING(s, len, count)
 * Description: Writes a string 's' of length 'len' to stdout and updates the 'count' variable.
 * Parameters:
 *   s - The string to write.
 *   len - The length of the string.
 *   count - A pointer to the count of characters written.
 * Usage:
 *   char *message = "Hello, World!";
 *   int length = strlen(message);
 *   WRITE_STRING(message, length, char_count);
 */
#define WRITE_STRING(s, len, count) do { write(1, s, len); (*(count)) += len; } while (0)

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
