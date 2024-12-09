#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cerr<<*i<<" "; cerr<<endl; }
inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
// 2次方程式 ax^2 + bx + c = 0の解 (重解を一つにまとめる)
vector<double> quadratic(double a, double b, double c){
  // assert(a != 0);
  if(a < EPS){
    if(b < EPS) return vector<double>();
    return vector<double>(1, -c / b);
  }
  double D = b*b - 4*a*c;
  if(D < 0) return vector<double>();
  if(D == 0) return vector<double>(1, -b/(2.0 * a));

  // |b| >> |ac|の時の桁落ちを避けるために
  // x_1 = (-b-sign(b)*sqrt(D))/(2*a), x_2 = c / (a*x_1)を利用する
  vector<double> res;
  int sign = (b >= 0) ? 1 : -1;
  double x1 = (-b - sign * sqrt(D))/(2.0 * a);
  double x2 = c / (a * x1);
  res.push_back(x1);
  res.push_back(x2);
  return res;
}
struct UnionFind {
  vector<int> data;
  UnionFind(int N) : data(N, -1) { }
  bool uni(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[x] > data[y]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool same(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};
typedef double Weight;
struct Edge{
  int src, dst;
  Weight cost;
  Edge(int f, int t, Weight c) : src(f), dst(t), cost(c) {}
};
bool operator<(const Edge& a, const Edge& b){
  return a.cost < b.cost;
}
bool operator>(const Edge& a, const Edge& b){
  return b < a;
}
typedef vector<Edge> Node;
typedef vector<Node> Graph;
vector<Edge> kruskal(int N, const vector<Edge>& edges){
  priority_queue<Edge, vector<Edge>, greater<Edge> > que;
  REP(i, edges.size()) que.push(edges[i]);
  UnionFind uf(N);
  vector<Edge> res;
  while(!que.empty()){
    Edge e = que.top(); que.pop();
    if(!uf.same(e.dst, e.src)){
      uf.uni(e.dst, e.src);
      res.push_back(e);
    }
    if(res.size() == N - 1) break;
  }
  assert(res.size() == N - 1);
  return res;
}
// sqrt( at^2 + bt + c )
double f(double t, double a, double b, double c){
  double res = a * t * t + b * t + c;
  return sqrt(res);
}
double MST(double t, const vector<Edge>& edges, double a[16][16], double b[16][16], double c[16][16]){
  double res = 0;
  FORIT(e, edges){
    res += f(t, a[e->src][e->dst], b[e->src][e->dst], c[e->src][e->dst]);
  }
  return res;
}
int main(){
  int N, T;
  while(cin >> N >> T && N){
    double x[16], y[16];
    double vx[16], vy[16];
    REP(i, N) cin >> x[i] >> y[i] >> vx[i] >> vy[i];
    double a[16][16]; // (v[i] - v[j]) * (v[i] - v[j])
    double b[16][16]; // (p[i] - p[j]) * (v[i] - v[j])
    double c[16][16]; // (p[i] - p[j]) * (p[i] - p[j])
    vector<double> inter_point;
    inter_point.push_back(0); inter_point.push_back(T);
    REP(i, N) FOR(j, i + 1 , N){
      double dx = x[i] - x[j];
      double dy = y[i] - y[j];
      double vdx = vx[i] - vx[j];
      double vdy = vy[i] - vy[j];
      a[i][j] = vdx * vdx + vdy * vdy;
      b[i][j] = 2 * (dx * vdx + dy * vdy);
      c[i][j] = dx * dx + dy * dy;
      //printf("%d -> %d: a = %lf b = %lf c = %lf\n", i, j, a[i][j], b[i][j], c[i][j]);
    }
    REP(i, N)FOR(j, i + 1, N)REP(k, N) FOR(l, k + 1, N){
      vector<double> v = quadratic(a[i][j] - a[k][l], b[i][j] - b[k][l], c[i][j] - c[k][l]);
      REP(i, v.size()){
        double t = v[i];
        bool ok = (0 + EPS < t && t < T - EPS);
        REP(i, inter_point.size()) if(abs(t - inter_point[i]) < EPS) ok = false;
        if(ok) inter_point.insert(lower_bound(inter_point.begin(), inter_point.end(), t), t);
      }
    }
    double ans = 1e40;
    REP(i, inter_point.size() - 1){
      double lb = inter_point[i], ub = inter_point[i + 1];
      vector<Edge> edges;
      REP(i, N) FOR(j, i + 1, N){
        edges.push_back(Edge(i, j, f((lb + ub) / 2, a[i][j], b[i][j], c[i][j])));
      }
      edges = kruskal(N, edges);
      REP(iter, 60){
        if(MST((lb * 2 + ub) / 3, edges, a, b, c) < MST((lb + ub * 2) / 3, edges, a, b, c)){
          ub = (lb + ub * 2) / 3;
        }else{
          lb = (lb * 2 + ub) / 3;
        }
      }
      ans = min(ans, MST((lb + ub) / 2, edges, a, b, c));
    }
    printf("%.10lf\n", ans);
  }
  return 0;
}