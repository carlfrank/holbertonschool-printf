#ifdef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - formated output functions.
 * @format: character string
 * Return: the number of character
 */

int _print(const char *format, ...);

int print_char(char c);
int print_str(char *s);
int print_interger(int num);

#endif
