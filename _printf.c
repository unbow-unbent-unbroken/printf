#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a format and handles c, s and %
 * format: A character string containing zero or more directives.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char c;

	va_start(args, format);
	while (format && format[count])
	{
		if (format[count] != '%')
		{
			write(1, &format[count], 1);
			count++;
		}
		else
		{
			count++;
			c = format[count];
			if (c == 'c')
			{
				char char_arg = va_arg(args, int);

				write(1, &char_arg, 1);
			}
			else if (c == 's')
			{
				char *str_arg = va_arg(args, char *);

				if (str_arg)
				{
					while (*str_arg)
					{
						write(1, str_arg, 1);
						str_arg++;
					}
				}
				else
				{
					write(1, "(null)", 6);
				}
			}
			else if (c == '%')
			{
				write(1, "%", 1);
			}
			count++;
		}
	}

	va_end(args);
	return (count);
}
