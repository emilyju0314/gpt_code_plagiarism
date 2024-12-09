#include<iostream>
#include<vector>
using namespace std;
int n,a[50],b[50];
bool use[50];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i];
	bool f=0;
	for(int i=0;i<n;i++)f|=a[i]<=2*b[i]&&a[i]!=b[i];
	if(f)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(int i=1;i<50;i++)use[i]=1;
	for(int i=49;i>0;i--)
	{
		use[i]=0;
		bool d[51][51]={};
		for(int j=0;j<=50;j++)d[j][j]=1;
		for(int j=1;j<50;j++)
		{
			if(!use[j])continue;
			for(int k=0;k<j;k++)
			{
				for(int l=k+j;l<=50;l+=j)d[l][k]=1;
			}
		}
		for(int k=0;k<=50;k++)for(int j=0;j<=50;j++)for(int l=0;l<=50;l++)d[j][l]|=d[j][k]&&d[k][l];
		f=1;
		for(int j=0;j<n;j++)f&=d[a[j]][b[j]];
		if(!f)use[i]=1;
	}
	long ans=0;
	for(int i=1;i<50;i++)ans|=(long)(use[i])<<i;
	cout<<ans<<endl;
}