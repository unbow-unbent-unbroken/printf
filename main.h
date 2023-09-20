#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);

int handle_format_specifier(char specifier, va_list args);

int print_int(int n);

/* functions of practice files are below here */
int _putchar(char c);

int handle_percent_c_s(const char *format, ...);

#endif /* MAIN_H */
