#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
long long n;
bool pt[maxn];
void solve() {
  long long ans = 0;
  for (long long i = 2; i <= n; i++) {
    long long cnt = 0;
    for (long long j = i + i; j <= n; j += i) {
      cnt++;
    }
    ans += cnt * i;
  }
  printf("%lld\n", ans * 4);
}
int main() {
  cin >> n;
  solve();
  return 0;
}
