#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_int - Print an integer
 * @n: The integer to print
 *
 * Return: Number of characters printed
 */

int print_int(int n)
{
	char buffer[12]; /* Buffer to store integer as string */
	int char_count = 0;

	if (n < 0)
	{
		write(1, "-", 1); /* Print minus sign for negative numbers */
		char_count++;
		n = -n; /* Make n positive */
	}

    /* Convert integer to string */
	int len = snprintf(buffer, sizeof(buffer), "%d", n);

	if (len >= 0)
	{
		write(1, buffer, len);
		char_count += len;
	}

	return (char_count);
}
