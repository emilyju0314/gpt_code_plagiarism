#include <bits/stdc++.h>
using namespace std;
void play() {
  long long n, m;
  cin >> n >> m;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  sort((v).rbegin(), (v).rend());
  long long l = 1, r = n;
  long long ans = -1;
  while (l <= r) {
    long long mid = (l + r) / 2;
    long long res = 0;
    for (long long j = 0; j < n; j++) {
      res += max(v[j] - j / mid, 0LL);
    }
    if (res >= m) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  t = 1;
  for (long long i = 1; i < t + 1; i++) {
    play();
  }
  return 0;
}
