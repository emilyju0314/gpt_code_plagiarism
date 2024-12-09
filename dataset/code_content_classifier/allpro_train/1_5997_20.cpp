#include<bits/stdc++.h>
using namespace std;
int n,mo,res;
int dp[51][5001],ans[51][5001];
void solve(int x){
	if(x==1){
		dp[x][2500]=1;
		return;
	}
	solve(x-1);
	for(int i=1;i<=x;i++)
		for(int j=1;j<=x;j++){
			if(i==j){
				for(int k=2500-x*x;k<=2500+x*x;k++){
					ans[x][k]=(ans[x][k]+ans[x-1][k])%mo;
					dp[x][k]=(dp[x][k]+dp[x-1][k])%mo;
				}
			}else if(i>j){
				for(int k=2500-x*x;k+i-j<=2500+x*x;k++)
					dp[x][k+i-j]=(dp[x][k+i-j]+dp[x-1][k])%mo;
			}else{
				for(int k=2500-x*x+j-i;k<=2500+x*x;k++){
					dp[x][k+i-j]=(dp[x][k+i-j]+dp[x-1][k])%mo;
					ans[x][k+i-j]=(ans[x][k+i-j]+dp[x-1][k])%mo;
				}
			}
		}
	return;
}
signed main(){
	cin>>n>>mo;
	solve(n);
	for(int i=2501;i<=5000;i++)
		res=(res+ans[n][i])%mo;
	cout<<res<<endl;
	return 0;
}