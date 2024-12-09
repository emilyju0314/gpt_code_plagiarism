#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007LL;
int n, m;
int a[100005];
int main() {
  unordered_map<int, long long> cnt1;
  unordered_map<int, long long> cnt2;
  cnt1.clear();
  cnt2.clear();
  cin >> n >> m;
  bool isone = false;
  for (int i = 1; i <= m; ++i) {
    cin >> a[i];
    if (a[i] == 1) isone = true;
  }
  if (n == 1) {
    if (isone)
      cout << 0 << endl;
    else
      cout << 1 << endl;
    return 0;
  }
  for (int i = m; i >= 1; --i) {
    cnt1[a[i] - i] = cnt1[a[i] - i - 1] + 1;
    cnt2[a[i] + i] = cnt2[a[i] + i + 1] + 1;
  }
  long long tot = 0LL;
  for (int i = 1; i <= n; ++i) {
    long long rn =
        min((long long)(n - i), max((long long)m + 1 - cnt1[i], 0LL));
    long long ln =
        min((long long)(i - 1), max((long long)m + 1 - cnt2[i], 0LL));
    tot += ln + rn + 1;
  }
  cout << tot << endl;
  return 0;
}
