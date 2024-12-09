#include <bits/stdc++.h>

using namespace std;

namespace geometry
{	
	typedef double D;
	typedef complex<D> P;
	typedef pair<P, P> S;
	typedef S L;
	typedef pair<P, D> C;
	
	#define EPS 		(1e-10)
	#define EQ(a, b) 	(abs((a) - (b)) < EPS)
	#define EQV(a, b) 	(EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()))
	
	static const int COUNTER_CLOCKWISE 	=  1;
	static const int CLOCKWISE			= -1;
	static const int ONLINE_BACK		=  2;
	static const int ONLINE_FRONT		= -2;
	static const int ON_SEGMENT			=  0;
	
	bool cmp(const P& a, const P& b){
		if (a.real() != b.real()) return a.real() < b.real();
		return a.imag() < b.imag();
	}
	
	void debug(P p){
		printf("x: %f, y: %f\n", p.real(), p.imag()); 
	}
	void debug(C c){
		printf("x: %f, y: %f, r: %f\n", c.first.real(), c.first.imag(), c.second);
	}
	void debug(S s){
		printf("{\n");
		printf("    ");
		debug(s.first);
		printf("    ");
		debug(s.second);
		printf("}\n");
	}
	void debug(vector<P> poly){
		printf("{\n");
		for (int i = 0; i < poly.size(); i++){
			printf("    ");
			debug(poly[i]);
		}
		printf("}\n");
	}
	
	D norm(P a) { return a.real() * a.real() + a.imag() * a.imag(); }
	
	D dot(P a, P b) { return a.real() * b.real() + a.imag() * b.imag(); }
	D cross(P a, P b) { return a.real() * b.imag() - a.imag() * b.real(); }
	
	bool isOrthogonal(P a1, P a2, P b1, P b2) { return EQ(dot(a1 - a2, b1 - b2), 0.0); }
	bool isOrthogonal(L a, L b) { return isOrthogonal(a.first, a.second, b.first, b.second); }
	bool isParallel(P a1, P a2, P b1, P b2) { return EQ(cross(a1 - a2, b1 - b2), 0.0); }
	bool isParallel(L a, L b) { return isParallel(a.first, a.second, b.first, b.second); }
	
	bool isPointOnLine(P a, P b, P c) { return EQ(cross(b - a, c - a), 0.0); }
	bool isPointOnLine(L a, P b) { return isPointOnLine(a.first, a.second, b); }
	bool isPointOnSegment(P a, P b, P c) {
		return EQ(cross(b - a, c - a), 0.0) &&
		       (dot(b - a, c - a) > -EPS) &&
			   (dot(a - b, c - b) > -EPS);
	}
	bool isPointOnSegment(S a, P b) { return isPointOnLine(a.first, a.second, b); }
	
	int ccw(P p0, P p1, P p2){
		P a = p1 - p0;
		P b = p2 - p0;
		if (cross(a, b) > EPS) 	return COUNTER_CLOCKWISE;
		if (cross(a, b) < -EPS) return CLOCKWISE;
		if (dot(a, b) < -EPS)	return ONLINE_BACK;
		if (norm(a) < norm(b))	return ONLINE_FRONT;
		return ON_SEGMENT;
	}
	
	bool intersect(P p1, P p2, P p3, P p4){
		return ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
		       ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
	}
	bool intersect(S s1, S s2){
		return intersect(s1.first, s1.second, s2.first, s2.second);
	}
	
	D distanceLP(P a, P b, P c) { return abs(cross(b - a, c - a)) / abs(b - a); }
	D distanceLP(L a, P b) { return distanceLP(a.first, a.second, b); }
	D distanceSP(P a, P b, P c) {
		if (dot(b - a, c - a) < EPS) return abs(c - a);
		if (dot(a - b, c - b) < EPS) return abs(c - b);
		return abs(cross(b - a, c - a)) / abs(b - a);
	}
	D distanceSP(S a, P b) { return distanceSP(a.first, a.second, b); }
	D distanceCS(C c, S s){
		return distanceSP(s, c.first) - c.second;
	}
	
	bool intersectCL(C c, L l){
		return c.second - distanceLP(l, c.first) > -EPS;
	}
	bool intersectCS(C c, S s){
		if (EQ(c.second - abs(c.first - s.first), 0.0) ||
			EQ(c.second - abs(c.first - s.second), 0.0)) return true;
		if (c.second - distanceSP(s, c.first) > -EPS){
			return (c.second - abs(c.first - s.first) < EPS ||
				    c.second - abs(c.first - s.second) < EPS);
		}
		return false;
	}
	
	P project(S s, P p){
		P base = s.second - s.first;
		D r = dot(p - s.first, base) / norm(base);
		return s.first + base * r;
	}
	P reflect(S s, P p){
		return p + (project(s, p) - p) * (D)2.0;
	}
	
	P crossPoint(S s1, S s2){
		P base = s2.second - s2.first;
		D d1 = abs(cross(base, s1.first - s2.first));
		D d2 = abs(cross(base, s1.second - s2.first));
		D t = d1 / (d1 + d2);
		return s1.first + (s1.second - s1.first) * t;
	}
	
	D area(vector<P> poly){
		if (poly.size() < 3) return 0.0;
		D res = 0.0;
		for (int i = 1; i < poly.size() - 1; i++){
			P v1 = poly[i] - poly[0];
			P v2 = poly[i + 1] - poly[0];
			res += abs(cross(v1, v2)) / 2;
		}
		return res;
	}
	
	pair<P, P> crossPoints(C c, L l){
		P pr = project(l, c.first);
		P e = (l.second - l.first) / abs(l.second- l.first);
		D base = sqrt(c.second * c.second - norm(pr - c.first));
		return make_pair(pr + e * base, pr - e * base);
	}
	
	bool intersect(C c1, C c2){
		return abs(c1.first - c2.first) - c1.second - c2.second < EPS;
	}
	
	pair<P, P> crossPoints(C c1, C c2){
		D d = abs(c1.first - c2.first);
		D a = acos((c1.second * c1.second + d * d - c2.second * c2.second) / (2 * c2.second * d));
		D t = arg(c2.first - c1.first);
		return make_pair(c1.first + polar(c1.second, t + a), c1.first + polar(c1.second, t - a));
	}
	
	vector<P> convexHull(vector<P> s){
		if (s.size() < 3) return s;
		vector<P> u, l;
		sort(s.begin(), s.end(), cmp);
		u.push_back(s[0]);
		u.push_back(s[1]);
		l.push_back(s[s.size() - 1]);
		l.push_back(s[s.size() - 2]);
		for (int i = 2; i < s.size(); i++){
			for (int n = u.size(); n >= 2 && ccw(u[n - 2], u[n - 1], s[i]) != CLOCKWISE/* && ccw(u[n - 2], u[n - 1], s[i]) != ONLINE_FRONT*/; n--){
				u.pop_back();
			}
			u.push_back(s[i]);
		}
		for (int i = s.size() - 3; i >= 0; i--){
			for (int n = l.size(); n >= 2 && ccw(l[n - 2], l[n - 1], s[i]) != CLOCKWISE/* && ccw(l[n - 2], l[n - 1], s[i]) != ONLINE_FRONT*/; n--){
				l.pop_back();
			}
			l.push_back(s[i]);
		}
		reverse(l.begin(), l.end());
		for (int i = u.size() - 2; i >= 1; i--){
			l.push_back(u[i]);
		}
		return l;
	}
}

using namespace geometry;

int main()
{
	int n;
	while (scanf("%d", &n), n){
		vector<C> cs;
		for (int i = 0; i < n; i++){
			D a, b;
			scanf("%lf,%lf", &a, &b);
			cs.push_back( C( P(a, b), 1.0 ) );
		}
		
		int res = 1;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (i == j) continue;
				if (!intersect(cs[i], cs[j])) continue;
				pair<P, P> cp = crossPoints(cs[i], cs[j]);
				P ps[2] = {cp.first, cp.second};
				for (int p = 0; p < 2; p++){
					int cnt = 2;
					for (int k = 0; k < n; k++){
						if (i == k || j == k) continue;
						if (abs(cs[k].first - ps[p]) < 1.0 + EPS){
							cnt++;
						}
					}
					res = max(res, cnt);
				}
			}
		}
		printf("%d\n", res);
	}
}