#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

#include <complex>
typedef complex<double> Point;

int HtoS(int h, int m, int s) {
  return h * 3600 + m * 60 + s;
}
string StoH(double sec) {
  int h = (int)sec / 3600;
  int m = (int)sec % 3600 / 60;
  double ms =  sec - (h * 3600 + m * 60);
  char str[1000];
  sprintf(str, "%02d %02d %02d.%08d", h, m, (int)ms, (int)((ms - (int)ms) * 100000000 + 0.5));
  return str;
}

struct State {
  int use;
  double t;
  Point p;
  int last;
  State() {;}
  State(int use, double t, Point p, int last) : use(use), t(t), p(p), last(last) {;}
  bool operator<(const State &rhs) const {
    return t > rhs.t;
  }
};

const double SPEED_N = 80.0 / 60.0;
const double SPEED_C = 50.0 / 60.0;
Point sp, ep;
int startTime;
int endTime;
int n;
vector<Point> route[20];
vector<double> ts[20];

int bisect(State state, int target) {
  int lower = 0;
  int upper = 1 << 20;
  while (lower != upper) {
    int mid = (lower + upper) / 2;
    int cycle = mid / ts[target].size();
    int index = mid % ts[target].size();
    double et = cycle * ts[target].back() + ts[target][index] + startTime;
    Point p = route[target][(index + 1) % route[target].size()];
    if (abs(state.p - p) / SPEED_N - (et - state.t) <= -EPS) {
      upper = mid;
    } else {
      lower = mid + 1;
      if (et >= endTime) { break; }
    }
  }
  return lower;
}

pair<double, Point> calc(State state, int target) {
  int from = bisect(state, target);
  double lower;
  double upper;
  {
    int cycle = from / ts[target].size();
    int index = from % ts[target].size();
    lower = cycle * ts[target].back() + startTime;
    if (index != 0) {
      lower += ts[target][index - 1];
    }
    upper = cycle * ts[target].back() + ts[target][index] + startTime + EPS * 10;
  }
  double stime = lower;
  pair<double, Point> ret(endTime + 1, Point(0, 0));
  if (lower > endTime) { return ret; }
  from %= ts[target].size();
  Point vect = route[target][(from + 1) % route[target].size()] - route[target][from];
  vect /= abs(vect);
  bool ok = false;
  REP(i, 50) {
    double mid = (lower + upper) / 2.0;
    double t = mid - stime;
    Point tp = route[target][from] + vect * (t * SPEED_C);
    if (abs(state.p - tp) / SPEED_N <= mid - state.t) {
      upper = mid;
      ret = make_pair(mid, tp);
      ok = true;
    } else {
      lower = mid;
    }
  }
  double t = lower - stime;
  Point tp = route[target][from] + vect * (t * SPEED_C);
  //cout << abs(state.p - tp) / SPEED_N << " " << lower - state.t << endl;
  assert(ok);
  return ret;
}

bool visit[1 << 14][15];
double times[1 << 14][15];
int main() {
  int test;
  scanf("%d", &test);
  double sx, sy, ex, ey;
  while (scanf("%lf %lf %lf %lf", &sx, &sy, &ex, &ey) > 0) {
    sp = Point(sx, sy);
    ep = Point(ex, ey);
    {
      int h, m, s;
      scanf("%d:%d:%d", &h, &m, &s);
      startTime = HtoS(h, m, s);
      scanf("%d:%d:%d", &h, &m, &s);
      endTime = HtoS(h, m, s);
    }
    scanf("%d", &n);
    REP(i, n) {
      route[i].clear();
      ts[i].clear();
      int k;
      scanf("%d", &k);
      REP(j, k) {
        int x, y;
        scanf("%d %d", &x, &y);
        route[i].push_back(Point(x, y));
      }
      double pt = 0.0;
      REP(j, k) {
        ts[i].push_back(pt + abs(route[i][j] - route[i][(j + 1) % route[i].size()]) / SPEED_C);
        pt = ts[i].back();
      }
    }

    REP(i, 1 << 14) REP(j, 15) { times[i][j] = endTime + EPS * 2; }
    MEMSET(visit, false);
    priority_queue<State> que;
    que.push(State(0, startTime, sp, 14));
    pair<int, double> ans(-1, -1e+100);
    while (!que.empty()) {
      State state = que.top();
      que.pop();
      if (visit[state.use][state.last]) { continue; }
      //cout << state.use << " " << state.last << " "<< state.t << endl;
      visit[state.use][state.last] = true;
      {
        double et = state.t + abs(state.p - ep) / SPEED_N;
        if (et > endTime) { continue; }
        pair<int, double> lans(__builtin_popcount(state.use), -et);
        ans = max(ans, lans);
      }
      REP(i, n) {
        if ((state.use >> i) & 1) { continue; }
        int nuse = state.use | (1 << i);
        if (visit[nuse][i]) { continue; }
        pair<double, Point> next = calc(state, i);
        if (next.first - times[nuse][i] > EPS) { continue; }
        times[nuse][i] = next.first;
        que.push(State(nuse, next.first, next.second, i));
      }
    }
    printf("%d\n%s\n", ans.first, StoH(-ans.second).c_str());
  }
}