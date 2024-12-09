#include <bits/stdc++.h>
using namespace std;
int cmp(pair<int, int> a, pair<int, int> b) { return a.first > b.first; }
int main() {
  long long n;
  cin >> n;
  pair<long long, long long> a[n];
  long long aa[n], bb[n];
  for (long long i = 0; i < n; i++) {
    long long b, c;
    cin >> b >> c;
    aa[i] = b;
    bb[i] = c;
    a[i].first = b - c;
    a[i].second = i;
  }
  sort(a, a + n, cmp);
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    ans += a[i].first * (i + 1) + bb[a[i].second] * n - aa[a[i].second];
  }
  cout << ans << endl;
}
