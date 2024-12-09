#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 100, MAXN = 2e3 + 5;
unsigned long long dp1[MAX];
unsigned long long dp2[MAX];
unsigned long long dp3[MAX];
int a[MAXN];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) dp1[a[j] - a[i]]++;
  for (int i = 0; i < MAX / 2; ++i)
    if (dp1[i])
      for (int j = 0; j < MAX / 2; ++j)
        if (dp1[j]) dp2[i + j] += dp1[i] * dp1[j];
  for (int i = MAX - 2; i; --i) dp3[i] = dp3[i + 1] + dp1[i];
  unsigned long long sol = 0;
  for (int i = 0; i < MAX - 1; ++i) sol += dp2[i] * dp3[i + 1];
  unsigned long long uk = (unsigned long long)(n * (n - 1) / 2) *
                          (unsigned long long)(n * (n - 1) / 2) *
                          (unsigned long long)(n * (n - 1) / 2);
  cout << fixed << setprecision(10) << (double)sol / (double)uk;
}
