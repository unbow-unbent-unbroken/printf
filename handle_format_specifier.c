#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * handle_format_specifier - Handle conversion specifiers
 * @specifier: The conversion specifier character
 * @args: The va_list of arguments
 *
 * Return: Number of characters printed for this specifier
 */

int handle_format_specifier(char specifier, va_list args)
{
	char buffer[2] = {'\0', '\0'};
	int char_count = 0;

	switch (specifier)
	{
		case 'c':
			buffer[0] = va_arg(args, int);
			break;
		case 's':
			buffer[0] = va_arg(args, char *);
			break;
		case '%':
			buffer[0] = '%';
			break;
		case 'd':
		case 'i':
			/* Handle integer specifier */
			int n = va_arg(args, int);

			char_count += print_int(n);

			break;
		default:
			/* Handle unknown specifier or error */
			write(1, "%", 1); /* Print '%' if unknown specifier */
			write(1, &specifier, 1); /* Print the unknown specifier */
			char_count += 2; /* Two characters printed */
	}

	if (buffer[0] != '\0')
	{
		write(1, buffer, 1);
		char_count++;
	}

	return (char_count);
}
