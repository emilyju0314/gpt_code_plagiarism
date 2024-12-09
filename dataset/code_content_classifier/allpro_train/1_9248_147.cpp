#include <bits/stdc++.h>
using namespace std;

int n;
struct node
{
	int h,p,val;
	bool operator <(const node &a) const
	{
		return val < a.val;
	}
}a[5005];
long long dp[5005];

int main()
{
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d",&a[i].h,&a[i].p);
		a[i].val = a[i].h + a[i].p;
	}
	sort(a + 1,a + n + 1);
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 0x7fffffffffffffff;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j >= 1; j--)
		{
			if (dp[j - 1] <= a[i].h) dp[j] = min(dp[j],dp[j - 1] + a[i].p);
		}
	}
	int ans = -1;
	for (int i = 0; i <= n; i++)
	{
		if (dp[i] < 0x7fffffffffffffff) ans = i;
	}
	printf("%d",ans);
	return 0;
}