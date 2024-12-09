#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
const int mod = 1e9 + 7;
using namespace std;
template <class T>
void cinn(T& x) {
  cin >> x;
}
template <class H, class... T>
void cinn(H& h, T&... t) {
  cinn(h);
  cinn(t...);
}
template <class A>
void cinn(vector<A>& x) {
  for (auto& a : x) cinn(a);
}
void Shazam() {
  string s;
  cinn(s);
  long long l = s.size();
  long long x = -1, y = -1, cnt;
  for (long long i = 1; i < 6; i++) {
    bool got = 0;
    for (long long j = 1; j < 21; j++) {
      long long hav = i * j;
      if (hav < l) continue;
      cnt = hav - l;
      if (cnt <= i) {
        x = i;
        y = j;
        got = 1;
        break;
      }
    }
    if (got) break;
  }
  cout << x << " " << y << "\n";
  long long ind = 0;
  for (long long i = 0; i < x; i++) {
    for (long long j = 0; j < y - 1; j++) {
      cout << s[ind++];
    }
    if (cnt > 0)
      cout << "*", cnt--;
    else
      cout << s[ind++];
    cout << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  while (t--) Shazam();
  return 0;
}
