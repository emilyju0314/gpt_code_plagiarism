#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int maxb = 20;
int x[maxn], r[maxn][maxb];
int n, L;
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &x[i]);
	scanf("%d", &L); 
	int j = n;
	r[n][0] = n + 1;
	for(int i = n - 1; i; --i)
	{
		while(x[j] - x[i] > L) --j;
		r[i][0] = j;
	}
	for(int j = 1; j < maxb; ++j) 
		for(int i = 1; i <= n; ++i)
			r[i][j] = r[i][j - 1] == n + 1 ? n + 1 : r[r[i][j - 1]][j - 1];
	int q;
	scanf("%d", &q);
	while(q--)
	{
		int u, v, ans = 0;
		scanf("%d%d", &u, &v);
		if(u > v) swap(u, v);
	 	for(int j = maxb - 1; ~j; --j)
	 		if(r[u][j] <= v)
	 		{
	 			u = r[u][j];
	 			ans += 1 << j;
	 		}
	 	if(u < v) ++ans;
	 	printf("%d\n", ans);
	}
	return 0;
}