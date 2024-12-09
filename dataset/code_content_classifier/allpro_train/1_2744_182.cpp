#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const long double PI = acos(-1);
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
const int mod1 = 998244353;
const long long INF = 2e18;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    int z;
    int mini = MOD;
    for (int i = 1; i <= n; i++) {
      cin >> v[i];
      if (mini > (v[i] - i + n) / n) {
        mini = (v[i] - i + n) / n;
        z = i;
      }
    }
    cout << z << "\n";
  }
  return 0;
}
