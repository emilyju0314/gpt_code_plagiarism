#include <bits/stdc++.h>
#define LL long long 
#define N 1000005
using namespace std;
LL int n,m,ar[N],k[N],a,b,sum;
int main()
{
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
		ar[i]=1;
	k[1]=1;	
	
	for(int i=1;i<=m;i++)
	{
		scanf("%lld %lld",&a,&b);
		ar[a]--;
		ar[b]++;
		if(k[a])
			k[b]++;
		if(ar[a]==0)
			k[a]=0;
	}
	for(int i=1;i<=n;i++)
		if(k[i] && ar[i])
			sum++;
	printf("%lld",sum);		
}
