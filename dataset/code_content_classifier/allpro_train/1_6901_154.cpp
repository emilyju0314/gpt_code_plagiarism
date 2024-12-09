#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = (x << 1) + (x << 3) + ch - '0';
	return x * f;
}

const int N = 1e5 + 5;
int p[N], l[N], r[N];

int main()
{
	int n = read();
	for (int i = 1; i <= n; ++i) p[read()] = i;
	for (int i = 1; i <= n; ++i) l[i] = i - 1, r[i] = i + 1;
	
	long long ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		int l1 = l[p[i]], l2 = l[l1];
		int r1 = r[p[i]], r2 = r[r1];
		if (l1 > 0) ans += 1LL * i * (l1 - l2) * (r1 - p[i]);
		if (r1 < n + 1) ans += 1LL * i * (r2 - r1) * (p[i] - l1);
		l[r1] = l1; r[l1] = r1; 
	}
	printf("%lld\n", ans);
	return 0;
}