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

ll gcd(ll a, ll b) {
	if (b == 0) return abs(a);
	else return gcd(b, a % b);
}

int main() {
	int T; cin >> T;
	while (T--) {
		ll h, w; cin >> h >> w;
		for (; h % 2 == 0 && w % 2 == 0; h /= 2, w /= 2);
		if (h % 2 == 0 || w % 2 == 0) {
			cout << 1 << ' ' << 1 << endl;
			continue;
		}
		ll d = gcd(h, w);
		h /= d; w /= d;
		if (h < w) swap(h, w);
		ll r = ((h - w) / 2 + 1) * w + (w / 2) * (w / 2) * 2;
		ll b = ((h - w) / 2) * w + (w / 2) * (w / 2 + 1) * 2;
		d = gcd(r, b);
		cout << r / d << ' ' << b / d << endl;
	}
}