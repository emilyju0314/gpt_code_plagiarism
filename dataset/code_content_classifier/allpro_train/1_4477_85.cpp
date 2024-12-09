#include<stdio.h>
int n,ans;char a[200001];
int main()
{
	scanf("%d%s",&n,a);
	for(register int l=0,r=n-1;l<r;)
	{
		for(;l<n&&a[l]=='R';++l);
		for(;r&&a[r]=='W';--r);
		if(l<r){++ans;++l;--r;}
	}
	printf("%d",ans);
}