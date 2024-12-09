#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 1e9 + 7;
double eps = 1e-12;
void solve() {
  vector<long long> ar(3);
  for (auto &it : ar) cin >> it;
  sort((ar).begin(), (ar).end());
  if (ar[0] + ar[1] == ar[2])
    cout << "YES"
         << "\n";
  else if (ar[0] == ar[1]) {
    if (ar[2] % 2 == 0)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  } else if (ar[1] == ar[2]) {
    if (ar[0] % 2 == 0)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  } else
    cout << "NO"
         << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}
