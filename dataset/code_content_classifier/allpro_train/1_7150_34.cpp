#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
int add(int a, int b) {
  if ((a += b) >= P) a -= P;
  return a < 0 ? a + P : a;
}
int mul(int a, int b) { return 1ll * a * b % P; }
int kpow(int a, int b) {
  int r = 1;
  for (; b; b >>= 1, a = mul(a, a)) {
    if (b & 1) r = mul(r, a);
  }
  return r;
}
const int N = 1e6 + 10;
int n, l, cntd, cntu;
long long sumd, sumu, ans[N];
string s;
void solve(string s, int o) {
  queue<int> q;
  if (o) {
    reverse((s).begin(), (s).end());
    for (int i = (0); i < (n); i++)
      if (s[i] == 'D')
        s[i] = 'U';
      else
        s[i] = 'D';
  }
  l = n;
  cntd = sumd = cntu = sumu = 0;
  for (int i = (n + 1) - 1; i >= (1); i--)
    if (s[i - 1] == 'U') {
      while (l >= 1 && cntu < cntd + 1) {
        if (s[l - 1] == 'U') cntu++, sumu += l;
        l--;
      }
      while (cntu < cntd) cntd--, sumd -= q.front(), q.pop();
      int p = o ? n - i + 1 : i;
      if (cntd == cntu) {
        ans[p] = sumd * 2 - sumu * 2 + i;
      } else {
        ans[p] = sumd * 2 - sumu * 2 + i + n + 1;
      }
      cntu--;
      sumu -= i;
    } else {
      sumd += i;
      cntd++;
      q.push(i);
    }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  cin >> s;
  solve(s, 0);
  solve(s, 1);
  for (int i = (1); i < (n + 1); i++) cout << ans[i] << " \n"[i == n];
  return 0;
}
