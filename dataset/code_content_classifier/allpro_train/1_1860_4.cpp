#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
void vrikodara(long long n = 12) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(n) << fixed;
}
long long lb = 100000;
long long A, B;
vector<string> v;
bool fun(long long x, long long y) {
  set<string> s;
  for (long long i = 0; i < A; i += x) {
    for (long long j = 0; j < B; j += y) {
      string s1 = "";
      for (long long a = i; a < i + x; a++) {
        for (long long b = j; b < j + y; b++) {
          s1 += v[a][b];
        }
      }
      set<string> t;
      t.insert(s1);
      reverse(s1.begin(), s1.end());
      t.insert(s1);
      if (x == y) {
        string s2 = "";
        for (long long b = j; b < j + y; b++) {
          for (long long a = i + x - 1; a >= i; a--) {
            s2 += v[a][b];
          }
        }
        t.insert(s2);
        reverse(s2.begin(), s2.end());
        t.insert(s2);
      }
      for (auto k : t) {
        if (s.count(k)) return false;
        s.insert(k);
      }
    }
  }
  return true;
}
void solve() {
  cin >> A >> B;
  v.resize(A);
  for (long long i = 0; i < A; i++) cin >> v[i];
  ;
  vector<long long> va, vb;
  for (long long i = 1; i <= A; i++) {
    if (A % i == 0) va.push_back(i);
  }
  for (long long j = 1; j <= B; j++) {
    if (B % j == 0) vb.push_back(j);
  }
  set<pair<long long, long long> > ans;
  long long area = A * B + 1;
  long long xd, yd;
  for (auto i : va) {
    for (auto j : vb) {
      bool f = fun(i, j);
      if (f) {
        if (area == i * j) {
          if (i < xd) {
            xd = i;
            yd = j;
          }
        } else if (area > i * j) {
          area = i * j;
          xd = i;
          yd = j;
        }
        ans.insert({i, j});
      }
    }
  }
  cout << ans.size() << '\n';
  cout << xd << ' ' << yd;
}
int32_t main() {
  vrikodara();
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
