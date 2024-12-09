#include<bits/stdc++.h>
using namespace std;
int a[51],n,k,t,sum;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	t=n-k;
	for(int i=n;i>t;i--) sum+=a[i];
	cout<<sum<<endl;
	return 0;
}