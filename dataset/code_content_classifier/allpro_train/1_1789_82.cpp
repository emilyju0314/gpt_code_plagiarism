#include <bits/stdc++.h>
using namespace std;
long long const delta = 1000000007;
long long mark[(long long)2e5 + 8];
int main() {
  std::ios::sync_with_stdio(0);
  ;
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long ans = a[n - 1];
  mark[a[n - 1]] = 1;
  for (long long i = n - 2; i >= 0; i--) {
    if (!mark[a[i]]) {
      ans = a[i];
      mark[a[i]] = 1;
    }
  }
  cout << ans;
  return 0;
}
