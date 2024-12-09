#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e17;
long long MOD = 1e9 + 9;
long long n, s;
long long a[100005];
long long check(long long k) {
  vector<long long> v;
  for (int i = 0; i < n; i++) {
    v.push_back(a[i] + (k * (i + 1)));
  }
  sort(v.begin(), v.end());
  long long sum = 0;
  for (int i = 0; i < k; i++) {
    sum += v[i];
  }
  return sum;
}
int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++) cin >> a[i];
  long long l = 0, r = n + 1;
  long long r1 = 0, r2 = 0;
  long long p;
  while (l < r) {
    long long mid = (l + r) / 2;
    p = check(mid);
    if (p <= s) {
      r1 = mid, r2 = p;
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  cout << r1 << " " << r2;
  return 0;
}
