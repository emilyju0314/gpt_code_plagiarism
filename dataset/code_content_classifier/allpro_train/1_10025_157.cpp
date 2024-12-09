#include<bits/stdc++.h>
using namespace std;

int n,a[20];

long long dp(int l,int r,long long xl,long long xr) {
	if(l+1==r) return 0;
	long long ret=1e18;
	for(int i=l+1;i<r;i++) ret=min(ret,dp(l,i,xl,xl+xr)+dp(i,r,xl+xr,xr)+(xl+xr)*a[i]);
	return ret;
}

int main() {
	cin>>n;for(int i=1;i<=n;i++) cin>>a[i];
	cout<<dp(1,n,1,1)+a[1]+a[n];
	return 0;
}
