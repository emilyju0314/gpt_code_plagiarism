#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

int n, m, c;
int l[100000];
int color, w;;
vector<int> val[100000];

int main() {
	int i, j;
	
	cin >> n >> m >> c;
	for (i = 0; i < c; i++) cin >> l[i];
	for (i = 0; i < n; i++) {
		cin >> color >> w; color--;
		val[color].push_back(w);
	}
	for (i = 0; i < c; i++) sort(val[i].begin(), val[i].end(), greater<int>());
	
	priority_queue<int, vector<int>, greater<int> > que;
	for (i = 0; i < c; i++) {
		for (j = 0; j < val[i].size(); j++) {
			if (l[i] > 0) {
				que.push(val[i][j]);
				l[i]--;
			}
			if (que.size() > m) que.pop();
		}
	}
	
	int ans = 0;
	while (!que.empty()) {
		ans += que.top(); que.pop();
	}
	cout << ans << endl;
	return 0;
}
