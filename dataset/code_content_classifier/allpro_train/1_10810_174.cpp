#include<bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005];
void Get(int x)
{
	puts(x?"Second":"First");
	exit(0);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		if (a[i]!=a[i-1]) b[i]=1;
		else b[i]=b[i-1]^1;
		int t=n+1-i;
		if (t==a[i-1])
			if (a[i]==a[i-1]) Get(b[i]);
			else Get((b[i-1]==0)&&(((a[i]^t^b[i]^1)&1)==0));
		if (t>a[i-1]&&t<=a[i]) Get((a[i]^t^b[i])&1);
	}
}