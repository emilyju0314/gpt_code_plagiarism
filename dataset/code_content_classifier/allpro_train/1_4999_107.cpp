#include <bits/stdc++.h>
using namespace std;
int f[200001],c[200001],pos[200001],nxt[200001];
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		if(pos[c[i]])
			nxt[pos[c[i]]]=i;
		pos[c[i]]=i;
	}
	f[1]=1;
	for(i=1;i<=n;i++)
	{
		if(nxt[i]>i+1)
			f[nxt[i]]=(f[nxt[i]]+f[i])%1000000007;
		f[i+1]=(f[i+1]+f[i])%1000000007;
	}
	printf("%d",f[n]);
}