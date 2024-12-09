#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
struct point {
  int first, second;
  point(int first = 0, int second = 0) : first(first), second(second) {}
  point operator-(point a) { return point(first - a.first, second - a.second); }
  long long operator^(point a) {
    return (long long)first * a.second - (long long)second * a.first;
  }
  long long operator*(point a) {
    return (long long)first * a.first + (long long)second * a.second;
  }
  void input() { scanf("%d%d", &first, &second); }
};
int sgn(long long a) { return (a > 0) - (a < 0); }
int is_on(point a, point b, point c) {
  if (sgn((a - b) ^ (a - c))) return 0;
  return sgn((a - c) * (c - b)) > 0;
}
point ston[10], mons[1111];
int flag[1111], id[10], n, k, runs, used;
vector<int> adj[10][1111];
bool judge(int u) {
  if (used >= k) return false;
  flag[u] = runs;
  int shoot = id[used++];
  for (int i = 0; i < adj[shoot][u].size(); i++) {
    int v = adj[shoot][u][i];
    if (flag[v] != runs) {
      if (!judge(v)) return false;
    }
  }
  return true;
}
int main() {
  scanf("%d%d", &k, &n);
  for (int i = 0; i < k; i++) ston[i].input();
  for (int i = 0; i < n; i++) mons[i].input();
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      for (int p = 0; p < n; p++)
        if (p != j) {
          if (is_on(ston[i], mons[j], mons[p])) adj[i][j].push_back(p);
          if (adj[i][j].size() >= k) break;
        }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) id[j] = j;
    do {
      ++runs;
      used = 0;
      if (judge(i)) {
        ans++;
        break;
      }
    } while (next_permutation(id, id + k));
  }
  printf("%d\n", ans);
  return 0;
}
