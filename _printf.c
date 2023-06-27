#include "main.h"
/**
 * _printf - a function that produces output according to a format.
 * @format: c, s, %
 * Return: count
 */
int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int count = 0;

	while (*format != '\0') {
        if (*format == '%') {
            format++;
              switch (*format) {
                case 'c': {
                    char c = (char) va_arg(args, int);
                    _putchar(c);
                    count++;
                    break;
                }
                case 's': {
                    char *s = va_arg(args, char *);
                    while (*s != '\0') {
                        _putchar(*s);
                        s++;
                        count++;
                    }
                    break;
                }
                case '%':
                    _putchar('%');
                    count++;
                    break;
            }
        } else {
            _putchar(*format);
            count++;
        }
        format++;
    }
    va_end(args);
    return count;
}

