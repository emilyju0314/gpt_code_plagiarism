#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>
using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
	v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
	stringstream ss;
	ss << f;
	ss >> t;
}


#define REP(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define PB push_back
#define ITR ::iterator


#define MOD 1000000009LL
#define EPS 1e-8

typedef double D;
typedef complex<D> P;
typedef const P &rP;
typedef vector<P> polygon;
typedef const polygon &rpolygon;

typedef pair<D,int> pdi;

inline D dot(rP a, rP b){
	return real(a) * real(b) + imag(a) * imag(b);
}

inline D cross(rP a, rP b){
	return real(a) * imag(b) - imag(a) * real(b);
}

inline int ccw(rP a, P b, P c) {
	b -= a;
	c -= a;
	D cr = cross(b, c);
	if (cr > EPS){ return +1; }	// counter clockwise
	if (cr < -EPS){ return -1; }	// clockwise
	if (dot(b, c) < -EPS){ return +2; }	// c--a--b on line
	if (abs(b) + EPS < abs(c)){ return -2; }	// a--b--c on line
	return 0;
}

D distanceLP(rP a, rP b, rP c){
	return abs(cross(b - a, c - a)) / abs(b - a);
}

D distanceLsP(rP a, rP b, rP c){
	if( dot(b - a, c - a) <= 0.0 ) return abs(c - a);
	if( dot(a - b, c - b) <= 0.0 ) return abs(c - b);
	return distanceLP(a, b, c);
}

bool containsPlgP(rpolygon plg, rP pt){
	int cnt = 0;
	D y = imag(pt);
	for(int i = 0; i < plg.size(); ++i){
		int j = (i + 1 == plg.size() ? 0: i + 1);
		if( distanceLsP(plg[i], plg[j], pt) <= EPS ){
			return true;
		}
		D dyi = imag(plg[i]) - y;
		D dyj = y - imag(plg[j]);
		D tx = (dyi * real(plg[j]) + dyj * real(plg[i])) / (dyi + dyj);
		if(imag(plg[i]) >= y && imag(plg[j]) < y){
			if( tx < real(pt) ) ++cnt;
		}
		else if(imag(plg[i]) < y && imag(plg[j]) >= y){
			if( tx < real(pt) ) ++cnt;
		}
	}
	return (cnt % 2 != 0);
}

D divrat(rP pa1, rP pa2, rP pb1, rP pb2){
	P da12 = pa2 - pa1;
	P db21 = pb1 - pb2;
	P dab1 = pb1 - pa1;
	D d = cross(da12, db21);
	if(abs(d) > EPS){
		D t = cross(dab1, db21) / d;
		D s = cross(da12, dab1) / d;
		
		if((-EPS < t && t < 1.0 + EPS) && (-EPS < s && s < 1.0 + EPS)){
			return t;	//前半は交点が線分1に含まれるか、後半は線分2に含まれるかどうか
		}
	}
	return DBL_MAX;
}

bool containsPlgS(rpolygon plg, rP a, rP b){
	int n = plg.size();
	vector<D> r(2);
	r[1] = 1.0;
	P dif = b - a;
	for(int i = 0; i < n; ++i){
		D t = divrat(a, b, plg[i], plg[(i + 1) % n]);
		if(t < DBL_MAX){ r.push_back(t); }
	}
	sort(ALL(r));
	for(int i = 1; i < r.size(); ++i){
		if(!containsPlgP(plg, a + 0.5 * (r[i] + r[i - 1]) * dif)){
			return false;
		}
	}
	return true;
}


P input(){
	D x, y;
	scanf("%lf%lf", &x, &y);
	return P(x, y);
}

void mirror(rP pl1, rP pl2, P &p){
	P d = pl2 - pl1;
	d /= abs(d);
	P a = pl1 - p;
	a -= dot(a, d) * d;
	p += 2.0 * a;
}

D solve(int n){
	int m;
	P ps, pg, pl1, pl2;
	vector<polygon> blds(n), plgs;
	plgs.reserve(5);
	for(int i = 0; i < n; ++i){
		scanf("%d", &m);
		blds[i].resize(m);
		for(int j = 0; j < m; ++j){
			blds[i][j] = input();
		}
	}
	ps = input();
	pg = input();
	pl1 = input();
	pl2 = input();

	if(ccw(pl1, pl2, ps) == -1){
		swap(pl1, pl2);
	}

	for(int i = 0; i < n; ++i){
		if(ccw(pl1, pl2, blds[i][0]) == -1){
			for(int j = 0; j < blds[i].size(); ++j){
				mirror(pl1, pl2, blds[i][j]);
			}
		}

		if(containsPlgP(blds[i], ps) || containsPlgP(blds[i], pg)){
			plgs.push_back(blds[i]);
		}
	}
	if(plgs.size() != 2){ return DBL_MAX; }
	
	vector<P> pts;
	pts.push_back(ps);
	pts.push_back(pg);
	for(int i = 0; i < 2; ++i){
		pts.insert(pts.end(), ALL(plgs[i]));
	}
	
	vector<vector<pdi> > G(pts.size());
	for(int i = 1; i < pts.size(); ++i)
	for(int j = 0; j < i; ++j){
		bool ok = true;
		for(int k = 0; k < 2; ++k){
			if(!containsPlgS(plgs[k], pts[i], pts[j])){
				ok = false;
				break;
			}
		}
		if(ok){
			D ds = abs(pts[i] - pts[j]);
			G[i].push_back(pdi(ds, j));
			G[j].push_back(pdi(ds, i));
		}
	}
	
	vector<D> d(pts.size(), DBL_MAX);
	d[0] = 0.0;
	priority_queue<pdi,vector<pdi>,greater<pdi> > pq;
	pq.push(pdi());
	while(!pq.empty()){
		D a = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if(d[u] != a){ continue; }

		for(int i = 0; i < G[u].size(); ++i){
			D b = a + G[u][i].first;
			int v = G[u][i].second;
			if(d[v] > b){
				d[v] = b;
				pq.push(pdi(b, v));
			}
		}
	}
	
	return d[1];
}


int main(){
	int n;
	while(scanf("%d", &n), n){
		D ans = solve(n);
		if(ans < DBL_MAX){
			printf("%.15f\n", ans);
		}
		else{
			puts("impossible");
		}
	}
}