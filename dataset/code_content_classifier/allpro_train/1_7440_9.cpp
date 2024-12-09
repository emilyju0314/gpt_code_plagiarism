#include <iostream>
#include <complex>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;

const double pi  = M_PI;
const double inf = 1e10;
const double eps = 1e-10;
typedef complex<double> point;

struct line : public vector<point> {
	line(const point& a, const point& b) { push_back(a); push_back(b); }
};

namespace std {
	bool operator<(const point& a, const point& b) {
		if(abs(a.real() - b.real()) > eps) return a.real() < b.real();
		if(abs(a.imag() - b.imag()) > eps) return a.imag() < b.imag();
		return false;
	}
}

point  vec  (const line&  l)                 { return l[1]-l[0]; }
double dot  (const point& a, const point& b) { return (a*conj(b)).real(); }
double cross(const point& a, const point& b) { return (conj(a)*b).imag(); }

int ccw(const point& a, const point& b, const point& c)
{
	point u=b-a, v=c-a;
	if(cross(u,v) > 0 ) return +1;
	if(cross(u,v) < 0 ) return -1;
	if(  dot(u,v) < 0 ) return +2;
	if(abs(u) < abs(v)) return -2;
	return 0;
}

int ccw(const line& s, const point& p) {
	return ccw(s[0], s[1], p);
}

bool intersectSP(const line& s, const point& p) {
	return abs(s[0]-p)+abs(s[1]-p) < abs(s[1]-s[0])+eps;
}

bool intersectSS(const line& s, const line& t) {
	return ccw(s,t[0])*ccw(s,t[1]) <= 0
		&& ccw(t,s[0])*ccw(t,s[1]) <= 0;
}

point crosspoint(const line& l, const line& m) {
	double A = cross(vec(l), vec(m));
	double B = cross(vec(l), l[1]-m[0]);
	if(abs(A) < eps) return m[0];
	return m[0] + B/A*vec(m);
}

enum ntype{ NONE, VALVE, SOURCE, REPAIR };

struct node
{
	point pos;
	ntype type;
	vector<int> to;

	node(const point& p, ntype t) : pos(p), type(t) {}
};

vector<node> seg_arr(const vector<line>& lines, const vector<point>& points)
{
	map<point, ntype> p;
	for(int i=0; i<points.size(); i++) {
		ntype type = VALVE;
		if(i == points.size()-2) { type = SOURCE; }
		if(i == points.size()-1) { type = REPAIR; }

		p.insert( make_pair(points[i],type) );
	}

	for(int i=0; i<lines.size(); i++) {
		p.insert( make_pair(lines[i][0],NONE) );
		p.insert( make_pair(lines[i][1],NONE) );
		for(int j=i+1; j<lines.size(); j++) {
			if(intersectSS(lines[i], lines[j])) {
				point cp = crosspoint(lines[i], lines[j]);
				p.insert( make_pair(cp,NONE) );
			}
		}
	}

	vector<node> graph;
	for(map<point,ntype>::iterator it=p.begin(); it!=p.end(); it++) {
		graph.push_back( node(it->first,it->second) );
	}

	for(int i=0; i<lines.size(); i++) {
		vector<pair<double,int> > online;
		for(int j=0; j<graph.size(); j++) {
			if(intersectSP(lines[i], graph[j].pos)) {
				online.push_back( pair<double,int>(abs(lines[i][0]-graph[j].pos), j) );
			}
		}

		sort(online.begin(), online.end());
		for(int j=1; j<online.size(); j++) {
			int a = online[j-1].second;
			int b = online[j  ].second;
			graph[a].to.push_back(b);
			graph[b].to.push_back(a);
		}
	}

	return graph;
}

int main()
{
	int N,M;
	cin >> N >> M;

	vector<line>  lines;
	vector<point> points;

	int x1,y1,x2,y2;
	for(int i=0; i<N; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		lines.push_back( line(point(x1,y1), point(x2,y2)) );
	}
	for(int i=0; i<M+2; i++) {
		cin >> x1 >> y1;
		points.push_back( point(x1,y1) );
	}

	int source,repair;
	vector<node> graph = seg_arr(lines,points);
	for(int i=0; i<graph.size(); i++) {
		if(graph[i].type == SOURCE) { source = i; }
		if(graph[i].type == REPAIR) { repair = i; }
	}

	vector<bool> v(graph.size(), 0);

	queue<int> q;
	q.push(repair);
	v[repair] = 1;
	while(!q.empty())
	{
		int t=q.front(); q.pop();

		if(graph[t].type == VALVE) continue;
		if(graph[t].type == SOURCE) {
			cout << -1 << endl;
			return 0;
		}

		for(int i=0; i<graph[t].to.size(); i++) {
			int s = graph[t].to[i];
			if(v[s]) continue;
			v[s] = 1;
			q.push(s);
		}
	}

	double wl = 0;
	set<pair<int,int> > ve;
	q.push(source);
	v[source] = 1;
	while(!q.empty())
	{
		int t=q.front(); q.pop();

		for(int i=0; i<graph[t].to.size(); i++) {
			int s = graph[t].to[i];

			if(ve.insert(make_pair(min(t,s),max(t,s))).second) {
				wl += abs(graph[t].pos - graph[s].pos);
			}

			if(v[s]) continue;
			v[s] = 1;
			q.push(s);
		}
	}


	double al = 0;
	ve.clear();
	for(int i=0; i<graph.size(); i++)
	for(int j=0; j<graph[i].to.size(); j++) {
		int t=i, s=graph[i].to[j];
		if(ve.insert(make_pair(min(t,s),max(t,s))).second) {
			al += abs(graph[t].pos - graph[s].pos);
		}
	}
	printf("%.9lf\n", al-wl);

}