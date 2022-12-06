#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int count = 0;

void ft_printnum(long num)
{
	char st[] = "0123456789";
	if (num > 10)
		ft_printnum(num / 10);
	count += write(1, &st[num % 10], 1);	
	// printf("num len: %d", count);
}
void ft_printhex(unsigned num)
{
	char st[] = "0123456789abcdef";
	if (num >= 16)
		ft_printhex(num / 16);
	count += write(1, &st[num % 16], 1);	
}
int ft_printf(const char *str, ...)
{
	count = 0;
	int len = 0;
	va_list arg;
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 's')
			{
				char *save = va_arg(arg, char *);
				if (!save)
					save = "(null)";
				while (save[len])
					len++;
				count += len;
				write(1, save, len);
				len  = 0;
			}
			else if (*str == 'd')
			{
				long num = va_arg(arg, int);
				if (num < 0)
				{
					write(1, "-", 1);
					count++;
					num = -num;
				}
				ft_printnum(num);
			}
			else if (*str == 'x')
			{
				int num = va_arg(arg, int);
				ft_printhex(num);
			}
			str++;
		}
		else
			count += write(1, str++, 1);		
	}
	va_end(arg);
	return(count);
}

// int main()
// {
// 	int x = ft_printf("hello %s%d%x%s\n", "first", 123, 120, "last\n");
// 	printf("lwn : %d", x);
// }