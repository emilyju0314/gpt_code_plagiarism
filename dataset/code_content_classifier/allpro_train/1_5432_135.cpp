#include<bits/stdc++.h>
using namespace std;
int n,a[100005],ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n-1;i++)
		cin>>a[i];
	for(int i=1;i<=n-1;i++)
		ans+=min(a[i],a[i+1]);
	cout<<ans+a[n-1]+a[1];
	return 0;
 } 