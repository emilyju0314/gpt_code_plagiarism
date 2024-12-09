#include <bits/stdc++.h>
using namespace std;


int c[1111],w[1111];
int s[1111];
int sum(int l,int r){
	return s[r] - (l?s[l-1]:0);
}
int dp[1010][1010];
int dfs(int l,int r){
	if( r == l ) return 1;
	if( dp[l][r] != -1 ) return dp[l][r];
	int ans = 0;
	if( sum(l+1,r) <= c[l] ) ans |= dfs(l+1,r);
	if( sum(l,r-1) <= c[r] ) ans |= dfs(l,r-1);
	return dp[l][r] = ans;
}

int dp2[1010];
int N;

int dfs2(int x){
	if( x == N ) return 0;
	if( dp2[x] != -1 ) return dp2[x];
	int ans = 1e9;
	for(int i = x ; i < N ; i++)
		if( dfs(x,i) )
			ans = min(ans,dfs2(i+1)+1);
	return dp2[x] = ans;
}
int main(){
	memset(dp2,-1,sizeof(dp2));

	memset(dp,-1,sizeof(dp));
	cin >> N;
	for(int i = 0 ; i < N ; i++){
		cin >> c[i] >> w[i];
		s[i] = (i?s[i-1]:0)+w[i];
	}
	cout << dfs2(0) << endl;
}