#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
template <typename T>
using v = vector<T>;
const long long inf = 4611686018427387903;
void read() {}
template <typename Arg, typename... Args>
void read(Arg& arg, Args&... args) {
  cin >> (arg);
  read(args...);
}
void print() {}
template <typename Arg, typename... Args>
void print(Arg arg, Args... args) {
  cout << (arg) << " ";
  print(args...);
}
void debug() { cout << endl; }
template <typename Arg, typename... Args>
void debug(Arg arg, Args... args) {
  cout << (arg) << " ";
  debug(args...);
}
int getInt() {
  int a;
  cin >> a;
  return a;
}
const int N = 1e6 + 1;
vector<int> g[N];
int height[N];
int parent[N];
const int M = 17;
int kthAncestor[N][M];
inline void precalc(int cur, int h = 0, int p = -1) {
  height[cur] = h;
  parent[cur] = p;
  for (int j = 0; j < M; j++) kthAncestor[cur][j] = -1;
  if (p != -1) {
    kthAncestor[cur][0] = p;
    int pos = p;
    int k = 0;
    while (kthAncestor[pos][k] != -1) {
      kthAncestor[cur][k + 1] = kthAncestor[pos][k];
      pos = kthAncestor[pos][k];
      k++;
    }
  }
  for (int i : g[cur])
    if (i != p) precalc(i, h + 1, cur);
}
char included[N];
void run() {
  int n, kk;
  read(n, kk);
  n++;
  for (int i = (2); i < (n); i++) {
    int v, u;
    read(v, u);
    g[v].push_back(u);
    g[u].push_back(v);
  }
  precalc(n - 1);
  for (int i = (1); i < (n); i++) included[i] = 0;
  included[n - 1] = 1;
  int leftToAdd = n - 2 - kk;
  vector<int> ans;
  for (int i = n - 2; i; i--) {
    if (included[i]) continue;
    int k = M - 1;
    int p = i;
    while (k >= 0) {
      if (kthAncestor[p][k] != -1 && !included[kthAncestor[p][k]]) {
        p = kthAncestor[p][k];
      } else
        k--;
    }
    int nearestIncludedAncestor = kthAncestor[p][0];
    int distance = height[i] - height[nearestIncludedAncestor];
    if (distance > leftToAdd)
      ans.push_back(i);
    else {
      leftToAdd -= height[i] - height[nearestIncludedAncestor];
      p = i;
      while (!included[p]) {
        included[p] = 1;
        p = parent[p];
      }
    }
  }
  reverse(ans.begin(), ans.end());
  for (int i : ans) print(i);
}
int32_t main() {
  srand(time(0));
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(15);
  run();
  return 0;
}
