#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<int>x(n, 0); stack<int>s;
	vector < vector<pair<int, int>>>l(n), r(n);
	for (int i = 0, L, R, d; i < m; i++) {
		cin >> L >> R >> d; L--; R--;
		l[R].push_back({ L,d }); r[L].push_back({ R,d });
	}
	for (int i = 0; i < n; i++) {
		if (l[i].size() == 0) { x[i] = 1; s.push(i); }
	}
	bool ok = true;
	while (!s.empty()) {
		int node = s.top(); s.pop();
		for (int i = 0; i < r[node].size(); i++) {
			int next = r[node][i].first, xd = x[node] + r[node][i].second;
			if (x[next] == 0) { x[next] = xd; s.push(next); }
			else if (x[next] != xd) { ok = false; break; }
		}
	}
	for (int i = 0; i < n; i++) if (x[i] == 0)ok = false;
	cout << (ok ? "Yes" : "No") << endl;
	return 0;
}