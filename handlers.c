#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

const va_list list;
	set arguments[] = {
		{'c', print_char},
		{'%', print_percent},
		{'s', print_str},
/*		{'i', print_int_i},
		{'d', print_int_d},*/
		{'0', NULL}
	};

/**
 * print_char - prints out a character
 *
 * @list: A variable list of va_list type from stdarg.h
 * Return: 1
 */

int print_char(va_list list)
{
	char c;

	c = va_arg(list, int);

	if (c == '\0')
		return (0);
	write(1, &c, 1);
	return (1);
}

/**
 * print_str - prints string
 *0
 * @list: A variable list of type va_list of stdarg.h
 * Return: Int - Number of characters printed
 */

int print_str(va_list list)
{
	int count;
	char *s;

	s = va_arg(list, char*);

	if (*s == '\0')
		return (0);

	count = 0;

	while (*s)
	{
		count += write(1, s, 1);
		s++;
	}

	return (count);
}

/**
 * print_percent - print a percent sign
 * @args: arguments
 *
 * Return: Percent sign
 */
int print_percent(va_list args)
{
	(void)args;
	return (write(1, "%", 1));
}

 /**
 * print_anything - print any character
 * @args: arguments
 *
 * Return: arguments
 */

int print_anything(va_list args)
{
	int count = 0;
	const char *format = va_arg(args, const char *);

	count += write(1, "%", 1);

	if (*format == '%')
	{
		count += write(1, format, 1);
	}
	return (count);
}
 /**
 * print_int_d - prints an integer.
 *
 * @args: passed arguments.
 * Return: passed arguments.
 */

/*int print_int_d(va_list args)
{
int count = 0;

char num_str[12];
int len = 0, i, num = va_arg(args, int);

	if (num == 0)
	{
		write(1, "0", 1);
		count++;
	}

	if (num < 0 )
	{
		write(1, "-", 1);
		count++;
		num = -num;
	}
	else
	{
		while (num != 0)
		{
		num_str[len++] = num % 10 + '0';
		num /= 10;
		}

		for (i = len - 1; i >= 0; i++)
		{
		write(1, &num_str[i], i);
		count++;
		}
	}
return (count);
}

**
 *print_int_i -prints an integer.
 *
 * @args: passed arguments.
 * Return: passed arguments.
 *
int print_int_i(va_list args)
{
int count = 0;

char num_str[12];
int len = 0, i, num = va_arg(args, int);

	if (num == 0)
	{
		write(1, "0", 1);
		count++;
	}
	else
	{
		while (num != 0)
		{
		num_str[len++] = num % 10 + '0';
		num /= 10;
		}

		for (i = len - 1; i >= 0; i++)
		{
		write(1, &num_str[i], i);
		count++;
		}
	}
return (count);
}
*/
