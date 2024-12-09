#include <cstdio>
#include <cstring>
#include <algorithm>

int n, k, f[305][305][305];
char s[305];

int main()
{
	scanf("%s%d", s + 1, &k);
	n = strlen(s + 1);
	for (int l = n; l; l--)
	{
		f[l][l][0] = f[l][l][1] = 1;
		for (int r = l + 1; r <= n; r++)
			for (int x = 0; x <= r - l + 1; x++)
				f[l][r][x] = std::max({f[l + 1][r][x], f[l][r - 1][x], (x >= (s[l] != s[r])) ? f[l + 1][r - 1][x - (s[l] != s[r])] + 2 : 0});
	}
	int ans = 0;
	for (int i = 0; i <= k; i++)
		ans = std::max(ans, f[1][n][i]);
	printf("%d\n", ans);
	return 0;
}