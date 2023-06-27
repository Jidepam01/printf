#define MAIN_H

int _printf(const char *format, ...);
int _putchar(char c);

int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

int print_percent(va_list types, char buffer[],int flags, int width, int precision, int size);

UNUSED(types);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size);

int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size);

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);


#endif
