#include <bits/stdc++.h>
using namespace std;
template <typename C>
void ma(C& a, C b) {
  if (a < b) a = b;
}
template <typename C>
void mi(C& a, C b) {
  if (a > b) a = b;
}
int cas, n, l[251], r[251], w[251], roz[251];
void licz_roz(int nr) {
  if (w[nr] == -1) {
    licz_roz(l[nr]);
    licz_roz(r[nr]);
    if (roz[r[nr]] & 1) swap(l[nr], r[nr]);
    roz[nr] = 1 + roz[l[nr]] + roz[r[nr]];
  } else
    roz[nr] = 0;
}
int dp[251][2][3];
int ak[251][2][3];
inline int mima(int a, int b, bool jak) { return ((a > b) ^ jak) ? a : b; }
inline int mima3(int a, int b, int c, bool jak) {
  return mima(mima(a, b, jak), c, jak);
}
int dfs(int nr, bool kto, int pas) {
  if (w[nr] != -1) return w[nr];
  if (roz[nr] == 1) return mima(w[l[nr]], w[r[nr]], kto ^ (pas == 2));
  int& res = dp[nr][kto][pas];
  if (ak[nr][kto][pas] == cas) return res;
  ak[nr][kto][pas] = cas;
  if (pas) {
    if (roz[nr] & 1) {
      res = dfs(nr, !kto, 0);
      if (roz[l[nr]] & 1) {
        int pom =
            mima(dfs(l[nr], kto, 0),
                 dfs(r[nr], !kto, roz[l[nr]] == 1 && pas == 1 ? 2 : 1), !kto);
        res = mima(res, pom, kto);
        pom = mima(dfs(r[nr], kto, 0),
                   dfs(l[nr], !kto, roz[r[nr]] == 1 && pas == 1 ? 2 : 1), !kto);
        res = mima(res, pom, kto);
      } else {
        if (roz[r[nr]]) {
          int pom =
              mima(dfs(l[nr], !kto, 0),
                   dfs(r[nr], kto, roz[l[nr]] == 0 && pas == 1 ? 2 : 1), !kto);
          res = mima(res, pom, kto);
        }
        if (roz[l[nr]]) {
          int pom =
              mima(dfs(r[nr], !kto, 0),
                   dfs(l[nr], kto, roz[r[nr]] == 0 && pas == 1 ? 2 : 1), !kto);
          res = mima(res, pom, kto);
        }
      }
    } else {
      res = mima(dfs(r[nr], kto, 0),
                 dfs(l[nr], kto, roz[r[nr]] == 0 && pas == 1 ? 2 : 1), kto);
    }
  } else {
    if (roz[nr] & 1) {
      if (roz[l[nr]] & 1)
        res = mima(dfs(l[nr], kto, 1), dfs(r[nr], kto, 1), kto);
      else
        res = mima(dfs(l[nr], kto, 0), dfs(r[nr], kto, 0), kto);
    } else {
      int pom = mima(dfs(l[nr], kto, 0), dfs(r[nr], !kto, 0), !kto);
      int pom2 = mima(dfs(l[nr], !kto, 1), dfs(r[nr], kto, 1), !kto);
      res = mima(pom, pom2, kto);
    }
  }
  return res;
}
void test() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &w[i]);
    if (w[i] == -1) {
      scanf("%d", &l[i]);
      scanf("%d", &r[i]);
    }
  }
  licz_roz(0);
  printf("%d\n", dfs(0, 0, 0));
}
int main() {
  int _;
  scanf("%d", &_);
  for (cas = 1; cas <= _; cas++) test();
}
