#include <bits/stdc++.h>
using namespace std;

using db = double;
using ll = long long;
using vi = vector <int>;
#define op operator
#define pb push_back

string ans;
void dfs(vector <pair <int, string>> v) {
	if(v.size() == 1) {
		if(v[0].first == 10)
			ans = v[0].second;
		else
			return;
	}
	int n = v.size();
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n; j ++) if(i != j) {
			vector <pair <int, string>> nxt;
			for(int k = 0; k < n; k ++) if(i != k && j != k)
				nxt.pb({v[k]});
			nxt.pb({v[i].first + v[j].first, "(" + v[i].second + "+" + v[j].second + ")"});
			dfs(nxt); nxt.pop_back();
			nxt.pb({v[i].first - v[j].first, "(" + v[i].second + "-" + v[j].second + ")"});
			dfs(nxt); nxt.pop_back();
			nxt.pb({v[i].first * v[j].first, "(" + v[i].second + "*" + v[j].second + ")"});
			dfs(nxt); nxt.pop_back();
		}
}

int a[4];

int main() {
	ios :: sync_with_stdio(0);

	for(;;) {
		for(int i = 0; i < 4; i ++)
			cin >> a[i];
		if(*max_element(a, a + 4) == 0)
			break;
		vector <pair <int, string>> v;
		for(int i = 0; i < 4; i ++)
			v.pb({a[i], to_string(a[i])});
		ans = "";
		dfs(v);
		if(ans.size())
			cout << ans << '\n';
		else
			cout << "0\n";
	}

	return 0;
}