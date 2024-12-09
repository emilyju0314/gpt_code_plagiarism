//A
#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int m;
	long long c,d; 
	long long sum=0,tot=0,ans;//sum:位数；tot：总和 
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld",&d,&c);
		sum+=c;
		tot+=d*c;
	}
	if(tot%9!=0)
		ans=sum-1+tot/9;
	if(tot%9==0)
		ans=sum-1+(tot-9)/9;
	cout<<ans<<endl;
	
}