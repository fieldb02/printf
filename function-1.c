#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - produces output according to a format.
 * @format: a character string.
 *
 * Return: the number of characters printed (excluding the null byte used to
 * end output to strings).
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = (char) va_arg(args, int);

				printed_chars += write(1, &c, 1);
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				int len = 0;

				while (str[len])
					len++;
				printed_chars += write(1, str, len);
			}
			else if (*format == '%')
			{
				printed_chars += write(1, "%", 1);
			}
			else
			{
				printed_chars += write(1, "%", 1);
				printed_chars += write(1, &(*format), 1);
			}
		}
		else
		{
			printed_chars += write(1, &(*format), 1);
		}
		format++;
	}
	va_end(args);
	return (printed_chars);
}

