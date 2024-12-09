#include<bits/stdc++.h>
#define EM 100000000
using namespace std;
using LL = long long;
using P = pair<LL, LL>;
LL LINF = 1e18;
int INF = 1e9;
using vint = vector<int>;
using vLL = vector<LL>;
using vvint = vector<vector<int>>;
using vvLL = vector<vector<LL>>;

vvint vp(100000);
vint ans, used(100000, 0);

void dfs(int v){
	for(auto s : vp[v]){
		if(!used[s]){
			ans.push_back(s);
			used[s] = 1;
			dfs(s);
			break;
		}
	}
}
int main(){
	int N, M;
	cin >> N >> M;
	for(int i = 0;i < M;i++){
		int ai, bi;
		cin >> ai >> bi;
		vp[ai-1].push_back(bi-1);
		vp[bi-1].push_back(ai-1);
	}
	ans.push_back(0);
	used[0] = 1;
	dfs(0);
	reverse(ans.begin(), ans.end());
	for(auto s : vp[0]){
		if(!used[s]){
			ans.push_back(s);
			used[s] = 1;
			dfs(s);
			break;
		}
	}
	cout << ans.size() << endl;
	for(auto s : ans)	cout << (s+1) << " ";
}