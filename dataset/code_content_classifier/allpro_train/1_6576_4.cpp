#include <cstdio>
#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <queue>
#include <cfloat>
#include <functional>
#include <cassert>
using namespace std;

#define EPS 1e-8

typedef double D;
typedef complex<D> P;
typedef const P &rP;
typedef vector<D> vD;
typedef pair<D,int> pdi;

const D pi = acos(-1.0);
const P iu(0.0, 1.0);

D dot(rP a, rP b){
	return real(a) * real(b) + imag(a) * imag(b);
}

D cross(rP a, rP b){
	return real(a) * imag(b) - imag(a) * real(b);
}

P intersect(rP a, rP va, rP b, rP vb){
	P vab = b - a;
	D t = cross(vb, vab) / cross(vb, va);
	return a + t * va;
}

vD comtang(rP c1, D r1, P c2, D r2, bool out){
	vD ret;
	c2 -= c1;
	if(norm(c2) > EPS){
		D sgn = (out ? -1.0 : 1.0);
		D s = (r1 + sgn * r2) / abs(c2);
		if(abs(s) < 1.0 + EPS){
			if(s > 1.0){ s = 1.0; }
			else if(s < -1.0){ s = -1.0; }
			D a = arg(c2), b = asin(s) - 0.5 * pi;
			ret.resize(2);
			ret[0] = a - b;
			ret[1] = a + b;
		}
	}
	return ret;
}

struct comparer{
	bool operator() (D x, D y) const{
		return x < y - EPS;
	}
};

struct arcinfo{
	P cen;
	D rd, af, al;
	map<D,int,comparer> mp;

	arcinfo(rP p1, rP p2, rP p3, rP p4){
		P va = p2 - p1, vb = p4 - p3;
		if(abs(cross(va, vb)) < EPS){
			cen = 0.5 * (p2 + p3);
		}
		else{
			cen = intersect(p2, va * iu, p3, vb * iu);
		}
		rd = abs(p2 - cen);

		af = arg(p2 - cen);
		al = arg(p3 - cen);
		if(cross(va, cen - p2) < 0.0){
			swap(af, al);
		}
		af += 8.0 * pi;
		while(al < af){ al += 2.0 * pi; }
	}

	bool check(D &a) const{
		while(a < af - EPS){ a += 2.0 * pi; }
		if(a > al + EPS){ return false; }
		if(a < af){ a = af; }
		if(a > al){ a = al; }
		return true;
	}
	
	P point(double a) const{
		return cen + polar(rd, a);
	}
};

struct edgeinfo{
	int f, t;
	D len;
};

vector<arcinfo> arcs;
int V;

int getid(int t, D a){
	if(!arcs[t].mp.count(a)){
		arcs[t].mp[a] = V;
		V += 2;
	}
	return arcs[t].mp[a];
}


int main(){
	int n;
	vector<P> pts;
	double x, y;
	scanf("%d", &n);
	for(int i = 0; i < 2 * n; ++i){
		scanf("%lf%lf", &x, &y);
		pts.push_back(P(x, y));
	}

	arcs.reserve(n);
	int k = 2 * n - 2;
	for(int i = 0; i < 2 * n; i += 2){
		arcs.push_back(arcinfo(pts[k], pts[k+1], pts[i], pts[i+1]));
		k = i;
	}

	vector<edgeinfo> E;
	for(int i = 0; i < arcs.size(); ++i)
	for(int j = i + 1; j < arcs.size(); ++j){
		vD ret = comtang(arcs[i].cen, arcs[i].rd, arcs[j].cen, arcs[j].rd, true);
		for(k = 0; k < ret.size(); ++k){
			D a = ret[k], b = ret[k];
			if(arcs[i].check(a) && arcs[j].check(b)){
				int ia = getid(i, a), ib = getid(j, b);
				P pa = arcs[i].point(a), pb = arcs[j].point(b);
				D ds = abs(pa - pb);

				if(cross(pa - arcs[i].cen, pb - pa) < 0.0){
					swap(ia, ib);
				}

				E.push_back((edgeinfo){ia, ib, ds});
				E.push_back((edgeinfo){ib + 1, ia + 1, ds});
			}
		}

		ret = comtang(arcs[i].cen, arcs[i].rd, arcs[j].cen, arcs[j].rd, false);
		for(k = 0; k < ret.size(); ++k){
			D a = ret[k], b = ret[k] + pi;
			if(arcs[i].check(a) && arcs[j].check(b)){
				int ia = getid(i, a), ib = getid(j, b);
				P pa = arcs[i].point(a), pb = arcs[j].point(b);
				D ds = abs(pa - pb);
				if(cross(pa - arcs[i].cen, pb - pa) > 0.0){
					E.push_back((edgeinfo){ia, ib + 1, ds});
					E.push_back((edgeinfo){ib, ia + 1, ds});
				}
				else{
					E.push_back((edgeinfo){ia + 1, ib, ds});
					E.push_back((edgeinfo){ib + 1, ia, ds});
				}
			}
		}
	}


	for(int i = 0; i < arcs.size(); ++i){
		assert(!arcs[i].mp.empty());
		map<D,int,comparer>::iterator it1, it2;
		it1 = arcs[i].mp.begin();
		while(1){
			it2 = it1;
			if(++it1 == arcs[i].mp.end()){ break; }
			int a = it1->second, b = it2->second;
			D ds = arcs[i].rd * abs(it1->first - it2->first);
			E.push_back((edgeinfo){b, a, ds});
			E.push_back((edgeinfo){a + 1, b + 1, ds});
		}
	}

	vector<vector<pdi> > G(V);
	for(int i = 0; i < E.size(); ++i){
		G[E[i].f].push_back(pdi(E[i].len, E[i].t));
	}

	D stang = arg(pts[0] - arcs[0].cen);
	arcs[0].check(stang);
	assert(arcs[0].mp.count(stang));
	int start = arcs[0].mp[stang];

	vD dst(V, DBL_MAX);
	priority_queue<pdi,vector<pdi>,greater<pdi> > pq;
	for(int i = 0; i < G[start].size(); ++i){
		int t = G[start][i].second;
		D d = G[start][i].first;
		dst[t] = d;
		pq.push(pdi(d, t));
	}

	while(!pq.empty()){
		pdi p = pq.top();
		pq.pop();
		if(dst[p.second] != p.first){ continue; }
		if(p.second == start){
			printf("%f\n", p.first);
			return 0;
		}

		for(int i = 0; i < G[p.second].size(); ++i){
			D d = G[p.second][i].first + p.first;
			int t = G[p.second][i].second;
			if(dst[t] > d){
				dst[t] = d;
				pq.push(pdi(d, t));
			}
		}
	}

	fprintf(stderr, "no answer\n");
}