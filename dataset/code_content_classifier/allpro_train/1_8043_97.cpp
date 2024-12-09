#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <fstream>
#include <bitset>
#include <time.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef complex<double> Point;

#define PI acos(-1.0)
#define EPS 1e-10
const ll INF = (1LL << 31) - 1;
const ll MOD = 1e9 + 7;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,N) for(int i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )
#define fi first
#define se second
#define N_SIZE (1LL << 20)
#define NIL -1
#define MAX_N 100100 * 3

int table[100][100];

string changes(ll i) {
	stringstream ss;
	ss << i;
	return ss.str();
}

bool check(string s) {
	int e = 0;
	REP(i, s.size()) {
		e = table[e][s[i] - '0'];
	}
	if (e == 0)return true;
	return false;
}

int main() {
	int ans = 0;
	REP(i, 10)REP(j, 10)cin >> table[i][j];
	REP(i, 10000) {
		string s = changes(i);
		int size = s.size();
		while (s.size() < 4)s = "0" + s;
		int now = 0;
		REP(j, s.size()) {
			now = table[now][s[j] - '0'];
		}
		s += "0";
		s[4] += now;
		bool f = 0;
		string t;
		REP(j, s.size()) {
			REP(k, 10) {
				t = s;
				t[j] = (char)('0' + k);
				if (s == t)continue;
				if (check(t))f = 1;
			}
		}
		REP(j, s.size() - 1) {
			t = s;
			swap(t[j], t[j + 1]);
			if (s == t)continue;
			if (check(t))f = 1;
		}
		ans += f;
	}
	cout << ans << endl;
}