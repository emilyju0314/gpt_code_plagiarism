#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 100;
constexpr double EPS = 1e-10;

int par[MAX], rank_[MAX];

void init(int N)
{
    for (int i = 0; i < N; i++) {
        par[i] = i;
        rank_[i] = 0;
    }
}

int find(int x)
{
    if (par[x] == x) {
        return x;
    }
    return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x == y) return;

    if (rank_[x] < rank_[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (rank_[x] == rank_[y]) {
            rank_[x]++;
        }
    }
}

bool same(int x, int y)
{
    return (find(x) == find(y));
}

struct Edge {
    int u, v;
    double cost;
    Edge () {}
    Edge (int u, int v, double cost) :
        u{u}, v{v}, cost{cost} {}
};

double dist(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

struct Point {
    double x, y;

    Point(){}
    Point(double x, double y) : x{x}, y{y} {}
    
    Point operator - (const Point &p) const { return Point(x - p.x, y - p.y); }
};

struct Settlement : Point {
    int v;
    Settlement () {}
    Settlement (double x, double y, int v) : Point{x, y}, v{v} {}
};

double dot(const Point &a, const Point &b)
{
    return a.x * b.x + a.y * b.y;
}

double cross(const Point &a, const Point &b)
{
    return a.x * b.y - b.x * a.y;
}

double norm(const Point &p)
{
    return dot(p, p);
}

double abs(const Point &p)
{
    return sqrt(norm(p));
}

typedef Point Vector;

int ccw(const Point &p0, const Point &p1, const Point &p2)
{
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if (cross(a, b) > EPS)  return +1;
    if (cross(a, b) < -EPS) return -1;
    if (dot(a, b) < -EPS)   return +2;
    if (norm(a) < norm(b))  return -2;
    return +0;
}

bool sortY(Point p1, Point p2)
{
    if (p1.y != p2.y) {
        return (p1.y - p2.y < -EPS);
    } else { 
        return (p1.x - p2.x < -EPS);
    }
}

typedef vector<Settlement> Polygon;

double convex_hull(Polygon &ps)
{
    int N = ps.size(), j = 0;
    Polygon pg(N * 2);
    sort(ps.begin(), ps.end(), sortY);
    for (int i = 0; i < N; i++, j++) {
        while (j >= 2 && ccw(pg[j - 2], pg[j - 1], ps[i]) == -1) {
            j--;
        }
        pg[j] = ps[i];
    }
    int k = j + 1;
    for (int i = N - 2; i >= 0; i--, j++) {
        while (j >= k && ccw(pg[j - 2], pg[j - 1], ps[i]) == -1) {
            j--;
        }
        pg[j] = ps[i];
    }
    pg.resize(j - 1);
    double res = 0;
    for (int i = 0; i < (int)pg.size(); i++) {
        Settlement a = pg[i], b = pg[(i + 1) % pg.size()];        
        res += dist(a.x, a.y, b.x, b.y);
        unite(a.v, b.v);
    }
    return res;
}

bool comp(const Edge &a, const Edge &b)
{
    return a.cost < b.cost;
}

double kruskal(vector<Edge> &es, int V,
               vector<Settlement> &ps)
{
    init(V);
    double res = convex_hull(ps);
    sort(es.begin(), es.end(), comp);
    for (int i = 0; i < (int)es.size(); i++) {
        Edge &e = es[i];
        if (!same(e.u, e.v)) {
            res += e.cost;
            unite(e.u, e.v);
        }
    }
    return res;
}

int main()
{
    int V, R;
    cin >> V >> R;
    vector<int> x(V), y(V);
    vector<Settlement> ps(V);
    for (int i = 0; i < V; i++) {
        cin >> x[i] >> y[i];
        ps[i] = Settlement(x[i], y[i], i);
    }
    int s, t;
    vector<Edge> e(R);
    for (int i = 0; i < R; i++) {
        cin >> s >> t;
        s--; t--;
        e[i] = Edge(s, t, dist(x[s], y[s], x[t], y[t]));
    }
    printf("%.10f\n", kruskal(e, V, ps));
    return 0;
}