#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=5e5+1e3+7;

int n,a[N],f[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		f[a[i]]=f[a[i]-1]+1;
	int mx=0;
	for(int i=1;i<=n;i++)
		mx=max(mx,f[i]);
	printf("%d",n-mx);
}