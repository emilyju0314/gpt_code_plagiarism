#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main() {
  ios_base::sync_with_stdio(0);
  int n, k;
  string s;
  cin >> n >> k >> s;
  if (n == 1) {
    cout << "0";
    return 0;
  }
  int puste = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'W') s[i] = '0';
    if (s[i] == 'B') s[i] = '1';
    if (s[i] == 'X') ++puste;
  }
  vector<vector<int> > gdzieL(n, vector<int>(2, -1));
  if (s[0] == '1') gdzieL[0][1] = 0;
  if (s[0] == '0') gdzieL[0][0] = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      gdzieL[i][j] = gdzieL[i - 1][j];
      if (s[i] != 'X' && s[i] - '0' == j) gdzieL[i][j] = i;
    }
  }
  vector<vector<long long> > dp1(n, vector<long long>(2));
  for (int i = 0; i < n; ++i) {
    if (gdzieL[i][1] < i) {
      int l = 1, p = min(i + 1, i - gdzieL[i][1]);
      dp1[i][0] = (i == 0) ? 0 : dp1[i - 1][1];
      if (i - p + 1 >= 2) dp1[i][0] -= dp1[i - p - 1][1];
      if (i - p + 1 == 0) dp1[i][0] = (dp1[i][0] + 1) % MOD;
      if (dp1[i][0] < 0) dp1[i][0] += MOD;
    } else
      dp1[i][0] = 0;
    if (gdzieL[i][0] < i) {
      int l = 1, p = min(k - 1, i - gdzieL[i][0]);
      dp1[i][1] = (i == 0) ? 0 : dp1[i - 1][0];
      if (i - p + 1 >= 2) dp1[i][1] -= dp1[i - p - 1][0];
      if (i - p + 1 == 0) dp1[i][1] = (dp1[i][1] + 1) % MOD;
      if (dp1[i][1] < 0) dp1[i][1] += MOD;
    } else
      dp1[i][1] = 0;
    if (i != 0) {
      dp1[i][0] = (dp1[i][0] + dp1[i - 1][0]) % MOD;
      dp1[i][1] = (dp1[i][1] + dp1[i - 1][1]) % MOD;
    }
  }
  vector<vector<int> > gdzieP(n, vector<int>(2, n));
  if (s[n - 1] == '0') gdzieP[n - 1][0] = n - 1;
  if (s[n - 1] == '1') gdzieP[n - 1][1] = n - 1;
  for (int i = n - 2; i >= 0; --i) {
    for (int j = 0; j < 2; ++j) {
      gdzieP[i][j] = gdzieP[i + 1][j];
      if (s[i] != 'X' && s[i] - '0' == j) gdzieP[i][j] = i;
    }
  }
  vector<vector<long long> > dp0(n, vector<long long>(2));
  for (int i = n - 1; i >= 0; --i) {
    if (gdzieP[i][1] > i) {
      int l = 1, p = min(k - 1, gdzieP[i][1] - i);
      dp0[i][0] = (i == n - 1) ? 0 : dp0[i + 1][1];
      if (i + p - 1 <= n - 3) dp0[i][0] -= dp0[i + p + 1][1];
      if (i + p - 1 == n - 1) dp0[i][0] = (dp0[i][0] + 1) % MOD;
      if (dp0[i][0] < 0) dp0[i][0] += MOD;
    } else
      dp0[i][0] = 0;
    if (gdzieP[i][0] > i) {
      int l = 1, p = min(n - i, gdzieP[i][0] - i);
      dp0[i][1] = (i == n - 1) ? 0 : dp0[i + 1][0];
      if (i + p - 1 <= n - 3) dp0[i][1] -= dp0[i + p + 1][0];
      if (i + p - 1 == n - 1) dp0[i][1] = (dp0[i][1] + 1) % MOD;
      if (dp0[i][1] < 0) dp0[i][1] += MOD;
    } else
      dp0[i][1] = 0;
    if (i != n - 1) {
      dp0[i][0] = (dp0[i][0] + dp0[i + 1][0]) % MOD;
      dp0[i][1] = (dp0[i][1] + dp0[i + 1][1]) % MOD;
    }
  }
  vector<vector<long long> > dp01(n, vector<long long>(2));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < 2; ++j) {
      if (gdzieP[i][j ^ 1] > i) {
        int l = 1, p = min(k - 1, gdzieP[i][j ^ 1] - i);
        dp01[i][j] = (i == n - 1) ? 0 : dp01[i + 1][j ^ 1];
        if (i + p - 1 <= n - 3) dp01[i][j] -= dp01[i + p + 1][j ^ 1];
        if (i + p - 1 == n - 1) dp01[i][j] = (dp01[i][j] + 1) % MOD;
        if (dp01[i][j] < 0) dp01[i][j] += MOD;
      } else
        dp01[i][j] = 0;
      if (i != n - 1) dp01[i][j] = (dp01[i][j] + dp01[i + 1][j]) % MOD;
    }
  }
  long long wsz = 1;
  for (int i = 0; i < puste; ++i) wsz = (wsz * 2) % MOD;
  long long zle =
      (dp1[n - 1][0] - dp1[n - 2][0] + dp1[n - 1][1] - dp1[n - 2][1] +
       dp0[0][0] - dp0[1][0] + dp0[0][1] - dp0[1][1] - dp01[0][0] + dp01[1][0] -
       dp01[0][1] + dp01[1][1]) %
      MOD;
  while (zle < 0) zle += MOD;
  for (int i = 0; i < n - 1; ++i) {
    if (gdzieL[i][1] <= i - k) {
      int l = k, p = min(i + 1, i - gdzieL[i][1]);
      long long a = (i - l + 1 == 0) ? 0 : dp1[i - l][1];
      if (i - p + 1 >= 2) a -= dp1[i - p - 1][1];
      if (i - p + 1 == 0) a = (a + 1) % MOD;
      if (a < 0) a += MOD;
      long long b = dp0[i + 1][1];
      if (i + 2 < n) b -= dp0[i + 2][1];
      if (b < 0) b += MOD;
      long long c = dp01[i + 1][1];
      if (i + 2 < n) c -= dp01[i + 2][1];
      if (c < 0) c += MOD;
      long long d = b - c;
      if (d < 0) d += MOD;
      zle = (zle + a * d) % MOD;
    }
  }
  long long odp = wsz - zle;
  if (odp < 0) odp += MOD;
  cout << odp;
  return 0;
}
