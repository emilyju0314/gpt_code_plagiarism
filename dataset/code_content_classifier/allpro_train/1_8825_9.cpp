#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>
#include <deque>
#include <complex>
#include <string>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <valarray>
#include <iterator>
using namespace std;
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
#define ALL(container) container.begin(), container.end()
#define RALL(container) container.rbegin(), container.rend()
#define SZ(container) ((int)container.size())
#define mp(a,b) make_pair(a, b)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

const int INF = 1<<29;
const double EPS = 1e-8;
const int MOD = 1000000007;

class BIT2D {
	int h, w;
	vector<vi> vs;
public:
	BIT2D(int W, int H): vs(H, vi(W, -INF)){
		h = H;
		w = W;
	}
	//O(log n)
	void update(int X, int Y, int a) {
		for(int y = Y; y < h; y |= y + 1)
			for(int x = X; x < w; x |= x + 1) vs[y][x] = max(vs[y][x], a);
	}
	//[s,t)	O(log n)
	int query(int tx, int ty) {
		int res = -INF;
		for(int y = ty - 1; y >= 0; y = (y & (y + 1)) - 1)
			for(int x = tx - 1; x >= 0; x = (x & (x + 1)) - 1){
				res = max(res, vs[y][x]);
			}
		return res;
	}
};

int N, V, Xl, Xr;

struct Mogura{
	ll x, y, p;
	Mogura(int X, int T, int P){
		x = T-X;
		y = T+X;
		p = P;
	}
	Mogura(){}
	bool operator <(const Mogura &opp) const {
		return x != opp.x ? x < opp.x : y < opp.y;
	}
};

int main(){
	scanf("%d%d%d%d", &N, &V, &Xl, &Xr);
	vector<Mogura> mog;
	vector<int> ItoP;
	ItoP.push_back(Xl);
	ItoP.push_back(Xr);
	REP(i, N){
		int x, t, p;
		scanf("%d%d%d", &x, &t, &p);
		mog.emplace_back(x, V*t, p);
		ItoP.push_back(mog.back().y);
	}
	sort(ALL(mog));
	sort(ALL(ItoP));
	UNIQUE(ItoP);
	int n = ItoP.size();
	unordered_map<int, int> PtoI;
	REP(i, n) PtoI[ItoP[i]] = i;
	BIT2D bit(n, n);
	bit.update(PtoI[Xl], PtoI[Xr], 0);
	REP(i, N){
		int x = PtoI[mog[i].y];
		int p = mog[i].p;
		RREP(j, n){
			if(j > x && -Xl <= mog[i].x){
				// 左手が x 右手が j
				int my = bit.query(x+1, j+1);
				bit.update(x, j, my + p);
			}else if(j <= x && -Xr <= mog[i].x){
				// 左手が j 右手が x
				int mx = bit.query(j+1, x+1);
				bit.update(j, x, mx + p);
			}
		}
	}
	cout << bit.query(n, n) << endl;
	return 0;
}