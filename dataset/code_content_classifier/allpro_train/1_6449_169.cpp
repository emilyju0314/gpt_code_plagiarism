#include <bits/stdc++.h>
const double EPS = 1e-7, PI = acos(-1.0);
using namespace std;
template <class T>
inline T IN(T& num) {
  num = 0;
  char c = getchar(), f = 0;
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') f = 1, c = getchar();
  while ('0' <= c && c <= '9') num = num * 10 + c - '0', c = getchar();
  if (f) num = -num;
  return num;
}
int n;
long long N = 10000000;
int l[50], m[50], w[50];
map<pair<int, int>, pair<int, long long> > mp;
map<pair<int, int>, pair<int, long long> >::iterator it;
int res;
long long ans, Bn[2];
void solve(int st, int ed, bool f) {
  Bn[f] = 1;
  for (int i = st; i < ed; ++i) Bn[f] *= 3;
  for (int i = 0; i < Bn[f]; ++i) {
    int a = 0, b = 0, c = 0;
    int x = i, y;
    for (int j = st; j < ed; ++j) {
      y = x % 3;
      x /= 3;
      if (y == 0) {
        a += l[j];
        b += m[j];
      } else if (y == 1) {
        a += l[j];
        c += w[j];
      } else {
        b += m[j];
        c += w[j];
      }
    }
    if (f) {
      pair<int, int> p = pair<int, int>(b - a, c - a);
      pair<int, long long> now = make_pair(a, i);
      it = mp.find(p);
      if (it == mp.end())
        mp[p] = now;
      else if (it->second.first < a)
        it->second = now;
    } else {
      it = mp.find(pair<int, int>(a - b, a - c));
      if (it != mp.end() && it->second.first + a > res) {
        res = it->second.first + a;
        ans = 1LL * it->second.second + 1LL * i * Bn[!f];
      }
    }
  }
}
char outs[3][5] = {"LM", "LW", "MW"};
int main() {
  IN(n);
  for (int i = 0; i < n; ++i) IN(l[i]), IN(m[i]), IN(w[i]);
  ans = -1;
  res = INT_MIN;
  int mid = n / 2 + 1;
  solve(0, mid, true);
  solve(mid, n, false);
  if (ans == -1)
    printf("Impossible\n");
  else {
    for (int i = 0; i < n; ++i) {
      printf("%s\n", outs[ans % 3]);
      ans /= 3;
    }
  }
  return 0;
}
