#include "main.h"
#include "stddef.h"
#include "unistd.h"
/**
 * _printf - main function
 * 
 *
 *
 * Return: 0
 */
int _printf(const char *format, ...)
{
	int char_print = 0;
	va_list list_of_args;

	if(format == NULL)
		return (-1);


	va_start(list_of_args, format);

	while (*format)
	{
	       if(*format != '%')
	       {
		       write(1, format, 1);
		       char_print++;
	       }

	else
	{
		format++;
		if(*format == '\0')
			break;
		
		if(*format == '%')
		{
			write(1, format, 1);
			char_print++;
		}
		else if (*format == 'c')
		{
			char c = va_arg(list_of_args, int);
			write(1, &c, 1);
			char_print++;
		}
		else if (*format == 's')
		{
			char *str = va_arg(list_of_args, char*);
			int str_len = 0;
			
			while (str[str_len] != '\0')
				str_len++;

			write(1, str, str_len);
			char_print += str_len;
		}
	}

	format++;
	}
	va_end(list_of_args);

	return char_print;
}
