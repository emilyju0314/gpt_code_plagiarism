#include <bits/stdc++.h>
using namespace std;
const int RMAX = 100000;
const int NMAX = 100000;
const int PI = 314000000;
template <class T>
class Heap {
 private:
  int M, H[1 + NMAX];
  int P[NMAX];
  T V[NMAX];
  void up(int, const T &, int);
  void dn(int, const T &, int);

 public:
  void Init(int, const T &);
  int Top() const { return M > 0 ? H[1] : -1; }
  const T &Get(int k) const { return V[k]; }
  void Set(int k, const T &v) {
    if (P[k] == 0)
      up(k, v, ++M);
    else if (V[k] < v)
      dn(k, v, P[k]);
    else
      up(k, v, P[k]);
  }
  void Del(int k) {
    const int p = P[k];
    if (p != 0) {
      P[k] = 0;
      if (p != M--) dn(H[M + 1], V[H[M + 1]], p);
    }
  }
};
template <class T>
void Heap<T>::Init(int n, const T &v) {
  M = 0;
  for (int i = 0; i < n; i++) P[i] = 0;
  for (int i = 0; i < n; i++) V[i] = v;
}
template <class T>
void Heap<T>::up(int k, const T &v, int i) {
  for (; i > 1 && v < V[H[i >> 1]]; i >>= 1) P[H[i] = H[i >> 1]] = i;
  H[i] = k;
  P[k] = i;
  V[k] = v;
}
template <class T>
void Heap<T>::dn(int k, const T &v, int i) {
  for (int j; (j = i << 1) <= M; i = j) {
    if (j < M && V[H[j + 1]] < V[H[j]]) j++;
    if (!(V[H[j]] < v)) break;
    P[H[i] = H[j]] = i;
  }
  H[i] = k;
  P[k] = i;
  V[k] = v;
}
struct Rule {
  int src;
  int cnt;
  vector<int> dst;
  int dwn;
  int sum;
};
int R, N;
Rule rule[RMAX];
vector<int> at[NMAX];
int ans1[NMAX];
int ans2[NMAX];
void solve1() {
  static Heap<int> H;
  H.Init(N, INT_MAX);
  for (int i = 0; i < R; i++) {
    if (rule[i].dst.empty()) {
      const int src = rule[i].src;
      if (rule[i].cnt < H.Get(src)) H.Set(src, rule[i].cnt);
    }
  }
  for (;;) {
    const int u = H.Top();
    if (u < 0) break;
    H.Del(u);
    for (vector<int>::const_iterator it(at[u].begin()); it != at[u].end();
         ++it) {
      rule[*it].sum += H.Get(u);
      if (rule[*it].sum > PI) rule[*it].sum = PI;
      if (++rule[*it].dwn == rule[*it].dst.size()) {
        rule[*it].sum += rule[*it].cnt;
        if (rule[*it].sum > PI) rule[*it].sum = PI;
        const int src = rule[*it].src;
        if (rule[*it].sum < H.Get(src)) H.Set(src, rule[*it].sum);
      }
    }
  }
  for (int i = 0; i < N; i++) {
    ans1[i] = H.Get(i);
    if (ans1[i] == INT_MAX) ans1[i] = -1;
  }
}
enum STATE { FRESH = 0, WORKING, DONE };
STATE state[NMAX];
void solve2(int u) {
  state[u] = WORKING;
  if (ans1[u] == -1) {
    ans2[u] = -1;
  } else {
    ans2[u] = ans1[u];
    vector<int>::const_iterator it, ti;
    for (it = at[u].begin(); it != at[u].end(); ++it) {
      const vector<int> &V = rule[*it].dst;
      bool useless = false;
      int sum = rule[*it].cnt;
      for (ti = V.begin(); ti != V.end(); ++ti) {
        if (state[*ti] == WORKING) {
          sum = -2;
          continue;
        }
        if (state[*ti] == FRESH) solve2(*ti);
        if (ans2[*ti] == -2) {
          sum = -2;
          continue;
        }
        if (ans2[*ti] == -1) {
          useless = true;
          break;
        }
        if (sum >= 0) {
          sum += ans2[*ti];
          if (sum > PI) sum = PI;
        }
      }
      if (useless) continue;
      if (sum == -2) {
        ans2[u] = -2;
        break;
      }
      if (sum > ans2[u]) ans2[u] = sum;
    }
  }
  state[u] = DONE;
}
void solve2() {
  for (int i = 0; i < N; i++) at[i].clear();
  for (int i = 0; i < R; i++) at[rule[i].src].push_back(i);
  for (int i = 0; i < N; i++)
    if (state[i] == FRESH) solve2(i);
}
void solve() {
  solve1();
  solve2();
  for (int i = 0; i < N; i++) printf("%d %d\n", ans1[i], ans2[i]);
}
void input() {
  scanf("%d%d", &R, &N);
  for (int i = 0; i < R; i++) {
    int src, num, dst;
    scanf("%d%d", &src, &num);
    src--;
    rule[i].src = src;
    while (num-- > 0) {
      scanf("%d", &dst);
      dst--;
      if (dst >= 0) {
        rule[i].dst.push_back(dst);
        at[dst].push_back(i);
      } else {
        rule[i].cnt++;
      }
    }
  }
}
int main() {
  input();
  solve();
  return 0;
}
