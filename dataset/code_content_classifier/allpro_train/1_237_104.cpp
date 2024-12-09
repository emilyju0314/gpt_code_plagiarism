#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <complex>
using namespace std;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define mp make_pair
#define ERASE(v,i) (v).erase(remove(all(v),i),(v).end())
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define each(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define debug(x) cerr<<#x<<" = "<<(x)<<endl;
#define LINE cerr<<"LINE: "<<__LINE__<<endl;
inline int toInt(string s){int v;istringstream i(s);i>>v;return v;}
template<class T> inline string toString(T x){ostringstream o;o<<x;return o.str();}
template<class T> void pv(T a,T b){for(T it=a;it!=b;++it)cerr<<*it<<" ";cerr<<endl;}
const int INF = 1000000000;
const double PI = acos(-1.0), EPS = 1e-10;

int years[] = {9, 19, 29, 39, 49, 59, INF};
const int CNT = 7;

inline int stamp(int h, int m) {
	return 60 * h + m;
}

inline int wari(int p) {
	int np = p;
	np /= 2;
	if(np % 50 != 0) np = (np - (np % 50)) + 50;
	return np;
}

// cost[a][b] (b > a)
int cost[7][7] = {
	{0, 300, 500, 600, 700, 1350, 1650},
	{0, 0, 350, 450, 600, 1150, 1500},
	{0, 0, 0, 250, 400, 1000, 1350},
	{0, 0, 0, 0, 250, 850, 1300},
	{0, 0, 0, 0, 0, 600, 1150},
	{0, 0, 0, 0, 0, 0, 500},
	{0, 0, 0, 0, 0, 0, 0}
};

// dist[a][b] (a > b)
int dist[7][7] = {
	{0, 0, 0, 0, 0, 0, 0},
	{6, 0, 0, 0, 0, 0, 0},
	{13, 7, 0, 0, 0, 0},
	{18, 12, 5, 0, 0, 0, 0},
	{23, 17, 10, 5, 0, 0, 0},
	{43, 37, 30, 25, 20, 0, 0},
	{58, 52, 45, 40, 35, 15, 0}
};

int main() {
#if 0
	for(int p; cin >> p;)
		cout << wari(p) << endl;
#endif

#if 1
	for(;;) {

		int from, to, from_t, to_t;
		int h, m;

		cin >> from;

		if(from == 0) break;

		cin >> h >> m;
		from_t = stamp(h, m);

		cin >> to;

		cin >> h >> m;
		to_t = stamp(h, m);

		from--, to--;

		int C = cost[min(from, to)][max(from, to)];
		int D = dist[max(from, to)][min(from, to)];

		if(D <= 40 && (stamp(17, 30) <= from_t && from_t <= stamp(19, 30)) ||
				(stamp(17, 30) <= to_t && to_t <= stamp(19, 30))) {
			C = wari(C);
		}
		cout << C << endl;
	}
#endif

	return 0;
}