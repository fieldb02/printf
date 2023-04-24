#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					{
					char c = va_arg(args, int);

					putchar(c);
					count++;
					break;
					}
				case 's':
					{
					char *s = va_arg(args, char *);

					fputs(s, stdout);
					count += strlen(s);
					break;
					}
				case 'd':
				case 'i':
					{
					int d = va_arg(args, int);

					printf("%d", d);
					count += snprintf(NULL, 0, "%d", d);
					break;
					}
				case '%':
					{
					putchar('%');
					count++;
					break;
					}
				default:
					break;
			}
			else
			{
				putchar(*format);
				count++;
			}
			format++;
		}
		va_end(args);
		return (count);
	}
}
