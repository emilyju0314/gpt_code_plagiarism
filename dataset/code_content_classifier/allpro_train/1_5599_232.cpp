#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3fll;
const long long M = 1e9 + 7;
const long long maxn = 1e5 + 7;
const double eps = 0.00000001;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
template <typename T>
inline T abs(T a) {
  return a > 0 ? a : -a;
}
template <typename T>
inline T powMM(T a, T b) {
  T ret = 1;
  for (; b; b >>= 1ll, a = a * a % M)
    if (b & 1) ret = 1ll * ret * a % M;
  return ret;
}
char a[maxn];
int n, cnt;
char pre;
bool mark;
int main() {
  int n, i;
  scanf("%s", a);
  int len = strlen(a);
  for (i = 0; i < len; i++) {
    if (a[i] != 'a' && a[i] != 'u' && a[i] != 'e' && a[i] != 'i' &&
        a[i] != 'o') {
      if (cnt && a[i] != a[i - 1]) mark = 1;
      cnt++;
    } else
      cnt = 0, mark = 0;
    if (cnt >= 3 && mark) {
      cnt = 1;
      mark = 0;
      putchar(' ');
    }
    putchar(a[i]);
  }
}
