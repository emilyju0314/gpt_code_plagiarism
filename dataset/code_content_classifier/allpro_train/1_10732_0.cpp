#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <complex>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-7;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

struct Edge {
  int to;
  double cost;
  Edge() {;}
  Edge(int to, double cost) : to(to), cost(cost) {;}
};

typedef complex<double> Point;
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

inline double cross(const Point &a, const Point &b) {
  return imag(conj(a) * b);
}

inline double inner(const Point &a, const Point &b) {
  return real(conj(a) * b);
}

struct Pos {
  Point p;
  double t;
  Pos() {;}
  Pos(Point p, double t) : p(p), t(t) {;}
  bool operator<(const Pos &rhs) const { return t < rhs.t; }
};

struct Event {
  double t;
  Point vect;
  set<int> person;
  Event() {;}
  Event(double t, Point vect) : t(t), vect(vect) {;}
  Event(double t, Point vect, int p1, int p2) : t(t), vect(vect) {
    person.insert(p1); person.insert(p2);
  }
  bool operator<(const Event &rhs) const {
    if (t != rhs.t) { return t < rhs.t; }
    if (abs(vect - rhs.vect) <= EPS) { return false; }
    if (vect.real() != rhs.vect.real()) { return vect.real() < rhs.vect.real(); }
    return vect.imag() < rhs.vect.imag();
  }
};


vector<double> quadratic(double a, double b, double c, int start, int end) {
  vector<double> ret;
  if (fabs(a) <= EPS && fabs(b) <= EPS) {
    if (fabs(c) > EPS) { return ret; }
    FOREQ(i, start, end) { ret.push_back(i); }
  } else if (fabs(a) <= EPS) {
    double t = start - c / b;
    if (start <= t && t <= end) { ret.push_back(t); }
  } else {
    double t1 = start + (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    double t2 = start + (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
    if (start <= t1 && t1 <= end) { ret.push_back(t1); }
    if (start <= t2 && t2 <= end) { ret.push_back(t2); }
  }
  return ret;
}

int n;
bool sing[60][1010];
vector<Pos> member[60];
set<Event> event;
int parent[60];
double ptime[60];

Point Position(int p, double t) {
  vector<Pos>::iterator it = lower_bound(member[p].begin(), member[p].end(), Pos(Point(0, 0), t));
  if (it == member[p].begin()) {
    return it->p;
  }
  vector<Pos>::iterator pit = it;
  pit--;
  if (it == member[p].end()) { return pit->p; }
  double span = it->t - pit->t;
  double l = t - pit->t;
  double r = it->t - t;
  return (r * pit->p + l * it->p) / span;
}

inline vector<double> preQuadratic(int i, int j, int start, int end) {
  Point p1 = Position(i, start);
  Point v1 = Position(i, end) - p1;
  Point p2 = Position(j, start);
  Point v2 = Position(j, end) - p2;
  return quadratic(cross(v1, v2), cross(p1, v2) - cross(p2, v1), cross(p1, p2), start, end);
}

void FindEvent() {
  event.clear();
  {
    Event firstEvent(0, Point(-10000, -10000));
    REP(i, n) { firstEvent.person.insert(i); }
    //event.push_back(firstEvent);
  }
  FOREQ(t, 0, 1000) {
    REP(i, n) {
      REP(j, i) {
        vector<double> cand = preQuadratic(i, j, t, t + 1);
        FORIT(it, cand) {
          assert(t <= *it && *it <= t + 1);
          if (inner(Position(i, *it), Position(j, *it)) < -EPS) { continue; }
          Point vect = Position(i, *it);
          vect /= abs(vect);
          if (event.count(Event(*it, vect))) {
            const_cast<Event*>(&*event.find(Event(*it, vect)))->person.insert(i);
            const_cast<Event*>(&*event.find(Event(*it, vect)))->person.insert(j);
          } else {
            event.insert(Event(*it, vect, i, j));
          }
        }
      }
    }
  }
}

double getCost(int p, double s, double e) {
  double ret = 0;
  if ((int)s == (int)e) {
    return sing[p][(int)s] ? e - s : 0;
  }
  if (sing[p][(int)s]) { ret += ceil(s) - s; }
  if (sing[p][(int)e]) { ret += e - floor(e); }
  FOR(i, ceil(s), e) {
    if (sing[p][i]) { ret++; }
  }
  return ret;
}

Graph g;
vector<double> ts;
void MakeGraph() {
  g = Graph(event.size() + 2);
  ts = vector<double>(event.size() + 2, 0);
  MEMSET(parent, 0);
  MEMSET(ptime, 0);
  int index = 1;
  FORIT(it1, event) {
    ts[index] = it1->t;
    FORIT(it2, it1->person) {
      double cost = getCost(*it2, ptime[*it2], it1->t);
      g[parent[*it2]].push_back(Edge(index, cost));
      //cout << *it2 << " " << index << " " << ts[parent[*it2]] << " " << ptime[*it2] << " " << it1->t << endl;
      assert(ts[parent[*it2]] == ptime[*it2]);
      parent[*it2] = index;
      ptime[*it2] = it1->t;
    }
    index++;
  }
    ts[index] = 1000;
  REP(i, n) {
    double cost = getCost(i, ptime[i], 1000);
    g[parent[i]].push_back(Edge(index, cost));
  }
}

vector<double> memo;
double calc(int index) {
  if (memo[index] != -1) { return memo[index]; }
  double ret = 0;
  FORIT(it, g[index]) {
    ret = max(ret, calc(it->to) + it->cost);
  }
  //cout << index << " "<< ts[index] << " "<< ret << endl;
  return memo[index] = ret;
}

int main() {
  int test_case = 0;
  while (scanf("%d", &n), n) {
    test_case++;
    MEMSET(sing, false);
    int x, y;
    scanf("%d %d", &x, &y);
    Point camera(x, y);
    REP(i, n) {
      int m;
      scanf("%d", &m);
      member[i].resize(m);
      REP(j, m) {
        int x, y, t;
        scanf("%d %d %d", &x, &y, &t);
        member[i][j].p = Point(x - camera.real(), y - camera.imag());
        member[i][j].t = t;
      }
      int l;
      scanf("%d", &l);
      REP(j, l) {
        int s, e;
        scanf("%d %d", &s, &e);
        FOR(k, s, e) { sing[i][k] = true; }
      }
    }
    FindEvent();
    MakeGraph();
    memo = vector<double>(g.size(), -1);
    printf("%.6f\n", calc(0));
    assert(calc(0) <= 1000);
  }
}