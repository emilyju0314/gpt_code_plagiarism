#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 1e18
ll MOD = 1e9+7;
ll a[403];
ll n,K;
ll dp[100000000];
//dp[i] - in which rows i have done and ways to make it happen
int main(){
	cin>>n;
	memset(dp,0,sizeof dp);
	ll a[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	dp[0]=1;
	for(int i=0;i<(1<<n);i++){
		int col = __builtin_popcount(i);
		for(int j=0;j<n;j++){
			if(((1<<j)&i)==0){
				if(a[j][col]){
					dp[(i|(1<<j))]+=dp[i];
					dp[(i|(1<<j))] = dp[(i|(1<<j))]%MOD;
				}
			}
		}
	}
	cout<<dp[(1<<n)-1]<<endl;
}