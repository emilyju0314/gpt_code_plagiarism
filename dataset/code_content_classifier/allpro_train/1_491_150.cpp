#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 2e3 + 7;
const int M = 1e9 + 7;
int S[N], T[N], sum[N][N];

int mod(int val)
{
	return (val % M + M) % M;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i)
		scanf("%d", &S[i]);
	for (int i = 0; i < m; ++i)
		scanf("%d", &T[i]);

	for (int i = 0; i <= max(n, m); ++i)
		sum[0][i] = sum[i][0] = 1;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			int val = S[i] == T[j] ? sum[i][j] : 0;
			sum[i + 1][j + 1] = mod(mod(mod(sum[i + 1][j] + sum[i][j + 1]) - sum[i][j]) + val);
		}

	printf("%d", sum[n][m]);

	return 0;
}