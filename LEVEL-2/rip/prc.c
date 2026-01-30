#include <stdio.h>

int valid(char *str)
{
	int opened = 0;
	int closed = 0;

	int i = 0;

	while (str[i])
	{
		if (str[i] == '(')
			opened++;

		if (str[i] == ')')
		{
			if (opened > 0)
				opened--;
			else
				closed++;
		}
		i++;
	}

	return opened + closed;
}

void solve(char *str, int n_fix, int n_fixed, int pos)
{
	if (n_fix == n_fixed && !valid(str))
	{
		puts(str);
		return ;
	}

	for (int i = pos; str[i]; i++)
	{
		if (str[i] == '(' || str[i] == ')')
		{
			char c = str[i];
			str[i] = ' ';
			solve(str, n_fix, n_fixed + 1, i);
			str[i] = c;
		}
		i++;
	}

}

int main(int ac, char **av)
{
	if (ac != 2)
		return 0;

	int n_fix = valid(av[1]);
	solve(av[1], n_fix, 0, 0);

	return 0;
}