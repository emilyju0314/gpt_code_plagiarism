#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> vc;
int a[N + 10], dp[N + 10];
int c1[N + 10], c2[N + 10];
int sz[5][N + 10], lis[5][N + 10];
int ln;
bool mrk[N + 10], mark[N + 10];
void LIS(int n, int x, int y, bool m) {
  for (int i = 0; i < n; i++) {
    int p = lower_bound(dp, dp + ln, a[i]) - dp;
    if (p == ln) ln++;
    dp[p] = a[i], lis[m][i * x + y] = p, sz[m][i * x + y] = p + 1;
  }
  return;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  LIS(n, 1, 0, 0);
  reverse(a, a + n);
  for (int i = 0; i < n; i++) a[i] *= -1;
  memset(dp, 0, sizeof dp), ln = 0;
  LIS(n, -1, n - 1, 1);
  reverse(a, a + n);
  for (int i = 0; i < n; i++)
    if (sz[0][i] + sz[1][i] - 1 == ln) vc.push_back(i), mrk[i] = true;
  for (int i = 0; i < vc.size(); i++) c1[lis[0][vc[i]]]++, c2[lis[1][vc[i]]]++;
  for (int i = 0; i < vc.size(); i++)
    if (c1[lis[0][vc[i]]] == 1 && c2[lis[1][vc[i]]] == 1) mark[vc[i]] = true;
  for (int i = 0; i < n; i++)
    if (mark[i])
      cout << 3;
    else if (mrk[i])
      cout << 2;
    else
      cout << 1;
  return 0;
}
