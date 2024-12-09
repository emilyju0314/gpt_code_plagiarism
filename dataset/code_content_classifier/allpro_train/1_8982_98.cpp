//
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define maxnn 2000
ll n;
ll ry[maxnn][maxnn];
ll ru[maxnn];
ll d=0;
ll mark[maxnn];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<n;j++)
	{
		scanf("%d",&ry[i][j]);
		ru[i]=1;
	}
	}
	while(1)
	{
		d++;
		for(int i=1;i<=n;i++)
{
		mark[i]=0;
}
		int tt=0;
		int tr=0;
		for(int i=1;i<=n;i++)
{
		if(ru[i]==n)	{continue;}
		if(mark[i]) {continue;}
		if(ry[ry[i][ru[i]]][ru[ry[i][ru[i]]]]!=i) 
	{
		tt++;
	} 
	else
	if(!mark[i]&&!mark[ry[i][ru[i]]])
	{
			ru[ry[i][ru[i]]]++;
			mark[i]=1;
			mark[ry[i][ru[i]]]=1;
			ru[i]++;
	}
}
	for(int i=1;i<=n;i++)
	if(ru[i]==n) tr++;
	if(tr==n) {cout<<d;return 0;}
	if(n-tr==tt) {cout<<-1;return 0;}
	}
} 