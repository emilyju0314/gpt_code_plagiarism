#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
long long n;
long long ct0, ct1, x;
string s;
bool c00() {
  long long max0 = ct0 + x;
  return max0 > ct1;
}
bool c11() {
  long long max1 = ct1 + x;
  return max1 > ct0 + 1;
}
bool c01() {
  string str = s;
  long long n0 = n / 2, n1 = (n + 1) / 2;
  long long reqz0 = n0 - ct0;
  long long reqz1 = n1 - ct1;
  if (reqz0 < 0 || reqz1 < 0) return 0;
  for (auto &it : str) {
    if (it == '?') {
      if (reqz0) {
        reqz0--;
        it = '0';
      } else {
        reqz1--;
        it = '1';
      }
    }
  }
  return str.back() == '1';
}
bool c10() {
  string str = s;
  long long n0 = n / 2, n1 = (n + 1) / 2;
  long long reqz0 = n0 - ct0;
  long long reqz1 = n1 - ct1;
  if (reqz0 < 0 || reqz1 < 0) return 0;
  for (auto &it : str) {
    if (it == '?') {
      if (reqz1) {
        reqz1--;
        it = '1';
      } else {
        reqz0--;
        it = '0';
      }
    }
  }
  return str.back() == '0';
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> s;
  n = s.size();
  for (long long i = 0; i < n; i++) {
    ct0 += (s[i] == '0');
    ct1 += (s[i] == '1');
    x += (s[i] == '?');
  }
  if (c00())
    cout << "00"
         << "\n";
  if (c01())
    cout << "01"
         << "\n";
  if (c10())
    cout << "10"
         << "\n";
  if (c11())
    cout << "11"
         << "\n";
  return 0;
}
