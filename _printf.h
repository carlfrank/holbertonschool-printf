#ifndef _printf_h
#define _printf_h
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/**
 */

typedef struct format
{
	char *opt;
	int (*call_fun)();
} format_t;

int _printf(const char *format, ...);
