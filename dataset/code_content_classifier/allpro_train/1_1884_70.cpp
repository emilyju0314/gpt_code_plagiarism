#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1005;

struct data
{
	int w, s, v;
};

int n;
int cache[N][20005];
data a[N];

bool comp(data &d1, data &d2)
{
	return (d1.w+d1.s)<(d2.w+d2.s);
}

int dp(int idx, int wt)
{
	if(idx==n+1)
		return 0;
	int &ans=cache[idx][wt];
	if(ans!=-1)
		return ans;
	ans=dp(idx+1, wt);
	if(a[idx].s>=wt)
		ans=max(ans, a[idx].v + dp(idx+1, wt+a[idx].w));
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].w>>a[i].s>>a[i].v;
	sort(a+1, a+n+1, comp);
	int ans=dp(1, 0);
	cout<<ans;
	return 0;
}