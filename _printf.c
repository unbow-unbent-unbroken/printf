#include "main.h"
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h> // Added for snprintf

/**
 * print_char - Print a character.
 * @c: The character to print.
 *
 * Return: The number of characters printed (always 1).
 */
int print_char(char c)
{
    return write(1, &c, 1);
}

/**
 * print_str - Print a string.
 * @str: The string to print.
 *
 * Return: The number of characters printed.
 */
int print_str(char *str)
{
    if (!str)
        str = "(null)";
    return write(1, str, strlen(str));
}

/**
 * print_int - Print an integer.
 * @n: The integer to print.
 *
 * Return: The number of characters printed.
 */
int print_int(int n)
{
    char buffer[12]; // Assumes a maximum of 11 digits for an int
    snprintf(buffer, sizeof(buffer), "%d", n);
    return write(1, buffer, strlen(buffer));
}

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing zero or more directives.
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
            count += print_char(format[count]);
        }
        else
        {
            count++;
            c = format[count];
            if (c == 'c')
                count += print_char(va_arg(args, int));
            else if (c == 's')
                count += print_str(va_arg(args, char *));
            else if (c == '%')
                count += print_char('%');
            else if (c == 'd' || c == 'i')
                count += print_int(va_arg(args, int));
            count++;
        }
    }

    va_end(args);
    return count;
}
