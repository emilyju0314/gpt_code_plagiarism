#include <bits/stdc++.h>
using namespace std;

mt19937 mt(48);

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

using ld = long double;

template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T _x=0, T _y=0) : x(_x), y(_y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	ld dist() const { return sqrt((ld)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	ld angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(ld a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
};

using P = Point<ll>;

using Pd = Point<ld>;

template <class P>
bool sameDir(P s, P t) {
	return s.cross(t) == 0 && s.dot(t) > 0;
}
// checks 180 <= s..t < 360?
template <class P>
bool isReflex(P s, P t) {
	auto c = s.cross(t);
	return c ? (c < 0) : (s.dot(t) < 0);
}
// operator < (s,t) for angles in [base,base+2pi)
template <class P>
bool angleCmp(P base, P s, P t) {
	int r = isReflex(base, s) - isReflex(base, t);
	return r ? (r < 0) : (0 < s.cross(t));
}
// is x in [s,t] taken ccw? 1/0/-1 for in/border/out
template <class P>
int angleBetween(P s, P t, P x) {
	if (sameDir(x, s) || sameDir(x, t)) return 0;
	return angleCmp(s, x, t) ? 1 : -1;
}

template<class P>
bool segmentIntersectionQ(P s1, P e1, P s2, P e2) {
	if (e1 == s1) {
		if (e2 == s2) return e1 == e2;
		swap(s1,s2); swap(e1,e2);
	}
	P v1 = e1-s1, v2 = e2-s2, d = s2-s1;
	auto a = v1.cross(v2), a1 = d.cross(v1), a2 = d.cross(v2);
	if (a == 0) { // parallel
		auto b1 = s1.dot(v1), c1 = e1.dot(v1),
		     b2 = s2.dot(v1), c2 = e2.dot(v1);
		return !a1 && max(b1,min(b2,c2)) <= min(c1,max(b2,c2));
	}
	if (a < 0) { a = -a; a1 = -a1; a2 = -a2; }
	return (0 <= a1 && a1 <= a && 0 <= a2 && a2 <= a);
}

template<class P>
int lineIntersection(const P& s1, const P& e1, const P& s2,
		const P& e2, P& r) {
	if ((e1-s1).cross(e2-s2)) { //if not parallell
		r = s2-(e2-s2)*(e1-s1).cross(s2-s1)/(e1-s1).cross(e2-s2);
		return 1;
	} else
		return -((e1-s1).cross(s2-s1)==0 || s2==e2);
}

template<class P>
bool onSegment(const P& s, const P& e, const P& p) {
	P ds = p-s, de = p-e;
	return ds.cross(de) == 0 && ds.dot(de) <= 0;
}

template<class It, class P>
bool insidePolygon(It begin, It end, const P& p,
		bool strict = true) {
	int n = 0; //number of isects with line from p to (inf,p.y)
	for (It i = begin, j = end-1; i != end; j = i++) {
		//if p is on edge of polygon
		if (onSegment(*i, *j, p)) return !strict;
		//or: if (segDist(*i, *j, p) <= epsilon) return !strict;
		//increment n if segment intersects line from p
		n += (max(i->y,j->y) > p.y && min(i->y,j->y) <= p.y &&
				((*j-*i).cross(p-*i) > 0) == (i->y <= p.y));
	}
	return n&1; //inside if odd number of intersections
}


vector<Pd> polygonCut(const vector<Pd>& poly, Pd s, Pd e) {
	vector<Pd> res;
	rep(i,0,sz(poly)) {
		Pd cur = poly[i], prev = i ? poly[i-1] : poly.back();
		bool side = s.cross(e, cur) < 0;
		if (side != (s.cross(e, prev) < 0)) {
			res.emplace_back();
			lineIntersection(s, e, cur, prev, res.back());
		}
		if (side)
			res.push_back(cur);
	}
	return res;
}

template<class T>
T polygonArea2(vector<Point<T>>& v) {
	if(v.empty()) return 0;
	T a = v.back().cross(v[0]);
	rep(i,0,sz(v)-1) a += v[i].cross(v[i+1]);
	return a;
}

const ld eps = 1e-10;

struct Line {
	Pd P1, P2;
	// Right hand side of the ray P1 -> P2
	explicit Line(Pd a = Pd(), Pd b = Pd()) : P1(a), P2(b) {};
	Pd intpo(Line y) {
		Pd r;
		assert(lineIntersection(P1, P2, y.P1, y.P2, r) == 1);
		return r;
	}
	Pd dir() {
		return P2 - P1;
	}
	bool contains(Pd x) {
		return (P2 - P1).cross(x - P1) < eps;
	}
	bool out(Pd x) {
		return !contains(x);
	}
}; 

template<class T>
bool mycmp(Point<T> a, Point<T> b) {
	// return atan2(a.y, a.x) < atan2(b.y, b.x);
	if (a.x * b.x < 0)	return a.x < 0;
	if (abs(a.x) < eps) {
		if (abs(b.x) < eps) 	return a.y > 0 && b.y < 0;
		if (b.x < 0)	return a.y > 0;
		if (b.x > 0)	return true;
	}
	if (abs(b.x) < eps) {
		if (a.x < 0)	return b.y < 0;
		if (a.x > 0)	return false;
	}
	return a.cross(b) > 0;
}

bool cmp(Line a, Line b) {
	return mycmp(a.dir(), b.dir());
}

ld Intersection_Area(vector <Line> b) {
	sort(b.begin(), b.end(), cmp);
	int n = b.size();
	int q = 1, h = 0, i;
	vector <Line> c(b.size() + 10);
	for (i = 0; i < n; i++) {
		while (q < h && b[i].out(c[h].intpo(c[h - 1])))	h--;
		while (q < h && b[i].out(c[q].intpo(c[q + 1])))	q++;
		c[++h] = b[i];
		if (q < h && abs(c[h].dir().cross(c[h - 1].dir())) < eps) {
			h--;
			if (b[i].out(c[h].P1))	c[h] = b[i];
		}
	}
	while (q < h - 1 && c[q].out(c[h].intpo(c[h - 1])))	h--;
	while (q < h - 1 && c[h].out(c[q].intpo(c[q + 1])))	q++;
	// Intersection is empty. This is sometimes different from the case when
	// the intersection area is 0. 
	if (h - q <= 1)	return 0;
	c[h + 1] = c[q];
	vector <Pd> s;
	for (i = q; i <= h; i++)	s.push_back(c[i].intpo(c[i + 1]));
	s.push_back(s[0]);
	ld ans = 0;
	for (i = 0; i < (int) s.size() - 1; i++) ans += s[i].cross(s[i + 1]);
	return ans / 2;
}

vector<vector<pair<P, int> > > tri;

void decompose(vector<pair<P, int> > polygon){
	int n = (int)polygon.size();
	if(n == 3){
		tri.push_back(polygon);
		return;
	}

	for(int i = 0; i < n; i++){
		for(int j = i + 2; j < n; j++){
			if(i == 0 && j == n - 1) continue;
			{
				P f = polygon[(i+1) % n].first - polygon[i].first;
				P b = polygon[(i+n-1) % n].first  - polygon[i].first;
				P t = polygon[j].first  - polygon[i].first ;
				if(angleCmp(f, b, t) || sameDir(f, t) || sameDir(b,  t)) continue;
			}
			{
				P f = polygon[(j+1) % n].first  - polygon[j].first;
				P b = polygon[(j+n-1) % n].first  - polygon[j].first;
				P t = polygon[i].first  - polygon[j].first ;
				if(angleCmp(f, b, t) || sameDir(f, t) || sameDir(b,  t)) continue;
			}
			bool works = true;
			for(int z = 0; z < n; z++){
				if(z == i || z == j || (z == (i+n-1) % n) || z == (j+n-1) % n) continue;
				if(segmentIntersectionQ(polygon[z].first, polygon[(z+1)%n].first, polygon[i].first, polygon[j].first)){
					works = false;
					break;
				}
			}
			if(!works) continue;
			vector<pair<P, int> > p1, p2;
			for(int r = i; r <= j; r++) p1.push_back(polygon[r]);
			for(int r = j; r < n; r++) p2.push_back(polygon[r]);
			for(int r = 0; r <= i; r++) p2.push_back(polygon[r]);
			decompose(p1);
			decompose(p2);
			return;
		}
	}
	assert(false);
}

Pd to_double(P p){
	return Pd(p.x, p.y);
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<P> p(n);
	for(int i = 0; i < n; i++){
		cin >> p[i].x >> p[i].y;
	}
	// decompose into triangles

	vector<pair<P, int> > point_with_idx;
	for(int i = 0; i < n; i++){
		point_with_idx.push_back({p[i], i});
	}
	decompose(point_with_idx);

	vector<vector<Pd> > cuts;
	vector<int> cut_start, cut_end1, cut_end2;
	for(int i = 0; i < n; i++){
		// decide polygons;
		// intersect ray from i, i+1 -> 
		if((p[(i+2)%n] - p[(i+1)%n]).cross(p[i] - p[(i+1)%n]) > 0) continue;
		ld best_ratio = 1e15;
		int best_z = -1;
		P f = p[i];
		P g = p[(i+1)%n];
		for(int z = 0; z < n; z++){
			if(z == i || z == (i+1)%n) continue;
			P p1 = p[z];
			P p2 = p[(z+1)%n];
			if((p1-f).cross(g-f) * (p2-f).cross(g-f) > 0) continue;
			if((p1-p2).cross(g-f) == 0) continue;
			if((g-f).cross(g-p1) == 0) continue;
			ld A1 = (p1-g).cross(p2-g);
			ld A2 = (p1-f).cross(p2-f) - A1;
			ld ratio = A1 / A2;
			if(ratio <= 0) continue;
			if(ratio < best_ratio){
				best_ratio = ratio;
				best_z = z;
				assert(z != (i+n-1) % n);
			}
		}
		assert(best_z >= 0);
		vector<Pd> pp;
		Pd pf = to_double(p[i]);
		Pd pg = to_double(p[(i+1)%n]);
		pp.push_back(pg);
		pp.push_back(pg + (pg - pf) * best_ratio);
		cuts.push_back(pp);
		cut_start.push_back((i+1)%n);
		if((f - g).cross(g - p[(best_z+1)%n]) == 0){
			cut_end1.push_back((best_z+1)%n);
		} else {
			cut_end1.push_back(best_z);
		}
		cut_end2.push_back((best_z+1)%n);
	}
	ld ans = 0;
	for(vector<pair<P, int> > st: tri){
		vector<int> tri_idx;
		for(auto q : st) tri_idx.push_back(q.second);

		vector<Line> half_planes;
		half_planes.push_back(Line(to_double(st[0].first), to_double(st[2].first)));
		half_planes.push_back(Line(to_double(st[1].first), to_double(st[0].first)));
		half_planes.push_back(Line(to_double(st[2].first), to_double(st[1].first)));
		bool failed = false;
		for(int i_cut = 0; i_cut < (int)cuts.size(); i_cut++){
			vector<Pd> cut = cuts[i_cut];
			int a = cut_start[i_cut];
			int b = cut_end1[i_cut];
			int c = cut_end2[i_cut];
			bool has_inside = false;
			bool has_outside = false;
			for(int r : tri_idx){
				if((r - b + n) % n > 0 && (r - b + n) % n < (a - b + n) % n){
					has_outside = true;
				}
				if((r - a + n) % n > 0 && (r - a + n) % n < (c - a + n) % n){				
					has_inside = true;
				}
			}
			if(!has_inside) continue;
			if(!has_outside) failed = true;
			half_planes.push_back(Line(cut.back(), cut.front()));
		}
		if(failed) continue;
		ld area = Intersection_Area(half_planes);
		ans += area;
	}
	cout << fixed << setprecision(15);
	cout << ans << '\n';
}
