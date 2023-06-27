#include "main.h"
/**
 * _printf - a function that produces output according to a format.
 * @format: c, s, %
 * Return: count
 */
int _printf(const char* format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;

    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++;

            if (format[i] == 'd')
            {
                int value = va_arg(args, int);
                int num_digits = 0;
                int temp = value;

                if (temp < 0)
                {
                    _putchar('-');
                    count++;
                    temp = -temp;
                }

                while (temp != 0)
                {
                    num_digits++;
                    temp /= 10;
                }

                if (value == 0)
                {
                    _putchar('0');
                    count++;
                }

                while (value != 0)
                {
                    int digit = value % 10;
                    _putchar('0' + digit);
                    count++;
                    value /= 10;
                }

                count += num_digits;
            }
            else if (format[i] == 'f')
            {
                double value = va_arg(args, double);
                printf("%f", value);
                count++;
            }
            else if (format[i] == 'c')
            {
                int value = va_arg(args, int);
                _putchar(value);
                count++;
            }
            else if (format[i] == 's')
            {
                char* value = va_arg(args, char*);
                int j = 0;
                while (value[j] != '\0')
                {
                    _putchar(value[j]);
                    count++;
                    j++;
                }
            }
            else
            {
                _putchar('%');
                putchar(format[i]);
                count += 2;
            }
        }
        else
        {
            _putchar(format[i]);
            count++;
        }
    }

    va_end(args);
    return count;
}

