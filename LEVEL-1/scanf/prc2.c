
#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int match_space(FILE *f)
{
        // You may insert code here
    return (0);
}

int match_char(FILE *f, char c)
{
        // You may insert code here
    return (0);
}

int scan_char(FILE *f, va_list ap)
{
        // You may insert code here
    return (0);
}

int scan_int(FILE *f, va_list ap)
{
        // You may insert code here
    return (0);
}

int scan_string(FILE *f, va_list ap)
{
        // You may insert code here
    return (0);
}


int	match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
		case 'c':
			return scan_char(f, ap);
		case 'd':
			match_space(f);
			return scan_int(f, ap);
		case 's':
			match_space(f);
			return scan_string(f, ap);
		case EOF:
			return -1;
		default:
			return -1;
	}
}

int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int nconv = 0;
	int ret;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ret = match_conv(f, &format, ap);
			if (ret == -1)
			{
                return (nconv == 0) ? -1 : nconv;
            }
			else if (ret == 0)
			{
                return nconv;
            }
			else
			{
                nconv++;
            }
		}

		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				return (nconv == 0) ? -1 : nconv;
		}

		else
		{
			ret = match_char(f, *format);
			if (ret == -1)
				return (nconv == 0) ? -1 : nconv;
			else if (ret == 0)
				return nconv;
		}

		format++;
	}

	if (ferror(f))
		return EOF;
	return nconv;
}


int ft_scanf(const char *format, ...)
{
	va_list ap;
    va_start(ap, format);
	int ret = ft_vfscanf(stdin, format, ap);
	va_end(ap);
    return ret;
}


int main()
{
    int num1 = 0;
    char s1[31];
	char c1;

    printf("scanfの d, s, c を入力してください: ");
    scanf("%d %s %c", &num1, s1, &c1);

	printf("scanf result: \n");
    printf("d: %d\n", num1);
    printf("d: %s\n", s1);
	printf("d: %c\n", c1);

	//////

	int num2 = 0;
    char s2[31];
	char c2;

	printf("ft_scanfの d, s, c を入力してください: ");
	ft_scanf("%d %s %c", &num2, s2, &c2);

	printf("ft_scanf result: \n");
    printf("d: %d\n", num2);
    printf("d: %s\n", s2);
	printf("d: %c\n", c2);

    return (0);
}
