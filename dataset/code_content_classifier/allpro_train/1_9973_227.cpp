#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18 + 7;
const long double EPS = 1e-8;
const long long MAXI = 20000;
const long long MOD = 16714589;
const long long MAXST = 2000000;
const long double PI = 3.14159265358979323;
ostream &operator<<(ostream &stream, const pair<long long, long long> &p) {
  stream << p.first << ' ' << p.second << ' ';
  return stream;
}
signed main() {
  {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  };
  long long n;
  cin >> n;
  long long kol1 = 0, kol0 = 0;
  string second;
  cin >> second;
  for (auto i : second) {
    if (i == 'n')
      kol1++;
    else if (i == 'z')
      kol0++;
  }
  for (long long i = 0; i < kol1; i++) cout << 1 << ' ';
  for (long long i = 0; i < kol0; i++) cout << 0 << ' ';
  return 0;
}
