#include <bits/stdc++.h>
using namespace std;
pair<long double, int> v[300100];
long double mi, R[300100], S[300100], cs, sol;
int p, k, n;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i].first;
    v[i].second = i;
  }
  sort(v + 1, v + n + 1);
  cin >> k;
  for (int i = 1; i <= n; ++i) S[i] = S[i - 1] + v[i].first;
  for (int i = n; i >= 1; --i) R[i] = R[i + 1] + v[n].first - v[i].first;
  for (int i = 2; i <= k; ++i) {
    cs += v[i].first * (i - 1) - S[i - 1];
  }
  sol = cs;
  p = k;
  for (int i = k + 1; i <= n; ++i) {
    cs -= (v[i - 1].first - v[i - k].first) * (k - 1) - (R[i - k + 1] - R[i]) +
          (v[n].first - v[i - 1].first) * (k - 1);
    cs += (v[i].first - v[i - k + 1].first) * (k - 1) - (S[i - 1] - S[i - k]) +
          v[i - k + 1].first * (k - 1);
    if (cs < sol) {
      sol = cs;
      p = i;
    }
  }
  p -= k;
  p++;
  for (int i = p; i <= p + k - 1; ++i) cout << v[i].second << " ";
  return 0;
}
