#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

constexpr double EPS = 1e-9;

struct point {
	double x, y;
	point(double x_ = 0.0, double y_ = 0.0):x(x_), y(y_) {}
	point(const point &p):x(p.x), y(p.y) {}

	point operator+ (const point &p) const {
		return point(x + p.x, y + p.y);
	}

	point operator- (const point &p) const {
		return point(x - p.x, y - p.y);
	}

	point operator* (double s) const {
		return point(x * s, y * s);
	}

	point operator* (const point &p) const {
		return point(x * p.x - y * p.y, x * p.y + y * p.x);
	}

	point operator/ (double s) const {
		return point(x / s, y / s);
	}

	bool operator< (const point &p) const {
		return x + EPS < p.x || (abs(x - p.x) < EPS && y + EPS < p.y);
	}

	bool operator== (const point &p) const {
		return abs(x - p.x) < EPS && abs(y - p.y) < EPS;
	}
};

istream &operator>>(istream &is, point &p) {
	return is >> p.x >> p.y;
}

point rotate90(const point &p) {
	return point(-p.y, p.x);
}

double norm(const point &p) {
	return p.x * p.x + p.y * p.y;
}

double abs(const point &p) {
	return sqrt(norm(p));
}

double dot(const point &a, const point &b) {
	return a.x * b.x + a.y * b.y;
}

double cross(const point &a, const point &b) {
	return a.x * b.y - a.y * b.x;
}

struct segment {
	point a, b;
	segment(const point &a_, const point &b_):a(a_), b(b_){}
};

struct circle {
	point c;
	double r;
	circle(const point &c_, const double &r_):c(c_), r(r_){}
};

typedef vector<point> polygon;

int ccw(const point &a, point b, point c) {
	b = b - a;
	c = c - a;
	const double tmp = cross(b, c);
	if(tmp > EPS) return 1; // ccw
	if(tmp < -EPS) return -1; // cw
	if(dot(b, c) < 0) return 2; // c, a, b 順に一直線上
	if(norm(b) < norm(c)) return -2; // a, b, c 順に一直線上
	return 0; //a, c, b 順で一直線上
}

bool intersect(const segment &s, const segment &t) {
	return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0
		&& ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

bool intersect(const segment &s, const point &p) {
	return ccw(s.a, s.b, p) == 0;
}

point crosspoint(const segment &s, const segment &t) {
	if(!intersect(s, t)) return s.a; // 交点を持たない

	const double tmp = cross(s.b - s.a, t.b - t.a);
	if(abs(tmp) < EPS) { // 一直線上
		if(intersect(s, t.a)) return t.a;
		if(intersect(s, t.b)) return t.b;
		if(intersect(t, s.a)) return s.a;
		return s.b;
	}
	return t.a + (t.b - t.a) * cross(s.b - s.a, s.b - t.a) * (1.0 / tmp);
}

struct edge {
	int to;
	double cost;
	edge(int to_, double cost_):to(to_), cost(cost_) {}
};

typedef vector<vector<edge>> graph;

int get_index(const vector<point> &points, const point &p) {
	return lower_bound(points.begin(), points.end(), p) - points.begin();
}

graph arrangement(const vector<segment> &segments, vector<point> &points) {
	vector<segment> streets, signs;

	for(int i = 0; i < static_cast<int>(segments.size()); ++i) {
		bool a_on = false, b_on = false;
		for(int j = 0; j < static_cast<int>(segments.size()); ++j) {
			if(i == j) continue;
			a_on |= intersect(segments[j], segments[i].a);
			b_on |= intersect(segments[j], segments[i].b);
		}

		(a_on && b_on ? streets : signs).emplace_back(segments[i]);
	}

	const int n = streets.size();
	points.clear();
	for(int i = 0; i < n; ++i) {
		const auto &s1 = streets[i];
		points.emplace_back(s1.a);
		points.emplace_back(s1.b);

		for(int j = i + 1; j < n; ++j) {
			const auto &s2 = streets[j];
			if(intersect(s1, s2)) {
				points.emplace_back(crosspoint(s1, s2));
			}
		}
	}

	sort(points.begin(), points.end());
	points.erase(unique(points.begin(), points.end()), points.end());

	const int V = points.size();
	graph G(V);

	for(const auto &s : streets) {
		vector<pair<double, int>> vs;
		for(int i = 0; i < V; ++i) {
			if(intersect(s, points[i])) {
				vs.emplace_back(abs(s.a - points[i]), i);
			}
		}

		sort(vs.begin(), vs.end());
		for(int i = 1; i < static_cast<int>(vs.size()); ++i) {
			const int v = vs[i].second;
			const int u = vs[i - 1].second;
			const double d = vs[i].first - vs[i - 1].first;

			bool go = true;
			bool back = true;

			const segment street(points[v], points[u]);

			for(const auto & t : signs) {
				const bool a_on = intersect(street, t.a);
				const bool b_on = intersect(street, t.b);

				if(a_on || b_on) {
					const point &base = (a_on ? t.a : t.b);
					const point &tip  = (a_on ? t.b : t.a);
					const int tmp = ccw(base, base + rotate90(points[u] - points[v]), tip);

					if(tmp != 1)  go = false;
					if(tmp != -1) back = false;
				}
			}

			if(go)   G[v].emplace_back(u, d);
			if(back) G[u].emplace_back(v, d);
		}
	}

	return G;
}

bool dijkstra(const graph &G, int s, int t, vector<int> &prev) {
	typedef pair<double, int> P;

	const int n = G.size();

	vector<double> dist(n, INT_MAX);
	priority_queue<P, vector<P>, greater<P>> que;

	dist[s] = 0;
	que.push({0, s});
	prev.assign(n, -1);

	while(!que.empty()) {
		const auto d = que.top().first;
		const auto v = que.top().second;
		que.pop();

		if(dist[v] + EPS < d) continue;

		if(v == t) return true;

		for(const auto &e : G[v]) {
			const auto next_dist = d + e.cost;
			if(dist[e.to] > next_dist + EPS) {
				dist[e.to] = next_dist;
				que.push({next_dist, e.to});
				prev[e.to] = v;
			}
		}
	}
	
	return false;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	for(int n; cin >> n && n;) {
		point start, goal;
		cin >> start >> goal;

		vector<segment> segments;
		segments.reserve(n);

		for(int i = 0; i < n; ++i) {
			point a, b;
			cin >> a >> b;
			segments.emplace_back(a, b);
		}

		vector<point> points;
		const auto G = arrangement(segments, points);

		const int start_index = get_index(points, start);
		const int goal_index = get_index(points, goal);

		vector<int> prev;
		if(!dijkstra(G, start_index, goal_index, prev)) {
			cout << -1 << '\n';
			continue;
		}

		vector<int> path;
		for(int v = goal_index; v != -1; v = prev[v]) {
			path.emplace_back(v);
		}
		reverse(path.begin(), path.end());

		for(const auto &idx : path) {
			cout << points[idx].x << ' ' << points[idx].y << '\n';
		}
		cout << "0\n";
	}

	return EXIT_SUCCESS;
}