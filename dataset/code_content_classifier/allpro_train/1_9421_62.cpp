/*
数据不清空，爆零两行泪。
多测不读完，爆零两行泪。
边界不特判，爆零两行泪。
贪心不证明，爆零两行泪。
D P 顺序错，爆零两行泪。
大小少等号，爆零两行泪。
变量不统一，爆零两行泪。
越界不判断，爆零两行泪。
调试不注释，爆零两行泪。
溢出不 l l，爆零两行泪。
*/
#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
const int N=3000;
int n;
char a[N+5];
int dp[N+1][N+1];
int Sum[N+1];
int main(){
	cin>>n>>a+1;
	dp[1][1]=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++)Sum[j]=(Sum[j-1]+dp[i-1][j])%mod;
		for(int j=1;j<=i;j++)dp[i][j]=a[i-1]=='>'?Sum[j-1]:((Sum[i-1]-Sum[j-1])%mod+mod)%mod;
//		for(int j=1;j<=i;j++)cout<<dp[i][j]<<" ";puts("");
	}
	int ans=0;
	for(int i=1;i<=n;i++)(ans+=dp[n][i])%=mod;
	cout<<ans;
	return 0;
}