#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed char*/

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int len = 0;   
    const char *p = format;  

    while (*p != '\0') {
        if (*p == '%') {
            p++i;
            if (*p == '\0') {
                break;  
            }

            if (*p == '%') {
                putchar('%');
                len++;
            } else if (*p == 'c') { 
                char c = va_arg(args, int);
                putchar(c);
                len++;
            } else if (*p == 's') {
              
                char *str = va_arg(args, char*);
                while (*str != '\0') {
                    putchar(*str);
                    str++;
                    len++;
                }
            } else {
                putchar('%');
                putchar(*p);
                len += 2;
            }
        } else {
            putchar(*p);
            len++;
        }
        
        p++;
    }

    va_end(args);
    return len;
}

