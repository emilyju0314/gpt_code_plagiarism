#include <bits/stdc++.h>
using namespace std;
template <typename T>
void maxtt(T& t1, T t2) {
  t1 = max(t1, t2);
}
template <typename T>
void mintt(T& t1, T t2) {
  t1 = min(t1, t2);
}
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "RDLU";
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int& x, int y, int mod = 998244353) {
  assert(y >= 0);
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et(int x = -1) {
  printf("%d\n", x);
  exit(0);
}
long long fastPow(long long x, long long y, int mod = 998244353) {
  long long ans = 1;
  while (y > 0) {
    if (y & 1) ans = (x * ans) % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
long long gcd1(long long x, long long y) { return y ? gcd1(y, x % y) : x; }
int vis[300135], pos[300135];
vector<int> qs[300135];
vector<pair<int, int> > vp[300135];
int SZ = 550;
bool ck() {
  for (int i = 1; i <= n; ++i) pos[i] = vis[i] = 0, vp[i].clear();
  for (int(i) = 1; (i) <= (int)(m); (i)++)
    if (qs[i].size() > SZ) {
      for (int(j) = 0; (j) < (int)(qs[i].size()); (j)++) {
        vis[qs[i][j]] = i;
        pos[qs[i][j]] = j;
      }
      for (int(j) = 1; (j) <= (int)(m); (j)++)
        if (i != j) {
          int lst = (1 << 30), fg = 1;
          for (int id : qs[j]) {
            if (vis[id] != i)
              fg = 1;
            else {
              if (!fg && lst <= pos[id] && lst + 1 != pos[id]) return 0;
              if (fg && lst <= pos[id]) return 0;
              fg = 0;
              lst = pos[id];
            }
          }
        }
    } else {
      for (int(j) = 0; (j) < (int)(qs[i].size()); (j)++)
        for (int z = j + 1; z < qs[i].size(); z++) {
          vp[qs[i][j]].push_back({qs[i][z - 1], qs[i][z]});
        }
    }
  for (int(i) = 1; (i) <= (int)(n); (i)++) vis[i] = 0;
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    for (auto p : vp[i]) {
      if (vis[p.second] == i && pos[p.second] != p.first) return 0;
      vis[p.second] = i;
      pos[p.second] = p.first;
    }
  }
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    vis[i] = 0;
    vp[i].clear();
  }
  return 1;
}
void fmain(int tid) {
  scanf("%d%d", &n, &m);
  for (int(i) = 1; (i) <= (int)(m); (i)++) {
    scanf("%d", &k);
    qs[i].clear();
    qs[i].resize(k, 0);
    for (int(j) = 0; (j) < (int)(k); (j)++) scanf("%d", &qs[i][j]);
  }
  puts(ck() ? "Robot" : "Human");
}
int main() {
  int t = 1;
  scanf("%d", &t);
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
