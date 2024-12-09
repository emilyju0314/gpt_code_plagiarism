#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
const int MAX = 1e5+1;

int main(void){
	int N,C;
	cin >> N >> C;
	vector<int> s(N),t(N),c(N);
	rep(i,N){
		cin >> s[i] >> t[i] >> c[i];
		c[i]--;
	}
	vector<int> table(MAX+1);
	for(int i=0;i<C;i++){
		vector<int> dp(MAX+1);
		for(int j=0;j<N;j++)if(c[j]==i){
			dp[s[j]]++;
			dp[t[j]+1]--;
		}
		for(int j=0;j<MAX-1;j++)dp[j+1] += dp[j];
		for(int j=0;j<MAX;j++)if(dp[j])table[j]++;
		//for(int j=0;j<15;j++)cout << dp[j] << " ";
	}
	int mx = 0;
	for(int j=0;j<MAX;j++){
		mx = max(mx,table[j]);
	}
	cout << mx << endl;
}