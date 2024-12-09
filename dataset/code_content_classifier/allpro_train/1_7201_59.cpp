#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
const int N = 100005;
map<long long, long long> mm;
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  long long cz = 0;
  for (long long i = 0; i <= n - 1; i++) {
    cin >> v[i];
    mm[v[i]] = 1;
    if (v[i] == 0) cz++;
  }
  if (n == 1) {
    cout << 0 << '\n';
    return;
  }
  if (cz == n) {
    cout << 1 << '\n';
    return;
  }
  long long odd = 0, even = 0;
  for (long long i = 1; i <= n; i++) {
    if (mm[i] == 0) {
      if (i % 2 == 0)
        even++;
      else
        odd++;
    }
  }
  long long ans = 0;
  vector<long long> oe, ee, oo;
  vector<long long> spo, spe;
  long long co = 0;
  long long last = -1, curr = -1;
  for (long long i = 1; i <= n - 1; i++) {
    if (v[i] != 0 && v[i - 1] != 0) {
      if (v[i] % 2 != v[i - 1] % 2) ans++;
    }
  }
  for (long long i = 0; i <= n - 1; i++) {
    if (v[i] == 0) {
      co++;
    } else {
      curr = v[i];
      if (co > 0) {
        if (last == -1) {
          if (curr % 2 == 0) {
            spe.push_back(co);
          } else
            spo.push_back(co);
        } else {
          if (last % 2 == 0 && curr % 2 == 1) {
            oe.push_back(co);
          } else if (last % 2 == 1 && curr % 2 == 0) {
            oe.push_back(co);
          } else if (last % 2 == 0 && curr % 2 == 0) {
            ee.push_back(co);
          } else
            oo.push_back(co);
        }
      }
      last = v[i];
      co = 0;
    }
  }
  if (co) {
    if (last % 2 == 0) {
      spe.push_back(co);
    } else
      spo.push_back(co);
  }
  sort((oo).begin(), (oo).end());
  sort((ee).begin(), (ee).end());
  sort((oe).begin(), (oe).end());
  sort((spo).begin(), (spo).end());
  sort((spe).begin(), (spe).end());
  for (long long i = 0; i <= (long long)oo.size() - 1; i++) {
    if (odd >= oo[i]) {
      odd -= oo[i];
    } else {
      ans += 2;
    }
  }
  for (long long i = 0; i <= (long long)ee.size() - 1; i++) {
    if (even >= ee[i]) {
      even -= ee[i];
    } else {
      ans += 2;
    }
  }
  for (long long i = 0; i <= (long long)spo.size() - 1; i++) {
    if (odd >= spo[i]) {
      odd -= spo[i];
    } else {
      ans += 1;
    }
  }
  for (long long i = 0; i <= (long long)spe.size() - 1; i++) {
    if (even >= spe[i]) {
      even -= spe[i];
    } else {
      ans += 1;
    }
  }
  ans += (long long)oe.size();
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) {
    solve();
  }
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
