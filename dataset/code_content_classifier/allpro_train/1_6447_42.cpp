#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void si(T &x) {
  register int c = getchar();
  x = 0;
  int neg = 0;
  for (; ((c<48 | c> 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  if (neg) x = -x;
}
long long bigmod(long long p, long long e, long long M) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return ret;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long modinverse(long long a, long long M) { return bigmod(a, M - 2, M); }
void io() { freopen("/Users/MyMac/Desktop/in.txt", "r", stdin); }
const int N = 1001;
int ax[N];
int bx[N];
int n, m;
int check(int Mask) {
  int prv = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if ((Mask & (1 << i)) && !prv) {
      prv = 1;
      cnt++;
    }
    if ((Mask & (1 << i)) == 0) {
      prv = 0;
    }
  }
  return cnt;
}
bool vis[1 << 5][21][12][12][12][12][12];
vector<int> Res;
bool F(int Mask, int ind, int a, int b, int c, int d, int e) {
  if (ind == m) {
    if (ax[0] == a && ax[1] == b && ax[2] == c && ax[3] == d && ax[4] == e) {
      return 1;
    }
    return 0;
  }
  if (vis[Mask][ind][a][b][c][d][e]) return 0;
  vis[Mask][ind][a][b][c][d][e] = 1;
  for (int i = 0; i < 1 << n; i++) {
    if (check(i) == bx[ind]) {
      int bol[5];
      memset(bol, 0, sizeof(bol));
      bol[0] = a, bol[1] = b, bol[2] = c, bol[3] = d, bol[4] = e;
      for (int j = 0; j < (n); j++)
        if ((Mask & (1 << j)) == 0 && (i & (1 << j))) bol[j]++;
      Res.push_back((i));
      bool k = F(i, ind + 1, bol[0], bol[1], bol[2], bol[3], bol[4]);
      if (k) {
        return 1;
      }
      Res.pop_back();
    }
  }
  return 0;
}
int main() {
  si(n);
  si(m);
  for (int i = 0; i < (n); i++) si(ax[i]);
  for (int j = 0; j < (m); j++) si(bx[j]);
  F(0, 0, 0, 0, 0, 0, 0);
  for (int i = 0; i < (n); i++) {
    for (int j = 0; j < Res.size(); j++) {
      if (Res[j] & (1 << i))
        printf("*");
      else
        printf(".");
    }
    puts("");
  }
  return 0;
}
