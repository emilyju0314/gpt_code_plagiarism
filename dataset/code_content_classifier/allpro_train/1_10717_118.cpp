#include<bits/stdc++.h>
using namespace std;
long long a[101],w[101],v[101],i,j,n,res=0,f[100001],ww,m;
int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++) 
	{
		cin>>w[i]>>v[i];
		ww=ww+v[i];
	}
	for(i=1;i<=1e5;i++) f[i]=1e15;
	for(i=1;i<=n;i++)
	for(j=ww-v[i];j>=0;j--)
	{
		f[j+v[i]]=min(f[j+v[i]],f[j]+w[i]);
	}
	for(i=ww;i>=0;i--) if(f[i]<=m)
	{
		cout<<i;
		return 0;
	}
}