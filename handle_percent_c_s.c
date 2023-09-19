#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * handle_percent_c_s - Handle the specifier
 * @format: The format string containing directives.
 *
 * Return: The number of characters printed (excluding the null byte).
 */

int handle_percent_c_s(const char *format, ...)
{
	va_list(args);
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++; /* Move past '%' */

			switch (*format)
			{
			case 'c':
				{
					char character = va_arg(args, int);
					putchar(character);
					count++;
				}
				break;
			case 's':
				{
					char *str = va_arg(args, char *);
					while (*str)
					{
						putchar(*str);
						str++;
						ount++;
					}
				}
				break;
			case '%':
				{
					putchar('%');
					count++;
				}
				break;
			default:
				putchar('%');
				putchar(*format);
				count += 2;
				break;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}

	return (count);
}

/**
 * _printf - Produces output according to a format.
 * @format: The format string containing directives.
 *
 * Return: The number of characters printed (excluding the null byte).
 */

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int count = 0;  /* To keep track of the number of characters printed */

	count += handle_percent_c_s(format, args);  /* Call the first person's function */
	count += handle_d_and_i(format, args);      /* Call the second person's function */

	va_end(args);
	return (count);
}
