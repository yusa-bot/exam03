#include <stdio.h>
#include <stdlib.h>

//void print_ans(int len, int int_arr_i, int int_arr_j)
//{
//	int i = 0;
//	while (i < len)
//	{
//		printf("%d", int_arr_i)
//		i++;
//	}
//}

//solve(int first_int, int *int_arr, int len)
//{
//	int *ans_arr = malloc(sizeof(int) * len + 1);
//	if (!ans_arr)
//		return ;

//	for (int i = 0; i < len; i++)
//	{
//		for (int j = i+1; j < len; j++)
//		{
//			if (first_int == int_arr[i] + int_arr[j])
//			{

//			}
//		}
//	}
//}

//int main(int ac, char **av)
//{
//	if (ac < 2)
//		return 0;

//	int *int_arr = malloc(sizeof(int) * (ac - 1 + 1));
//	if (!int_arr)
//		return 0;

//	int first_int = atoi(av[1]);

//	int i = 0;
//	int j = 2;
//	while (av[j])
//	{
//		int_arr[i] = atoi(av[j]);
//		i++;
//		j++;
//	}
//	int_arr[i] = '\0';

//	int len =  ac - 2;

//	solve(first_int, int_arr, len);

//	return 0;
//}


int check_int(char **str, int ac)
{
	int j = 1;
	while (j < ac)
	{
		int i = 0;

		if (str[j][i] == '-' || str[j][i] == '+')
			i++;

		while (str[j][i])
		{
			if (str[j][i] < '0' || str[j][i] > '9')
				return 0;
			i++;
		}
		j++;
	}
	return 1;
}

void solve(int *nums, int size, int target, int *subset, int index, int sub_size, int curr_sum)
{
	if (index == size)
	{
		if(curr_sum == target)
		{
			for(int i =0; i < sub_size; i++)
			{
				printf("%d", subset[i]);
				if(i != sub_size - 1)
					printf(" ");
			}
			printf("\n");
		}
		return ;
	}
	solve(nums, size, target, subset, index + 1, sub_size, curr_sum);
	subset[sub_size] = nums[index];
	solve(nums, size, target, subset, index + 1, sub_size + 1, curr_sum + nums[index]);
}

int main(int ac, char **av)
{
	if(ac > 3 && check_int(av, ac))
	{
		int target = atoi(av[1]);

		int *nums = malloc(sizeof(int) * (ac - 2));
		for(int i= 0; i< ac -2; i++)
			nums[i] = atoi(av[i+2]);

		int subset[(ac -2)];

		solve(nums, (ac -2), target, subset, 0, 0, 0);

		free(nums);
		return 0;
	}
	return 1;
}
