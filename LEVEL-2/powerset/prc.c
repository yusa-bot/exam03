#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;

	return len;
}

int int_check(char **av)
{
	int i = 1;

	while (av[i])
	{
		int j = 0;

		if (av[i][j] == '+' || av[i][j] == '-')
			j++;

		while (av[i][j])
		{
			int c = av[i][j] - '0';

			if (c < 0 || c > 9)
				return 0;

			j++;
		}
		i++;
	}
	return 1;
}

void solve(int *num_arr, int len, int target, int *sub_num, int index, int sub_size, int curr_sum)
{
	if (index == len)
	{
		if (curr_sum == target)
		{
			for (int i = 0; i < sub_size; i++)
			{
				printf("%d", sub_num[i]);
				if (i < sub_size - 1)
					printf(" ");
			}
			printf("\n");
		}
		return ;
	}

	solve(num_arr, len, target, sub_num, index + 1, sub_size, curr_sum);
	sub_num[sub_size] = num_arr[index];
	solve(num_arr, len, target, sub_num, index + 1, sub_size + 1, curr_sum + num_arr[index]);
}

int main (int ac, char **av)
{
	if (ac > 3 && int_check(av))
	{
		int len = ac - 2;

		int *num_arr = malloc(sizeof(int) * (len + 1));
		if (!num_arr)
			return 0;

		int target = atoi(av[1]);

		int i = 2;
		int j = 0;
		while (av[i])
			num_arr[j++] = atoi(av[i++]);
		num_arr[j] = '\0';

		int *sub_num = malloc(sizeof(int) * len);
		if (!sub_num)
			return 0;

		solve(num_arr, len, target, sub_num, 0, 0, 0);

		free(num_arr);
		free(sub_num);
		return 0;
	}

	return 0;
}