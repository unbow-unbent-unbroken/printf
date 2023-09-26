#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * print_char - Print a character.
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_str - Print a string.
 */
int print_str(char *str)
{
	if (str)
	return (write(1, str, strlen(str)));
	return (write(1, "(null)", 6));
}

/**
 * print_int - Print an integer.
 */
int print_int(int n)
{
	char buffer[12];

	snprintf(buffer, sizeof(buffer), "%d", n);
	return (write(1, buffer, strlen(buffer)));
}

/**
 * handle_format - Handle a format specifier.
 */
int handle_format(va_list args, char format)
{
	if (format == 'c')
	{
		return (print_char(va_arg(args, int)));
	}
	else if (format == 's')
	{
		return (print_str(va_arg(args, char *)));
	}
	else if	(format == '%')
	{
		return (print_char('%'));
	}
	else if (format == 'd' || format == 'i')
	{
		return (print_int(va_arg(args, int)));
	}
	return (-1);
}

/**
 * _printf - Produces output according to a format.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (format && *format)
	{
		if (*format != '%')
		{
			count += write(1, format, 1);
			format++;
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				format--;
				count += write(1, "%", 1);
			}
			else
			{
				int result = handle_format(args, *format);

				if (result == -1)
				{
					count += write(1, "%", 1);
					count += write(1, format, 1);
				}
				else
				{
					count += result;
				}
			}
			format++;
		}
	}
	va_end(args);
	return (count);
}
