#include<bits/stdc++.h>
using namespace std;
int a[100000][3];
int main()
{
	int f=1,i,j,n;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		if((a[i][2]+a[i][1]>a[i][0])||a[i][0]%2!=(a[i][1]+a[i][2])%2)	f=0;
	}
	if(f==1) cout<<"Yes";
	else cout<<"No";
	return 0;
}
