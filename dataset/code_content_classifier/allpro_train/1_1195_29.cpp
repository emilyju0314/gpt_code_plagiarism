#include <bits/stdc++.h>
using namespace std;
using ll =long long int;
constexpr ll mod = 1e6;
vector<int>arr[mod];
int res[mod];
int main()
{
	int n, m;
	cin >> n >> m;
	vector<bool>vis(n + 1, false);
	for (int i = 1; i <= m; ++i) {
		int a, b; cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	queue<int>q;
	q.push(1);
	vis[1] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto ele : arr[x]) {
			if (!vis[ele]) {
				vis[ele] = true;
				res[ele] = x;
				q.push(ele);
			}
		}
	}
	cout << "Yes\n";
	for (int i = 2; i <= n; ++i) {
		cout << res[i] << "\n";
	}
	return 0;
}