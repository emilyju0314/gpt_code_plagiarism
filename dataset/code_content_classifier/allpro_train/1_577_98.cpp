#include <bits/stdc++.h>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cout.tie(0);
cin.tie(NULL);
int n,m; cin>>n>>m;
int a[n];
for(int i=0;i<n;i++)
a[i]=10;
if(n==1&&m==0)
{
	cout<<0; return 0;
}
while(m--)
{
	int s,c;
	cin>>s>>c;
	if(a[s-1]!=10&&a[s-1]!=c)
	{
		cout<<-1; return 0;
	}
	a[s-1]=c;
}
if(a[0]==10)
cout<<1;
else if(a[0]==0&&n>=2)
{
		cout<<-1; return 0;
}
else
cout<<a[0];
for(int i=1;i<n;i++)
{
	if(a[i]==10)
	{
		a[i]=0;
	}
	cout<<a[i];
}
}
