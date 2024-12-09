#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long Hashimoto = 0, Kanna = 1;
  char I_Love = getchar();
  while (I_Love < '0' || I_Love > '9') {
    if (I_Love == '-') Kanna = -1;
    I_Love = getchar();
  }
  while (I_Love >= '0' && I_Love <= '9') {
    Hashimoto = Hashimoto * 10 + I_Love - '0';
    I_Love = getchar();
  }
  return Hashimoto * Kanna;
}
template <typename T1, typename T2>
inline void Umax(T1 &a, T2 b) {
  if (a < b) a = b;
}
template <typename T1, typename T2>
inline void Umin(T1 &a, T2 b) {
  if (a > b) a = b;
}
long long pw[444444];
struct data {
  int len;
  long long h, rh;
  data() {
    len = 0;
    h = 0;
    rh = 0;
  }
} dat[2222222];
int n;
int d;
string s;
inline data operator+(data a, data b) {
  data ret;
  ret.len = a.len + b.len;
  ret.h = (a.h + b.h * pw[a.len]);
  ret.rh = (b.rh + a.rh * pw[b.len]);
  return ret;
}
void modify(int &pos, int &val, int k, int a, int b) {
  if (pos == a && a == b - 1) {
    dat[k].len = 1;
    dat[k].h = dat[k].rh = val;
    return;
  }
  int mid = a + b >> 1;
  if (pos < mid)
    modify(pos, val, k * 2 + 1, a, mid);
  else
    modify(pos, val, k * 2 + 2, mid, b);
  dat[k] = dat[k * 2 + 1] + dat[k * 2 + 2];
}
data query(int l, int r, int k, int a, int b) {
  if (l >= b || a >= r) return data();
  if (l <= a && b <= r) {
    return dat[k];
  }
  int mid = a + b >> 1;
  return query(l, r, k * 2 + 1, a, mid) + query(l, r, k * 2 + 2, mid, b);
}
void dfs(int pos, bool f) {
  if (pos == n) {
    if (f) {
      cout << s << endl;
      ;
      exit(0);
    }
    return;
  }
  char lb = (f ? 'a' : s[pos]);
  for (int i = lb; i < ('z' + 1); ++i) {
    s[pos] = i;
    modify(pos, i, 0, 0, n);
    if (pos + 1 >= d) {
      data sav = query(pos + 1 - d, pos + 1, 0, 0, n);
      if (sav.h == sav.rh) {
        continue;
      }
    }
    if (pos + 1 >= d + 1) {
      data sav = query(pos - d, pos + 1, 0, 0, n);
      if (sav.h == sav.rh) {
        continue;
      }
    }
    dfs(pos + 1, f | (i > lb));
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  pw[0] = 1;
  for (int i = 1; i < (444444); ++i) pw[i] = pw[i - 1] * 29;
  cin >> d >> s;
  n = s.size();
  dfs(0, 0);
  cout << "Impossible" << endl;
  return 0;
}
