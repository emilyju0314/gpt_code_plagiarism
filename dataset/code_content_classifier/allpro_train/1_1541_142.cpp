#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int N, M;
int x[MAXN], y[MAXN];
vector <pii> v;
vector <int> comp;
int f[MAXN];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", x + i);
	for (int i = 0; i < M; i++)
		scanf("%d", y + i);
}

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	return x;
}

void update(int x, int val) {
	for (x++; x < MAXN; x += x & -x)
		f[x] = add(f[x], val);
}

int get(int x) {
	int res = 0;
	for (x++; x; x -= x & -x)
		res = add(res, f[x]);
	return res;
}

int solve() {
	for (int i = 0; i < N; i++) 
		if (x[i] > y[0] && x[i] < y[M - 1]) {
			int pos = lower_bound(y, y + M, x[i]) - y;
			v.push_back({x[i] - y[pos - 1], x[i] - y[pos]});
		}
	
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	
	for (auto &it : v) {
		it.second *= -1;
		comp.push_back(it.second);
	}
	
	sort(comp.begin(), comp.end());		
	
	int sol = 1;
	for (auto it : v) {
		int tmp = lower_bound(comp.begin(), comp.end(), it.second) - comp.begin();
		int dp = add(get(tmp - 1), 1);
		sol = add(sol, dp);
		update(tmp, dp);
	}
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}