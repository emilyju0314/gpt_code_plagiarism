#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#include <map>

using namespace std;

const string button = "22233344455566677778889999";
int ctob[256];

bool check(string &s, string &t, int idx){
	if (idx + s.size() > t.size()) return false;
	for (int i = 0; i < s.size(); ++i){
		if (ctob[s[i]] != t[i + idx]) return false;
	}
	return true;
}

vector<string> v;
vector<vector<pair<int, int>>> G;
int ans[500];
int len;

void dfs(int idx, int n){
	if (idx == len){
		for (int i = 0; i < n; ++i){
			cout << v[ans[i]] << (i == n - 1 ? ".\n" : " ");
		}
		return;
	}
	for (auto e : G[idx]){
		ans[n] = e.first;
		dfs(idx + e.second, n + 1);
	}
}

int main(){
	for (int i = 0; i < button.size(); ++i){
		ctob['a' + i] = button[i];
	}

	int n;
	while (cin >> n, n){
		v.clear(), v.resize(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		string t;
		cin >> t;
		len = t.size();
		G.clear(), G.resize(len);
		for (int i = 0; i < len; ++i){
			for (int j = 0; j < n; ++j){
				if (check(v[j], t, i)) G[i].push_back(make_pair(j, v[j].size()));
			}
		}
		dfs(0, 0);
		cout << "--\n";
	}


	return 0;
}