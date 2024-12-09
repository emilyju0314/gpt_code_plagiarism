#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <limits>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)

constexpr int MAX_N = 100;
constexpr double INF = 1e15;

int N;
int t[MAX_N + 1];
double v[MAX_N];
double maxv[40005]; // サイズを大きく

int main()
{
	scanf("%d", &N);
	rep(i, N)
		scanf("%d", t + i), t[i] *= 2;
	rep(i, N)
		scanf("%lf", v + i);

	std::fill( maxv, maxv+40005, INF );

	int cur = 0;

	rep(i, N)
	{
		repi(j, cur, cur+t[i]+1)
			maxv[j] = std::min( maxv[j], v[i] ); // ここが肝 (区間の境界のつじつまがあった)

		cur += t[i];
	}

	maxv[0] = 0; maxv[cur] = 0;

	rep(i, cur-1)
		maxv[i + 1] = std::min(maxv[i + 1], maxv[i] + 0.5);

	for (int i = cur - 1; i >= 0; --i)
		maxv[i] = std::min(maxv[i], maxv[i + 1] + 0.5);

	double ans = 0.0;

	rep(i, cur)
		ans += maxv[i] + maxv[i + 1];

	printf("%f\n", ans/4.0);

	return 0;
}