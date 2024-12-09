#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 17;
const int MX = (int)1e6 + 17;
const int MOD = (int)1e9 + 7;
const long long oo = LLONG_MAX;
const int INF = INT_MAX;
const long double Pi = 3.14159265358979323846264338327950288419716939937510;
const int di[4] = {-1, 0, 1, 0};
const int dj[4] = {0, 1, 0, -1};
inline long long IN() {
  long long x = 0, ch = getchar(), f = 1;
  while (!isdigit(ch) && (ch != '-') && (ch != EOF)) ch = getchar();
  if (ch == '-') {
    f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void OUT(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10)
    OUT(x / 10), putchar(x % 10 + '0');
  else
    putchar(x + '0');
}
void IOI2017() {}
int a, b;
int get(int x) {
  stringstream t;
  t << x;
  string s;
  t >> s;
  int res = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] == '4' || s[i] == '7') {
      res *= 10;
      res += s[i] - '0';
    }
  }
  return res;
}
int main() {
  cin >> a >> b;
  a++;
  while (get(a) != b) {
    a++;
  }
  cout << a;
  return 0;
}
