#include <bits/stdc++.h>
using namespace std;
long long memo[100005], ps[100005], n, c;
int v[100005], st[4 * 100005];
void buildST(int ind, int L, int R) {
  if (L == R)
    st[ind] = v[L];
  else {
    int t = (L + R) / 2;
    buildST((2 * ind), L, t);
    buildST((2 * ind + 1), t + 1, R);
    st[ind] = min(st[(2 * ind)], st[(2 * ind + 1)]);
  }
}
int query(int ind, int L, int R, int l, int r) {
  if (R < l || L > r) return 1000000000;
  if (l <= L && R <= r) return st[ind];
  int t = (L + R) / 2;
  return min(query((2 * ind), L, t, l, r),
             query((2 * ind + 1), t + 1, R, l, r));
}
long long calc(int x) {
  if (x > n) return 0;
  if (n - x + 1 < c) return memo[x] = ps[n] - ps[x - 1];
  if (memo[x] != -1) return memo[x];
  return memo[x] =
             min(v[x] + calc(x + 1), calc(x + c) + ps[x + c - 1] - ps[x - 1] -
                                         query(1, 1, n, x, x + c - 1));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> n >> c;
  ps[0] = 0;
  for (int i = 1; i <= n; i++) cin >> v[i], ps[i] = ps[i - 1] + v[i];
  buildST(1, 1, n);
  memset(memo, -1, sizeof memo);
  cout << calc(1);
  return 0;
}
