#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int is_safe(int *answer_row, int curr_col, int curr_row)
{
	for (int prev_col = 0; prev_col < curr_col; prev_col++)
	{
		int prev_row = answer_row[prev_col]; // 過去に置いた colのrow を1つづつ代入.

		if (curr_row == prev_row ||
			curr_row - curr_col == prev_row - prev_col ||
			curr_row + curr_col == prev_row + prev_col)
			return 0;
	}
	return 1;
}

// curr_col++
void solve(int *answer_row, int curr_col, int n)
{
	// 1row print
	if (curr_col == n)
	{
		for (int i = 0; i < n; i++)
		{
			if (i > 0)
				printf(" ");
			printf("%d", answer_row[i]);
		}
		printf("\n");
		return ; // 呼び出し元へ戻る
	}

	// curr_row++ で1つづつcheck
	for (int curr_row = 0; curr_row < n; curr_row++) // 出力の1文字 = 1row
	{
		// 既に置いた 行0 ~ 行curr までで重複しないか？
		int safe_flag = is_safe(answer_row, curr_col, curr_row);

		if (safe_flag == 1)
		{
			answer_row[curr_col] = curr_row;

			solve(answer_row, curr_col+1, n); // 続けるべき時だけ再帰で進む = 正しい数だけsolveを呼べる.
		}
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		return 0;

	int n = atoi(av[1]);
	if (n < 4) //
		return 0;

	int *answer_row = malloc(sizeof(int) * n);
	if (!answer_row)
		return 0;

	solve(answer_row, 0, n);
	
	free(answer_row);
	return 0;
}
