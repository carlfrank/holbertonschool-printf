#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - printf function
 *
 * @format: formatted string
 * Return: The total number of outputted characters
 */
int _printf(const char *format, ...)
{
	int i, j, count = 0, find;
	va_list list;
	set arguments[] = {{'c', print_char}, {'%', print_percent}, {'s', print_str},
		{'i', print_int}, {'d', print_int}, {'0', NULL}};
	if (format == NULL)
		return (-1);
	va_start(list, format);
	for (i = 0; *(format + i); i++)
	{
		if (*(format + i) == '%')
		{
			if (*(format + i + 1) == '\0')
				return(-1);
			find = 0;
			for (j = 0; j < 6; j++)
			{
				if (*(format + i + 1) == arguments[j].spec)
				{
					count += arguments[j].print(list);
					find = 1;
					format++;
					break;
				}
			}
			if (find != 1)
			{
				count += write(1, (format + i), 1);
			}
		}
		else
			count += write(1, (format + i), 1);
	}
	va_end(list);
	return (count);
}
