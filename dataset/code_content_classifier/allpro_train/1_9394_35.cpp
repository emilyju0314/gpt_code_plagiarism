#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int K = 25;
int st[MAXN][K + 1];
int LOG[MAXN + 1];
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void gcd_preprocess(int N, int array[]) {
  for (int i = 0; i < N; i++) st[i + 1][0] = array[i];
  for (int j = 1; j <= K; j++)
    for (int i = 1; i + (1 << j) - 1 <= N; i++)
      st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}
int gcd_query(int L, int R) {
  if (L > R) return 0;
  int j = LOG[R - L + 1];
  return gcd(st[L][j], st[R - (1 << j) + 1][j]);
}
int binary_search(int start, int l, int r, int num) {
  int best = -1;
  while (l <= r) {
    int mid = (r - l) / 2 + l;
    if (gcd_query(start, mid) == num)
      best = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  return best;
}
map<int, long long> ans;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int a[n];
  for (int i = (0); i < (n); ++i) cin >> a[i];
  gcd_preprocess(n, a);
  LOG[1] = 0;
  for (int i = 2; i <= MAXN; i++) LOG[i] = LOG[i / 2] + 1;
  for (int i = (1); i < (n + 1); ++i) {
    int start = i;
    while (binary_search(i, start, n, gcd_query(i, start)) != -1) {
      int to = binary_search(i, start, n, gcd_query(i, start));
      ans[gcd_query(i, to)] += 1LL * (to - start + 1);
      start = to + 1;
    }
  }
  int q, x;
  cin >> q;
  for (int i = (0); i < (q); ++i) {
    cin >> x;
    cout << ans[x] << endl;
  }
  return 0;
}
