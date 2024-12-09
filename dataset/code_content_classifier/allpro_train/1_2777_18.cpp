#include <bits/stdc++.h>
using namespace std;
struct hash_pair {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(pair<uint64_t, uint64_t> x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x.first + FIXED_RANDOM) ^
           (splitmix64(x.second + FIXED_RANDOM) >> 1);
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, a, b;
  cin >> n >> m;
  unordered_set<pair<int, int>, hash_pair> s;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    s.insert({min(a, b), max(a, b)});
  }
  for (int i = 1; i <= sqrt(n); ++i) {
    if (n % i == 0) {
      bool ok2 = true, ok3 = true;
      for (auto it : s) {
        a = it.first + i;
        b = it.second + i;
        if (a > n) a -= n;
        if (b > n) b -= n;
        if (!s.count({min(a, b), max(a, b)})) {
          ok2 = false;
          break;
        }
      }
      if (ok2 == true) {
        cout << "Yes";
        return 0;
      }
      if (i != 1) {
        for (auto it : s) {
          a = it.first + n / i;
          b = it.second + n / i;
          if (a > n) a -= n;
          if (b > n) b -= n;
          if (!s.count({min(a, b), max(a, b)})) {
            ok3 = false;
            break;
          }
        }
        if (ok3 == true) {
          cout << "Yes";
          return 0;
        }
      }
    }
  }
  cout << "No";
}
