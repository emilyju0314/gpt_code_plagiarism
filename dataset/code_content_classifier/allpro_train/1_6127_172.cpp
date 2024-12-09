#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
LL v[300010];

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=3*N;i++)scanf("%lld",&v[i]);
	sort(v+1,v+3*N+1);
	LL res = 0;
	for (int i=3*N-1;i>N;i-=2)
		res+=v[i];
	printf("%lld\n",res);
}