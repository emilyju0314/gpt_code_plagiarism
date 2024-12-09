#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
int INF = INT_MAX / 2;
double EPS = 1e-10;

int main() {
	int H, W, N; cin >> W >> H >> N;
	int sy, sx; cin >> sx >> sy; sy--; sx--;
	vector<int> L(N);
	vector<vector<int> > py(N), px(N);
	vector<vector<bool> > a(H, vector<bool>(W));
	for (int i = 0; i < N; i++) {
		cin >> L[i];
		int y, x;
		for (int t = 0; t < L[i]; t++) {
			cin >> x >> y; y--; x--;
			py[i].push_back(y);
			px[i].push_back(x);
		}
		a[y][x] = true;
	}
	vector<vector<vector<bool> > > dp(H, vector<vector<bool>>(W, vector<bool>(1<<N)));
	dp[sy][sx][(1<<N) - 1] = true;
	for (int t = 0; t < 45; t++) {
		vector<vector<vector<bool> > > _dp(H, vector<vector<bool>>(W, vector<bool>(1<<N)));
		for (int y = 0; y < H; y++)
			for (int x = 0; x < W; x++)
				for (int S = 0; S < 1<<N; S++) {
					if (!dp[y][x][S]) continue;
					int _S = 0;
					bool ok = true;
					for (int i = 0; i < N; i++)
						if ((S>>i & 1)) {
							if (L[i] <= t) {
								ok = false;
								break;
							}
							if (py[i][t] != y || px[i][t] != x)
								_S += 1<<i;
						}
					if (!ok) continue;
					if (_S == 0) {
						cout << t << endl;
						return 0;
					}
					for (int dy = -1; dy <= 1; dy++)
						for (int dx = -1; dx <= 1; dx++) {
							int _y = y + dy, _x = x + dx;
							if (_y >= 0 && _y < H && _x >= 0 && _x < W && !a[_y][_x])
								_dp[_y][_x][_S] = true;
						}
				}
		dp = _dp;
	}
	cout << -1 << endl;
}