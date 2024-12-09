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
long long MOD = 1000000000 + 7; //924844033 1000000000 + 7;
constexpr long long INF = numeric_limits<LL>::max();
const double PI = acos(-1);
#define fir first
#define sec second
#define thi third
#define debug(x) cerr<<#x<<": "<<x<<'\n'
typedef pair<LL, LL> Pll;
typedef pair<double, double> Dll;
typedef pair<LL, pair<LL, LL>> Ppll;
typedef pair<LL, pair<LL, bitset<100001>>> Pbll;
typedef pair<LL, pair<LL, vector<LL>>> Pvll;
typedef pair<LL, LL> Vec2;
struct Tll { LL first, second, third; };
struct Fll { LL first, second, third, fourth; };
typedef pair<LL, Tll> Ptll;
#define rep(i,rept) for(LL i=0;i<rept;i++)
#define Rrep(i,mf) for(LL i=mf-1;i>=0;i--)
LL h, w, n, m, k, t, s, p, q, last, first, cnt, sum[200000], ans, dp[40000],a[200000],b[200000];
string str, ss;
bool f;
char c;
int di[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
struct Edge { LL to, cost; };
struct edge { LL from, to, cost; };
vector<LL>vec;
vector<edge>ed;
vector<LL>v;
map<LL,LL>ma;
set<LL>st;
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

map<LL,LL> zip;
int unzip[200000];

int compress(vector<LL> &x) {
	sort(x.begin(), x.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	for (int i = 0; i < x.size(); i++) {
		zip[x[i]] = i;
		unzip[i] = x[i];
	}
	return x.size();
}

int main() {
	cin >> n;
	rep(i, n) {
		cin >> a[i] >> b[i];
		v.push_back(a[i]);
		v.push_back(b[i]);
	}
	compress(v);
	rep(i, n) {
		a[i] = zip[a[i]];
		b[i] = zip[b[i]];
		sum[a[i]]++;
		sum[b[i] + 1]--;
	}
	rep(i, 110000) {
		sum[i + 1] += sum[i];
		ans = max(sum[i], ans);
	}
	cout << ans << endl;
	return 0;
}

