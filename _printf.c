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

    int count = 0;  /* Counter for characters printed*/

    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++;

            /* Handle format specifiers */
            if (format[i] == 'd')
            {
                int value = va_arg(args, int);
                count += printf("%d", value);
            }
            else if (format[i] == 'f')
            {
                double value = va_arg(args, double);
                count += printf("%f", value);
            }
            else if (format[i] == 'c')
            {
                int value = va_arg(args, int);
                count += printf("%c", value);
            }
            else if (format[i] == 's')
            {
                char* value = va_arg(args, char*);
                count += printf("%s", value);
            }
            else
            {
                putchar('%');
                putchar(format[i]);
                count += 2;
            }
        }
        else
        {
            putchar(format[i]);
            count++;
        }
    }

    va_end(args);
    return count;
}
