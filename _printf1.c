#include "main.h"

/**
 * handle_d_i - Handle the 'd' and 'i' conversion specifiers.
 * @args: The va_list containing the integer to print.
 *
 * Return: The number of characters printed.
 */
int handle_d_i(va_list args)
{
	int n = va_arg(args, int);
	char buffer[12];

	snprintf(buffer, sizeof(buffer), "%d", n);
	return (write(1, buffer, strlen(buffer)));
}
