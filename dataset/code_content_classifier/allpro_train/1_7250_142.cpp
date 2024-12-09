#include<bits/stdc++.h>
using namespace std;
int n,a[100000],b[100000];
int main()
{
	cin>>n;
	for (int i=0,k=1;i<n;i++,k*=-1)
	    cin>>b[i+1],a[1]+=k*b[i+1];
	for (int i=2;i<=n;i++)
		a[i]=2*b[i-1]-a[i-1];
	for (int i=1;i<=n;i++)
	    cout<<a[i]<<" \n"[i==n];
	return 0;
}
