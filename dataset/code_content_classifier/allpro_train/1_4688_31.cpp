#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
void func() {
  long long n, k, d;
  cin >> n >> k >> d;
  long long a[n], ans = 0;
  map<long long, long long> b;
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
  }
  if (d == 1) {
    cout << 1 << "\n";
    return;
  }
  for (long long i = 0; i < d; ++i) {
    if (b[a[i]] == 0) {
      ans++;
    }
    b[a[i]]++;
  }
  long long r = ans;
  for (long long i = d; i < n; ++i) {
    if (b[a[i]] == 0) {
      r = r + 1;
    }
    b[a[i]]++;
    b[a[i - d]]--;
    if (b[a[i - d]] == 0) {
      r = r - 1;
    }
    ans = min(ans, r);
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    func();
  }
}
