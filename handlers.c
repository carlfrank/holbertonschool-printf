#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

const va_list list;
	set arguments[] = {
		{'c', print_char},
		{'%', print_percent},
		{'s', print_str},
		{'i', print_int},
		{'d', print_int},
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
 *
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
 * print_int - prints an integers.
 *
 * @args: passed arguments.
 * Return: passed arguments.
 */

int print_int(va_list args)
{
	int number = va_arg(args, int);
	unsigned int absolute_value;
	char digit;
	int exponent = 1;
	int lenght = 0;

	if (number < 0)
	{
		digit = '-';
		lenght = lenght + write(1, &digit, 1);
		absolute_value = number * -1;
	}

	else
		absolute_value = number;

	while (absolute_value / exponent > 9)
	{
		exponent *= 10;
	}

	while (exponent != 0)
	{
		digit = absolute_value / exponent + '0';
		lenght = lenght + write(1, &digit, 1);
		absolute_value = absolute_value % exponent;
		exponent = exponent / 10;
	}
	return (lenght);
}
