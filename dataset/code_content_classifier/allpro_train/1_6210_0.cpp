#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int n,m,l,r;
	scanf("%d%d",&n,&m);
	char s[100005];
	int a[100005]={0},cnt=0;
	scanf("%s",s);
	for(int i=1;s[i];i++)
		if(s[i]=='C'&&s[i-1]=='A')
			a[i]=++cnt;
		else
			a[i]=cnt;
	for(int i=0;i<m;i++)
	{
		cnt=0;
		scanf("%d%d",&l,&r);
        l--;r--;
		printf("%d\n",a[r]-a[l]);
	}
	return 0;
}