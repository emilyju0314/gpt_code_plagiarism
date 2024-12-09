#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
const int M=2e5+5;
int a[M],b[M];
int n,ans=0;
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		int x,y;
		cin >>x >>y;
		a[i] = x+y;
		b[i] = y-x;
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	ans = max(a[n]-a[1],b[n]-b[1]);
	printf("%d\n",ans);
	return 0;
}