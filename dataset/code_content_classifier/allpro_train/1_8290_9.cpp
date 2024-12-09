#include <iostream>
#include <map>
#include <bits/stdc++.h>
#include <cstdlib>
#include <math.h> 
using namespace std;
#define ll long long int
int main()
{
	int n;
	ll ans;
	cin>>n;
	ll a[n],b[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
	}
	sort(a,a+n);
	sort(b,b+n);
	if(n%2)
	{
		ans=b[n/2]-a[n/2]+1;
	}
	else
	{
		ans=b[n/2]+b[n/2-1]-a[n/2]-a[n/2-1]+1;
	}
	cout<<ans;
	return 0;
}