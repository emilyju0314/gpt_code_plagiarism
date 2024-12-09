#include<bits/stdc++.h>
using namespace std;
long long h[100005],dp[100005],k,n,K,i;
int main(){
	cin>>n>>K;
	for(k=1;k<=n;k++){
		cin>>h[k]; dp[k]=1e12;
	}
	dp[1]=0;
	long long f=1;
	for(k=2;k<=n;k++){
	
	for(i=k-1;i>=max(k-K,f);i--)
		dp[k]=min(dp[i]+abs(h[k]-h[i]),dp[k]);
	}
	cout<<dp[n];
}