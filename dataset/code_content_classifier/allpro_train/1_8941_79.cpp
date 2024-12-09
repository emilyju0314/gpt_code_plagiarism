#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string.h>
#include <cmath>
#include <iomanip> 
#include <ios> 
#define ll long long

using namespace std;

void solve()
{
	ll n,a,b;
	scanf("%lld %lld %lld",&n,&a,&b);
	ll w,bi;
	scanf("%lld %lld",&w,&bi);
	ll bl=(n-a + n-b);
	if((a+b)>=2*w && 2*bi<=bl)
	{
		printf("YES\n");
		return;
	}
	printf("NO\n");
	return;
}



int main(void)
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ll t=1;
	scanf("%lld",&t);
	while(t--)
	{
		solve();
	}
}



