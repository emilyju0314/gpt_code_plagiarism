#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5 * 100005;
long long n;
long long a[MAXN];
long long pref[MAXN];
long long sum;
multiset<long long> s;
long long x;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= (n + 1) / 2; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
  }
  cin >> x;
  for (int i = (n + 1) / 2 + 1; i <= n; i++) {
    a[i] = x;
    pref[i] = pref[i - 1] + x;
  }
  int k = n / 2 + 1;
  for (int i = 1; i <= k; i++) {
    sum += a[i];
  }
  s.insert(0);
  for (int i = 1; i <= n - k; i++) {
    s.insert((long long)i * x - pref[i]);
  }
  for (int i = k; i <= n; i++) {
    if (sum + *s.begin() + x * (i - k) > 0) {
      cout << i << '\n';
      return 0;
    }
    s.erase(s.find((n - i) * x - pref[n - i]));
  }
  cout << -1 << '\n';
}
