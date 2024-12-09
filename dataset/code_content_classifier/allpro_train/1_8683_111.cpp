#include <bits/stdc++.h>
using namespace std;
inline void wait(double seconds) {
  double endtime = clock() + (seconds * CLOCKS_PER_SEC);
  while (clock() < endtime) {
    ;
  }
}
inline int fastIn() {
  register char c = 0;
  register int a = 0;
  while (c < 33) c = getchar();
  while (c > 33) {
    a = (a * 10) + (c - '0');
    c = getchar();
  }
  return a;
}
int tour_count;
int win_need;
int bag_cap;
const int mx = 210;
struct NODE {
  double p;
  double np;
  int w;
  NODE(int p = 0, int np = 0, int w = 0) : p(p), np(np), w(w) {}
  bool operator<(const NODE &r) const { return this->w > r.w; }
};
NODE vi[mx];
inline void read() {
  scanf("%d %d %d", &tour_count, &win_need, &bag_cap);
  for (int i = 0, j1 = tour_count; i < j1; ++i) {
    int tmp = fastIn();
    vi[i].p = (double)tmp / (double)100;
    vi[i].np = (double)1 - vi[i].p;
  }
  for (int i = 0, j1 = tour_count; i < j1; ++i) {
    scanf("%d", &vi[i].w);
  }
}
struct data {
  bool f;
  double v;
  data(bool f = false, double v = 0) : f(f), v(v) { ; }
};
data dp[200][200][201];
double go(int at, int win, int cap) {
  if (cap < 0) return (double)0;
  if (at >= tour_count) {
    return win >= win_need ? (double)1 : (double)0;
  }
  if (dp[at][win][cap].f) return dp[at][win][cap].v;
  dp[at][win][cap].f = true;
  double v1 = vi[at].p * go(at + 1, win + 1, min(cap + vi[at].w, 200));
  double v2 = vi[at].np * go(at + 1, win, cap);
  return dp[at][win][cap].v = (v1 + v2);
}
inline void proc() {
  sort(vi, vi + tour_count);
  memset(dp, 0, sizeof(dp));
  double res = go(0, 0, bag_cap);
  printf("%.9lf\n", res);
}
int main() {
  int kase = 1;
  for (int i = 0, j1 = kase; i < j1; ++i) {
    read();
    proc();
  }
  return 0;
}
