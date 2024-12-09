#include <bits/stdc++.h>

int n, ntop[9]{}, move[9][9]{};
// 距離abs(a-b)/3+abs(a-b)%3

bool jisho(int[9], int[9]);

int main()
{
	scanf("%d", &n);
	char pre{};
	scanf(" %c", &pre);
	for (int i{1}; i < n; i++)
	{
		char s;
		scanf(" %c", &s);
		move[pre - '1'][s - '1']++;
		pre = s;
	}
	// for (int i{}; i < 9; i++)
	// {
	// 	for (int j{}; j < 9; j++)
	// 		printf("%d ", move[i][j]);
	// 	putchar('\n');
	// }
	for (int i{}; i < 9; i++) ntop[i] = i;
	long long min{1LL << 60};
	int ans[9]{};
	for (int i{}; i < 9; i++) ans[i] = 9;
	do
	{
		long long cost{};
		for (int i{}; i < 9; i++)
			for (int j{}; j < 9; j++)
				cost += move[i][j] * (std::abs(ntop[i] / 3 - ntop[j] / 3) + std::abs(ntop[i] % 3 - ntop[j] % 3));
		if (cost > min) continue;
		int tmp_ans[9]{};
		for (int i{}; i < 9; i++) tmp_ans[ntop[i]] = i;
		if (cost == min && !jisho(tmp_ans, ans)) continue;
		min = cost;
		for (int i{}; i < 9; i++) ans[i] = tmp_ans[i];
	} while (std::next_permutation(ntop, ntop + 9));
	for (int i{}; i < 3; i++)
	{
		for (int j{}; j < 3; j++)
		{
			putchar('1' + ans[3 * i + j]);
		}
		putchar('\n');
	}
	
	return 0;
}

bool jisho(int ntop[9], int min_arr[9])
{
	for (int i{}; i < 9; i++)
		if (ntop[i] > min_arr[i])
			return false;
		else if (ntop[i] < min_arr[i])
			return true;
	assert(true);
	return false;
}
