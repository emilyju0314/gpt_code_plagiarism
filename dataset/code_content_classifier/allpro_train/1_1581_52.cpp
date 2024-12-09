#include <bits/stdc++.h>
using namespace std;
using std::ios;
constexpr int MOD = 1e9 + 7;
constexpr int mod = 998244353;
template <typename T>
T power(T a, T b) {
  T r = 1;
  while (b) {
    if (b & 1) r *= a;
    b /= 2;
    a *= a;
  }
  return r;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n + 1), lk(n + 1), tmp;
    for (int i = 1; i < n + 1; i++) cin >> a[i];
    for (int i = 1; i < n + 1; i++) cin >> lk[i];
    for (int i = 1; i <= n; i++) {
      if (!lk[i]) tmp.push_back(a[i]);
    }
    sort((tmp).begin(), (tmp).end(), greater<int>());
    int p = 0, k = 0, d = 0;
    for (int i = 1; i <= n; i++) {
      if (lk[i])
        cout << a[i] << ' ';
      else
        cout << tmp[d++] << ' ';
    }
    cout << '\n';
  }
}
