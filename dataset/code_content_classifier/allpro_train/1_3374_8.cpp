#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void chmin(int &x, int y){ x = min(x, y); }

int solve(string a, string b, int ci, int ce, int cs, int cr){
	const int INF = 1010101010;

	int la = a.size();
	int lb = b.size();
	vector<vector<int> > dp;
	int ans = INF;
	for(int k = 0; k < la; ++k){
		dp.assign(la + 1, vector<int>(lb + 1, INF));
		dp[0][0] = 0;
		for(int i = 0; i <= la; ++i)
		for(int j = 0; j <= lb; ++j){
			if(i < la){
				int t = i < la - k ? ce : ce - cr;
				chmin(dp[i + 1][j], dp[i][j] + t);
			}
			if(j < lb){
				chmin(dp[i][j + 1], dp[i][j] + ci);
			}
			if(i < la && j < lb){
				int t = a[i] == b[j] ? 0 : cs;
				chmin(dp[i + 1][j + 1], dp[i][j] + t);
			}
		}
		chmin(ans, dp[la][lb] + k * cr);
		rotate(a.begin(), a.begin() + 1, a.end());
	}
	return ans;
}

int main(){
	string a, b;
	int ci, ce, cs, cr;
	while(cin >> a >> b >> ci >> ce >> cs >> cr){
		cout << solve(a, b, ci, ce, cs, cr) << endl;
	}
}
