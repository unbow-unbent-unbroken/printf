#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);

int _putchar(char c);

int handle_percent_c_s(const char *format, ...);

#endif /* MAIN_H */
