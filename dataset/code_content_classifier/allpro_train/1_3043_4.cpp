#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0;
  bool flg = false;
  char ch = getchar();
  for (; !isdigit(ch) && ch != 'E'; ch = getchar())
    if (ch == '-') flg = true;
  if (ch == 'E') return -1;
  for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ 48);
  return flg ? -x : x;
}
int k, m, n;
int w[2][32];
int LP, LN, RP, RN, P, N, gnd[6], O;
void solve() {
  k = read();
  m = k << 1 | 1, n = m * 2 - 1;
  int px = -1, py = -1;
  for (int e(0), _e(1); e <= _e; e++)
    for (int i(1), _i(k << 1 | 1); i <= _i; i++) {
      int &x = w[e][i] = read();
      if (!~x)
        px = e, py = i;
      else if (x > 2 * k + 1)
        x = 4 * k + 2 - x + 2 * k + 1;
    }
  static int p[64];
  int q = 0;
  for (int i(1), _i(m); i <= _i; i++)
    if (~w[0][i]) p[++q] = w[0][i];
  for (int i(m), _i(1); i >= _i; i--)
    if (~w[1][i]) p[++q] = w[1][i];
  bool g = 0;
  for (int i(1), _i(q); i <= _i; i++)
    for (int j(i + 1), _j(q); j <= _j; j++) g ^= p[i] > p[j];
  if (g) return puts("SURGERY FAILED"), void();
  puts("SURGERY COMPLETE");
  vector<string> S;
  string T;
  while (py > k + 1) T += 'l', swap(w[px][py], w[px][py - 1]), --py;
  while (py < k + 1) T += 'r', swap(w[px][py], w[px][py + 1]), ++py;
  if (!px) T += 'd', swap(w[px][py], w[px + 1][py]), ++px;
  q = 0;
  for (int i(1), _i(m); i <= _i; i++)
    if (~w[0][i]) p[++q] = w[0][i];
  for (int i(m), _i(1); i >= _i; i--)
    if (~w[1][i]) p[++q] = w[1][i];
  {
    string s;
    for (int _(1), __(k); _ <= __; _++) s += 'l';
    s += 'u';
    for (int _(1), __(k); _ <= __; _++) s += 'r';
    s += 'd';
    LN = S.size();
    S.emplace_back(s);
  }
  {
    string s;
    s += 'u';
    for (int _(1), __(k); _ <= __; _++) s += 'l';
    s += 'd';
    for (int _(1), __(k); _ <= __; _++) s += 'r';
    LP = S.size();
    S.emplace_back(s);
  }
  {
    string s;
    s += 'u';
    for (int _(1), __(k); _ <= __; _++) s += 'r';
    s += 'd';
    for (int _(1), __(k); _ <= __; _++) s += 'l';
    RN = S.size();
    S.emplace_back(s);
  }
  {
    string s;
    for (int _(1), __(k); _ <= __; _++) s += 'r';
    s += 'u';
    for (int _(1), __(k); _ <= __; _++) s += 'l';
    s += 'd';
    RP = S.size();
    S.emplace_back(s);
  }
  {
    string s;
    for (int _(1), __(k); _ <= __; _++) s += 'l';
    s += 'u';
    for (int _(1), __(k << 1); _ <= __; _++) s += 'r';
    s += 'd';
    for (int _(1), __(k); _ <= __; _++) s += 'l';
    N = S.size();
    S.emplace_back(s);
  }
  {
    string s;
    for (int _(1), __(k); _ <= __; _++) s += 'r';
    s += 'u';
    for (int _(1), __(k << 1); _ <= __; _++) s += 'l';
    s += 'd';
    for (int _(1), __(k); _ <= __; _++) s += 'r';
    P = S.size();
    S.emplace_back(s);
  }
  gnd[0] = P;
  for (int j(1), _j(5); j <= _j; j++) {
    gnd[j] = S.size();
    const char c = gnd[j - 1] + 'A';
    string s;
    s += c;
    s = s + s;
    S.emplace_back(s);
  }
  {
    string s;
    s += LP + 'A';
    s += RN + 'A';
    s += LN + 'A';
    s += RP + 'A';
    O = S.size();
    S.emplace_back(s);
  }
  int pos = k + 1;
  const auto rotate = [&](int p) {
    int q = p;
    if (p > pos) p -= n;
    p = pos - p;
    for (int _(0), __(5); _ <= __; _++)
      if (p >> _ & 1) T += gnd[_] + 'A';
    pos = q;
  };
  for (int i(1), _i(n - 2); i <= _i; i++) {
    int j = -1;
    for (int _(i), __(n); _ <= __; _++)
      if (p[_] == i) {
        j = _;
        break;
      }
    assert(~j);
    while (j - i >= 2) {
      rotate(j - 1);
      T += O + 'A';
      swap(p[j], p[j - 1]), swap(p[j - 1], p[j - 2]), j -= 2;
    }
    if (j - i == 1) {
      rotate(j);
      T += O + 'A';
      swap(p[j + 1], p[j]), swap(p[j], p[j - 1]);
      T += O + 'A';
      swap(p[j + 1], p[j]), swap(p[j], p[j - 1]);
    }
  }
  rotate(k + 1);
  for (int _(1), __(k); _ <= __; _++) T += 'r';
  puts(T.c_str());
  for (int i(0), _i(S.size() - 1); i <= _i; i++)
    printf("%c %s\n", i + 'A', S[i].c_str());
  puts("DONE");
}
int main() {
  for (int T = read(); T--;) solve();
  return 0;
}
