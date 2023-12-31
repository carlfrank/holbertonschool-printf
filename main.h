#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>



/**
 * struct Set - A specifier - function pair
 * @spec: Char - the format specifier
 * @print: Special function implemented to print data of a given
 * specifier to stdout
 *
 * Description: A specifier - function pair
 */
typedef struct Set
{
	char spec;
	int (*print)(va_list arg);
} set;

int print_int(va_list list);
int print_int(va_list list);
int print_percent(va_list list);
int print_str(va_list list);
int print_char(va_list list);
int _printf(const char*, ...);
int _putchar(char c);
int print_anything(va_list list);

#endif
