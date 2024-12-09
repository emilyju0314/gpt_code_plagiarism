// ACM-ICPCà\I2010 F. Ã¢L¯

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int INF = 100000000;

int d;
string mes, cur;
vector<string> piece;
vector<int> connect[30][20];
vector<string> ans;
set<string> mem[43];
int dp[43][43];

bool editDist(int s, int e){
	for(int i=s+1;i<=e;i++){
		int m = INF;
		for(int j=max(1,i-d);j<=min((int)mes.size(),i+d);j++){
			if(cur[i-1]==mes[j-1]) dp[i][j] = dp[i-1][j-1];
			else {
				dp[i][j] = dp[i-1][j-1]+1;
				dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
				dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
			}
			m = min(m, dp[i][j]);
		}
		if(m > d) return false;
	}
	return true;
}

void dfs(int pIdx){
	int len = piece[0].size();
	int csize = cur.size();
	if(dp[csize][mes.size()] <= d) ans.push_back(cur);
	for(int j=len-1;j>=0;j--){
		int nsize = csize + len - j;
		if(nsize > mes.size() + d) break;
		cur += ' ';
		for(int i=0;i<connect[pIdx][j].size();i++){
			bool flag = true;
			for(int k=j;k<len;k++){
				cur[csize+k-j] = piece[connect[pIdx][j][i]][k];
				if(!editDist(csize+k-j, csize+k-j+1)){
					flag = false;
					break;
				}
			}
			if(!flag) continue;
			if(mem[nsize].count(cur)) continue;
			mem[nsize].insert(cur);
			dfs(connect[pIdx][j][i]);
		}
	}
	cur = cur.substr(0, csize);
}

int main(){
	int n, len;
	for(int i=0;i<=42;i++) dp[i][0] = dp[0][i] = i;
	while(cin >> d >> n, n){
		cin >> mes;
		piece.clear();
		for(int i=0;i<n;i++){
			string str; cin >> str;
			piece.push_back(str);
		}
		sort(piece.begin(), piece.end());
		piece.erase(unique(piece.begin(), piece.end()), piece.end());
		len = piece[0].size();
		for(int i=1;i<=mes.size()+d;i++)
			for(int j=1;j<=mes.size()+d;j++)
				if(abs(i-j) > d) dp[i][j] = INF;
		for(int i=0;i<piece.size();i++){
			for(int k=0;k<len;k++){
				connect[i][k].clear();
				for(int j=0;j<piece.size();j++){
					if(piece[i].substr(len-k) == piece[j].substr(0,k))
						connect[i][k].push_back(j);
				}
			}
		}
		for(int i=0;i<=mes.size()+d;i++)
			mem[i].clear();
		ans.clear();
		for(int i=0;i<piece.size();i++){
			cur = piece[i];
			if(!editDist(0, len)) continue;
			dfs(i);
		}
		sort(ans.begin(), ans.end());
		cout << ans.size() << endl;
		if(ans.size() <= 5){
			for(int i=0;i<ans.size();i++)
				cout << ans[i] << endl;
		}
	}
}