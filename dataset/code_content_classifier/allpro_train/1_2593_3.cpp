#include<cstdio>
#include<utility>
#include<map>
#include<complex>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

typedef long double Real;
typedef pair<Real,Real> P;
typedef complex<Real> Point;

void print(Point p, char ch = '\n'){
	printf("%f %f%c", p.real(), p.imag(), ch);
}

const Real epsL = 5e-4;

const Real eps = 1e-8;

template<class T> bool eq_(T a, T b){
	return abs(a - b) < eps;
}

template<class T> bool lt_(T a, T b){
	if(eq_(a, b)) return false;
	return a < b;
}

template<class T> bool le_(T a, T b){
	if(eq_(a, b)) return true;
	return a < b;
}

const Real PI = acos(-1.0);

Real normalize(Real x){
	while(x > PI) x -= PI * 2;
	while(x < -PI) x += PI * 2;
	return x;
}

Point toPt(P p){
	return Point(p.first, p.second);
}

P toP(Point pt){
	return P(pt.real(), pt.imag());
}

struct Circle:vector<Real>{
	vector<P> ps;
	Point c;
	Real r;
	Circle(){}
	Circle(Point p_,Real r_):c(p_),r(r_){}
};

int N;
Circle cs[22];

map<P, P> merged_pts;

void ins_point(Point pt){
	map<P, P>::iterator it = merged_pts.begin();
	P p = toP(pt);
	if(merged_pts.count(p) == 1) return;
	for(; it != merged_pts.end(); ++it){
		Real d = abs(toPt(it->first) - pt);
		P p2 = it->second;
		if(d < epsL){
			merged_pts[p] = p2;
			return;
		}
	}
	merged_pts[p] = p;
}

vector<Real> xs;

void iCC(Circle &c, Circle &c2){
	if(eq_(c.c, c2.c)) return;
	Real d = abs(c.c - c2.c);
	Real r = c.r, r2 = c2.r;
	if(lt_(r + r2, d)) return;//not touch
	else if(eq_(r + r2, d)){//out tangent
		Real ang = normalize(arg(c2.c - c.c));
		c.push_back(ang);
	}else if(lt_(abs(r - r2), d)){
		Real ang = arg(c2.c - c.c);
		Real ang2 = acos((r * r + d * d - r2 * r2) / (2.0 * r * d));
		c.push_back(normalize(ang + ang2));
		c.push_back(normalize(ang - ang2));
	}else if(eq_(abs(r - r2), d)){//in tangent
		if(r > r2){
			c.push_back(normalize(arg(c2.c - c.c)));
		}else{
			c.push_back(normalize(-arg(c2.c - c.c)));
		}
	}else{//contained
		return;
	}
}

void getAllPoints(){
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if(i == j) continue;
			iCC(cs[i], cs[j]);
		}
	}
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < cs[i].size(); ++j){
			Real ang = cs[i][j];
			Point pt = cs[i].c + cs[i].r * Point(cos(ang), sin(ang));
			ins_point(pt);
		}
	}
}

void getPsCircle(Circle &c){
	sort(c.begin(), c.end());
	for(int i = 0; i < c.size(); ++i){
		Real ang = c[i];
		Point pt = c.c + c.r * Point(cos(ang), sin(ang));
		P p = merged_pts[toP(pt)];
		if(c.ps.size() == 0 || c.ps.back() != p){
			if(c.ps.size() != 0 && c.ps[0] == p) continue;
			c.ps.push_back(p);
		}
	}
}

void getPsAll(){
	for(int i = 0; i < N; ++i){
		getPsCircle(cs[i]);
	}
}

void getXs(){
	map<P, P> :: iterator it = merged_pts.begin();
	for(; it != merged_pts.end(); ++it){
		P p = it->second;
		xs.push_back(p.first);
	}
	for(int i = 0; i < N; ++i){
		xs.push_back(cs[i].c.real() - cs[i].r);
		xs.push_back(cs[i].c.real() + cs[i].r);
	}
	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());
}

//map<Real, vector<int> > ys[500];

vector<pair<Real, int> > ys[500];

void getYs(int id){
	Real x = xs[id];
	for(int i = 0; i < N; ++i){
		Circle &c = cs[i];
		if(c.c.real() - c.r == x){
		//	ys[id][c.c.imag()].push_back(i);
			ys[id].push_back(make_pair(c.c.imag(), i));
			ys[id].push_back(make_pair(c.c.imag(), i));
			continue;
		}else if(c.c.real() + c.r == x){
		//	ys[id][c.c.imag()].push_back(i);
			ys[id].push_back(make_pair(c.c.imag(), i));
			ys[id].push_back(make_pair(c.c.imag(), i));
			continue;
		}
		bool flg = false;
		for(int j = 0; j < c.ps.size(); ++j){
			if(c.ps[j].first == x){
				flg = true;
		//		ys[id][c.ps[j].second].push_back(i);
				ys[id].push_back(make_pair(c.ps[j].second, i));
				Real y1 = c.ps[j].second;
				Real y_mid = c.c.imag();
				Real y2 = y_mid * 2.0 - y1;
				ys[id].push_back(make_pair(y2, i));
				break;
			}
		}
		if(!flg){
			if(x < c.c.real() - c.r) continue;
			if(x > c.c.real() + c.r) continue;
			Real dx = abs(x - c.c.real());
			Real dy = sqrt(c.r * c.r - dx * dx);
		//	ys[id][c.c.imag() + dy].push_back(i);
		//	ys[id][c.c.imag() - dy].push_back(i);
			ys[id].push_back(make_pair(c.c.imag() + dy, i));
			ys[id].push_back(make_pair(c.c.imag() - dy, i));
		}
	}
	sort(ys[id].begin(), ys[id].end());
	/*for(int j = 0; j + 1 < ys[id].size(); ++j){
		Real y = ys[id][j].first;
		if(ys[id][j].first != ys[id][j + 1].first) continue;
		P p = P(xs[id], y);
		if(merged_pts.count(p) == 0){
			printf("no\n");
		}
	}*/
	/*printf("ys[%d]\n", id);
	for(int i = 0; i < ys[id].size(); ++i){
		printf("(%f, %d) ", ys[id][i].first, ys[id][i].second);
	}
	printf("\n");*/
}

void getYsAll(){
	for(int i = 0; i < xs.size(); ++i){
		getYs(i);
	}
}

typedef pair<Real, Real> PRR;

vector<PRR> arcs[500];

void getArcs(int id){
	vector<pair<Real, int> > &le = ys[id], &ri = ys[id + 1];
	for(int i = 0; i < N; ++i){
		const Real inf = 1e100;
		Real ly = inf, ry = inf;
		for(int j = 0; j < le.size(); ++j){
			if(le[j].second == i){
				ly = le[j].first;
				break;
			}
		}
		for(int j = 0; j < ri.size(); ++j){
			if(ri[j].second == i){
				ry = ri[j].first;
				break;
			}
		}
		if(ly == inf || ry == inf) continue;
		arcs[id].push_back(PRR(ly, ry));
		ly = inf, ry = inf;
		for(int j = (int)le.size() - 1; j >= 0; --j){
			if(le[j].second == i){
				ly = le[j].first;
				break;
			}
		}
		for(int j = (int)ri.size() - 1; j >= 0; --j){
			if(ri[j].second == i){
				ry = ri[j].first;
				break;
			}
		}
		arcs[id].push_back(PRR(ly, ry));
	}
	sort(arcs[id].begin(), arcs[id].end());
}

struct Region{
	int x_id;
	PRR lo, hi;
	Region(){}
	Region(int i, PRR prr1, PRR prr2){
		x_id = i;
		lo = prr1;
		hi = prr2;
		if(lo > hi) swap(lo, hi);
	}
};

vector<Region> regions;

struct UnionFind{
	int par[20200];
	void init(int N){
		for(int i = 0; i < N; ++i){
			par[i] = i;
		}
	}
	int find(int x){
		if(x == par[x]) return x;
		return par[x] = find(par[x]);
	}
	void unite(int x, int y){
	//	printf("unite %d %d\n", x, y);
		x = find(x), y = find(y);
		if(x == y) return;
		if(x > y) swap(x, y);
		par[y] = x;
	}
	bool same(int x, int y){
		return find(x) == find(y);
	}
};

UnionFind uf;

void getRegions(){
	for(int i = 0; i + 1 < xs.size(); ++i){
		getArcs(i);
	}
	for(int i = 0; i + 1 < xs.size(); ++i){
		for(int j = 0; j + 1 < arcs[i].size(); ++j){
			PRR lo = arcs[i][j];
			PRR hi = arcs[i][j + 1];
			regions.push_back(Region(i, lo, hi));
		}
	}
}

bool checkIntersect(Real l1, Real h1, Real l2, Real h2){
	if(h1 <= l2) return false;
	if(h2 <= l1) return false;
	if(l1 == h1) return false;
	if(l2 == h2) return false;
	return true;
}

void mergeRegions(){
	uf.init(regions.size());
	for(int i = 0; i < regions.size(); ++i){
		Region r = regions[i];
		for(int j = i - 1; j >= 0; --j){
			Region cur = regions[j];
			if(cur.x_id <= r.x_id - 2) break;
			if(cur.x_id == r.x_id) continue;
			bool flg = checkIntersect(r.lo.first, r.hi.first, cur.lo.second, cur.hi.second);
			if(flg){
				uf.unite(i, j);
			}
		}
		for(int j = i + 1; j < regions.size(); ++j){
			Region cur = regions[j];
			if(cur.x_id >= r.x_id + 2) break;
			if(cur.x_id == r.x_id) continue;
			bool flg = checkIntersect(r.lo.second, r.hi.second, cur.lo.first, cur.hi.first);
			if(flg){
				uf.unite(i, j);
			}
		}
	}
}

vector<int> G[20200];
bool is_valid[20200];

void getGraphVertices(){
	for(int i = 1; i < regions.size(); ++i){
		is_valid[i] = (uf.find(i) == i);
	//	if(is_valid[i]) printf("valid: %d\n", i);
	}
}

void getGraphEdges(){
	for(int i = 0; i + 1 < regions.size(); ++i){
		Region r1 = regions[i], r2 = regions[i + 1];
		if(r1.x_id != r2.x_id) continue;
		int u = uf.find(i), v = uf.find(i + 1);
		if(u == 0 || v == 0) continue;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 0; i < regions.size(); ++i){
		sort(G[i].begin(), G[i].end());
		G[i].erase(unique(G[i].begin(), G[i].end()), G[i].end());
	}
}

void getGraph(){
	getGraphVertices();
	getGraphEdges();
}

int match[20200];
bool used[20200];

vector<int> valid_vs;
/*
bool dfs(int v, int p){
	used[v] = true;
	if(match[v] == -1 && p != -1){
		match[v] = p;
		return true;
	}
	if(match[v] == p){
		for(int i = 0; i < G[v].size(); ++i){
			int u = G[v][i];
			if(used[u]) continue;
			bool flg = dfs(u, v);
			if(flg){
				match[v] = u;
				return true;
			}
		}
	}else{
		int u = match[v];
		if(used[u]) return false;
		bool flg = dfs(u, v);
		if(flg){
			match[v] = p;
			return true;
		}
	}
	return false;
}*/

bool dfs(int v){
	used[v] = true;
	for(int i = 0; i < G[v].size(); ++i){
		int u = G[v][i];
		if(used[u]) continue;
		int w = match[u];
		if(w == -1){
			match[u] = v;
			match[v] = u;
			return true;
		}
		if(used[w]) continue;
		bool flg = dfs(w);
		if(flg){
			match[u] = v;
			match[v] = u;
			return true;
		}
	}
	return false;
}

int bipartiteMatching(){
	for(int i = 1; i < 20200; ++i){
		match[i] = -1;
		if(is_valid[i]){
			valid_vs.push_back(i);
		}
	}
	/*for(int i = 0; i < valid_vs.size(); ++i){
		printf("%d:", valid_vs[i]);
		for(int j = 0; j < G[valid_vs[i]].size(); ++j){
			printf("%d ", G[valid_vs[i]][j]);
		}
		printf("\n");
	}*/
	int res = 0;
	for(int i = 0; i < valid_vs.size(); ++i){
		int v = valid_vs[i];
		if(match[v] != -1) continue;
		for(int j = 0; j < valid_vs.size(); ++j){
			used[valid_vs[j]] = false;
		}
		bool flg = dfs(v);
		if(flg) res++;
	}
	//printf("match = %d\n", res);
	return res;
}

int K;

void rotAll(){
	Point r = Point(cos(1), sin(1));
	for(int i = 0; i < N; ++i){
		cs[i].c *= r;
	}
}

int solve(){
	rotAll();
	/*for(int i = 0; i < N; ++i){
		print(cs[i].c, ' ');
		printf("%f\n", cs[i].r);
	}*/
	getAllPoints();
	getPsAll();
	getXs();
	getYsAll();
	getRegions();
	mergeRegions();
	getGraph();
/*	for(int i = 0; i < xs.size(); ++i){
		printf("%f ", xs[i]);
	}
	printf("\n");
	for(int i = 0; i < regions.size(); ++i){
		Region r = regions[i];
		printf("x_id = %d\n", r.x_id);
		printf("%f %f %f %f\n", r.lo.first, r.lo.second, r.hi.first, r.hi.second);
	}*/
	int V = 0;
	for(int i = 0; i < 20200; ++i){
		if(is_valid[i]){
			V++;
		}
	}
	if(K >= 2){
		return V;
	}
	int ans = V - bipartiteMatching();
	return ans;
}

void input(){
	scanf("%d%d", &N, &K);
	for(int i = 0; i < N; ++i){
		int x, y, r;
		scanf("%d%d%d", &x, &y, &r);
		cs[i] = Circle(Point(x, y), r);
	}
	cs[N] = Circle(Point(0, 0), 5000);
	N++;
}

int main(){
	input();
	int ans = solve();
	printf("%d\n", ans);
	return 0;
}

/*
void iCC(Circle &c,Circle &c2){
	if(eq(c.c,c2.c)) return;
	Real d=abs(c.c-c2.c);
	Real r=c.r,r2=c2.r;
	if(sgn(d-(r+r2))>0) return;
	else if(sgn(d-(r+r2))==0){//out tangent
		Real ang=normalize(arg(c2.c-c.c));
		c.push_back(ang);
	}else if(sgn(d-abs(r-r2))>0){//intersect two points
		Real ang=arg(c2.c-c.c);
		Real ang2=acos((r*r+d*d-r2*r2)/(2*r*d));
		c.push_back(normalize(ang+ang2));
		c.push_back(normalize(ang-ang2));
	}else if(sgn(d-abs(r-r2))==0){//in tangent
		if(r>r2){
			c.push_back(normalize(arg(c2.c-c.c)));
		}else{
			c.push_back(normalize(-arg(c2.c-c.c)));
		}
	}else{//contained
		return;
	}
}*/