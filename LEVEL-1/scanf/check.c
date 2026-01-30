#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

int main()
{
	int num1 = 0;
    char s1[31];
	char c1;

    printf("scanfの d, s, c を入力してください: ");
    int i = scanf("aa %d %s %c", &num1, s1, &c1);

	printf("i: %d\n", i);

	printf("scanf result: \n");
    printf("d: '%d'\n", num1);
    printf("d: '%s'\n", s1);
	printf("d: '%c'\n", c1);

    return (0);
}
