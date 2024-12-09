#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long add(long long a, long long b) {
  a %= 1000000007;
  b %= 1000000007;
  return (a + b) % 1000000007;
}
long long sub(long long a, long long b) {
  a %= 1000000007;
  b %= 1000000007;
  return (a - b + 1000000007) % 1000000007;
}
long long prod(long long a, long long b) {
  a %= 1000000007;
  b %= 1000000007;
  return (a * b) % 1000000007;
}
int a[1000005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    set<pair<long long, long long> > s;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      s.insert({a[i], i});
    }
    int v = 1, last = 1;
    for (int i = 1; i <= n; i++) {
      if (a[i] == v) {
        for (int j = i; j > last; j--) {
          if (a[j] < a[j - 1])
            swap(a[j], a[j - 1]);
          else
            break;
        }
        last = i;
        while (s.size() && s.begin()->second <= i) s.erase(s.begin());
        if (!s.size()) break;
        v = s.begin()->first;
      }
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
  }
  return 0;
}
