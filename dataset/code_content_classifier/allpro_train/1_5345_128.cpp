#include<bits/stdc++.h>
using namespace std;

int x[105];

int main()
{
	long long ans=0,maxn=9999999999;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i]);
	for(int i=1;i<=100;i++)
	{
		ans=0;
		for(int j=1;j<=n;j++)
			ans+=(i-x[j])*(i-x[j]);
		maxn=min(ans,maxn);
	}
	cout<<maxn<<endl;
}