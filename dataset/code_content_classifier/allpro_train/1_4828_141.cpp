#include<bits/stdc++.h>
using namespace std;
int main()
{
	int mn=1001,i,n,t,cc,tt;
	scanf("%d %d",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&cc,&tt);
		if(tt<=t)
		{
			mn=min(mn,cc);
		}
	}
	if(mn==1001)printf("TLE");
	else printf("%d",mn);
	return 0;
}