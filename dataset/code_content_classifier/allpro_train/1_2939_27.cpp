# include <iostream>
# include <algorithm>
#include <array>
# include <cassert>
#include <cctype>
#include <climits>
#include <numeric>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <tuple>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
# include <complex>
# include <chrono>
# include <random>
# include <limits.h>
# include <unordered_map>
# include <unordered_set>
# include <deque>
# include <cstdio>
# include <cstring>
#include <stdio.h>
#include<time.h>
#include <stdlib.h>
#include <cstdint>
#include <cfenv>
#include<fstream>
//#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
long long MOD = 1000000000 + 7;
constexpr long long INF = numeric_limits<LL>::max();
const double PI = acos(-1);
#define fir first
#define sec second
#define thi third
#define debug(x) cerr<<#x<<": "<<x<<'\n'
typedef pair<LL, LL> Pll;
typedef pair<LL, pair<LL, LL>> Ppll;
typedef pair<LL, pair<LL, bitset<100001>>> Pbll;
typedef pair<LL, pair<LL, vector<LL>>> Pvll;
typedef pair<LL, LL> Vec2;
struct Tll { LL first, second, third; };
struct Fll { LL first, second, third, fourth; };
typedef pair<LL, Tll> Ptll;
#define rep(i,rept) for(LL i=0;i<rept;i++)
#define Mfor(i,mf) for(LL i=mf-1;i>=0;i--)
LL h, w, n, m, k, t, s, p, q, last, first, cnt, sum, ans, dp[200000], b[300000][26];
Pll a[300000];
string str, ss;
bool f[200];
char c, ch[100][100];
int di[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
struct Edge { LL to, cost; };
vector<Edge>vec[200000];
vector<LL>v[26];
map<Pll,LL>ma;
multiset<LL>st;
void YN(bool f) {
	if (f)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
void yn(bool f) {
	if (f)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

int main() {
	cin >> n;
	rep(i, n) {
		cin >> str;
		a[i].first = str[0] - 'a', a[i].second = str[str.size() - 1] - 'a';
		v[a[i].first].push_back(i);
		if (i == 0) {
			first = str[0] - 'a';
		}
		if (i == n - 1) {
			last = str[0] - 'a';
		}
	}
	Mfor(i, n) {
		rep(j, 26) {
			b[i][j] = -1;
		}
	}
	Mfor(i, n - 1) {
		rep(j, 26) {
			if (a[i + 1].first == j && b[i+1][j] == -1)
				b[i][j] = i+1;
			else
				b[i][j] = max(b[i][j], b[i + 1][j]);
		}
	}
	priority_queue<Pll,vector<Pll>,greater<Pll>>qu;
	qu.push(Pll(0, 0));
	rep(i, n+1) {
		dp[i] = INF;
	}
	dp[0] = 0;
	while (!qu.empty()) {
		Pll cur = qu.top();
		qu.pop();
		LL num = cur.first, u = cur.second;
		if (num > dp[u]||u==n)continue;

		for (auto i = lower_bound(v[a[u].first].begin(), v[a[u].first].end(), u + 1); i != v[a[u].first].end(); i++) {
				if (dp[*i] > dp[u]) {
					dp[*i] = dp[u];
					qu.push(Pll(dp[*i], *i));
				}
				else {
					break;
				}
		}

		if (dp[u + 1] > dp[u] + 1) {
			dp[u + 1] = dp[u] + 1;
			qu.push(Pll(dp[u + 1], u + 1));
		}
	}
	cout << dp[n] << endl;
	return 0;
}

