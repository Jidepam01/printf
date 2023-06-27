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
    char ch;

    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++;

            switch (format[i])
            {
                case 'd':
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
                    break;
                }
                case 'f':
                {
                    double value = va_arg(args, double);
                    int int_part = (int)value;
                    int decimal_part = (int)((value - int_part) * 1000000);

                    if (value < 0)
                    {
                        _putchar('-');
                        count++;
                        int_part = -int_part;
                        decimal_part = -decimal_part;
                    }

                    count += printf("%d.", int_part);
                    count += printf("%06d", decimal_part);
                    break;
                }
                case 'c':
                {
                    ch = (char)va_arg(args, int);
                    _putchar(ch);
                    count++;
                    break;
                }
                case 's':
                {
                    char *str = va_arg(args, char*);
                    int j = 0;
                    while (str[j] != '\0')
                    {
                        _putchar(str[j]);
                        count++;
                        j++;
                    }
                    break;
                }
                default:
                {
                    _putchar('%');
                    _putchar(format[i]);
                    count += 2;
                    break;
                }
            }
        }
        else
        {
            _putchar(format[i]);
            count++;
        }
    }

    va_end(args);
    return(count);
}
