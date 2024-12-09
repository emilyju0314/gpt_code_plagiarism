#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const long long MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<long long> ar;
    long long sum = 0;
    for (long long i = 1; i <= 10; i++) {
      long long x = m * i;
      ar.push_back(x % 10);
      sum += x % 10;
    }
    long long f = n / m;
    sum *= (f / 10);
    for (long long i = 0; i < f % 10; i++) sum += ar[i];
    cout << sum << "\n";
  }
  return 0;
}
