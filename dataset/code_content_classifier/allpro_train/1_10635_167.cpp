#include <map>
#include <vector>
#include <iostream>
#pragma warning(disable : 4996)
using namespace std;
int n, m, x;
int main() {
	scanf("%d%d", &n, &m);
	vector<vector<int> > f(m);
	vector<int> c(m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		f[x % m].push_back(x);
		c[x % m]++;
	}
	for (int i = 0; i < m; i++) {
		map<int, int> e;
		for (int j : f[i]) e[j]++;
		vector<int> g;
		for (pair<int, int> j : e) g.push_back(j.second);
		f[i] = g;
	}
	int ret = 0;
	for (int i = 0; i <= m / 2; i++) {
		int p = (m - i) % m;
		if (i == p) {
			f[i].clear(); ret += c[i] / 2; c[i] = 0;
		}
		else {
			if (c[i] < c[p]) {
				swap(c[i], c[p]);
				swap(f[i], f[p]);
			}
			f[p].clear(); ret += c[p];
			while (c[p]--) {
				bool flag = false;
				for (int j = 0; j < f[i].size() && !flag; j++) {
					if (f[i][j] % 2 == 1) {
						f[i][j]--;
						flag = true;
					}
				}
				if (!flag) {
					for (int j = 0; j < f[i].size(); j++) {
						if (f[i][j] != 0) {
							f[i][j]--; break;
						}
					}
				}
			}
			for (int j = 0; j < f[i].size(); j++) ret += f[i][j] / 2;
			c[p] = 0;
			f[i].clear(); c[i] = 0;
		}
	}
	cout << ret << endl;
	return 0;
}