#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: The format string
 * @...: Variable number of arguments
 *
 * Return: Number of characters printed (excluding null byte)
 */

int _printf(const char *format, ...)
{
	va_list args;
	int char_count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++; /* Move past '%' */
			char_count += handle_format_specifier(*format, args);
		}
		else
		{
			write(1, format, 1); /* Print non-% character */
			char_count++;
		}
		format++; /* Move to the next character */
	}

	va_end(args);
	return (char_count);
}
