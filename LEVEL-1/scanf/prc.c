#include <stdio.h>

// int main()
// {
//     int num;
//     float height;

//     printf("整数と浮動小数点数を入力してください: ");
//     // 整数と浮動小数点数を読み込む
//     scanf("%d %f", &num, &height);

//     printf("入力された整数: %d\n", num);
//     printf("入力された浮動小数点数: %.2f\n", height);

//     return (0);
// }

int	ap(int count, ...)
{
	va_list	ap;
	int		sum;
	int		i;

	va_start(ap, count);
	sum = 0;
	i = 0;
	while (i < count)
	{
		sum += va_arg(ap, int);
		i++;
	}
	va_end(ap);
	return (sum);
}

int	main(void)
{
	printf("%d\n", ap(3, 10, 20, 30));
	return (0);
}

////

// #include <stdarg.h>
// #include <stdio.h>
// #include <ctype.h>

// int match_space(FILE *f)
// {
//         // You may insert code here
//     return (0);
// }

// int match_char(FILE *f, char c)
// {
//         // You may insert code here
//     return (0);
// }

// int scan_char(FILE *f, va_list ap)
// {
//         // You may insert code here
//     return (0);
// }

// int scan_int(FILE *f, va_list ap)
// {
//         // You may insert code here
//     return (0);
// }

// int scan_string(FILE *f, va_list ap)
// {
//         // You may insert code here
//     return (0);
// }

// int	match_conv(FILE *f, const char **format, va_list ap)
// {
// 	switch (**format)
// 	{
// 		case 'c':
// 			return (scan_char(f, ap));
// 		case 'd':
// 			match_space(f);
// 			return (scan_int(f, ap));
// 		case 's':
// 			match_space(f);
// 			return (scan_string(f, ap));
// 		case EOF:
// 			return (-1);
// 		default:
// 			return (-1);
// 	}
// }

// int ft_vfscanf(FILE *f, const char *format, va_list ap)
// {
// 	int nconv = 0;

// 	int c = fgetc(f);
// 	if (c == EOF)
// 		return (EOF);
// 	ungetc(c, f);

// 	while (*format)
// 	{
// 		if (*format == '%')
// 		{
// 			format++;
// 			if (match_conv(f, &format, ap) != 1)
// 				break ;
// 			else
// 				nconv++;
// 		}
// 		else if (isspace(*format))
// 		{
// 			if (match_space(f) == -1)
// 				break ;
// 		}
// 		else if (match_char(f, *format) != 1)
// 			break ;
// 		format++;
// 	}

// 	if (ferror(f))
// 		return (EOF);
// 	return (nconv);
// }

// int ft_scanf(const char *format, ...)
// {
// 	// ...
// 	int ret = ft_vfscanf(stdin, format, ap);
// 	// ...
// 	return (ret);
// }
