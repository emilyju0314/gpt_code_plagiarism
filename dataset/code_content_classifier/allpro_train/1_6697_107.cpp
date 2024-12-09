#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
template <class T>
inline void gn(T &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
template <class T>
inline void print(T first) {
  if (first < 0) {
    putchar('-');
    return print(-first);
  }
  if (first < 10) {
    putchar('0' + first);
    return;
  }
  print(first / 10);
  putchar(first % 10 + '0');
}
template <class T, class T1>
inline void gn(T &first, T1 &second) {
  gn(first);
  gn(second);
}
template <class T, class T1, class T2>
inline void gn(T &first, T1 &second, T2 &z) {
  gn(first);
  gn(second);
  gn(z);
}
template <class T>
inline void println(T first) {
  print(first);
  putchar('\n');
}
template <class T>
inline void printsp(T first) {
  print(first);
  putchar(' ');
}
template <class T1, class T2>
inline void print(T1 x1, T2 x2) {
  printsp(x1), println(x2);
}
template <class T1, class T2, class T3>
inline void print(T1 x1, T2 x2, T3 x3) {
  printsp(x1), printsp(x2), println(x3);
}
template <class T1, class T2, class T3, class T4>
inline void print(T1 x1, T2 x2, T3 x3, T4 x4) {
  printsp(x1), printsp(x2), printsp(x3), println(x4);
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
int g[100111];
int vst[111];
int runs;
struct seg {
  int st, ed, g;
  seg(int st = 0, int ed = 0, int g = 0) : st(st), ed(ed), g(g){};
} s[100111];
int nn;
long long cnt[111];
long long dp[1011][4];
long long calc(int a, int b) { return 1ll * (a + b) * (b - a + 1) / 2; }
int main() {
  s[nn++] = seg(0, 2, 0);
  s[nn++] = seg(3, 3, 1);
  int a = 0, b = 0;
  int val;
  int n, p;
  cin >> n >> p;
  if (p <= 3) return puts("0");
  cnt[0] += 0ll + p - 1 + p - 2;
  cnt[1] += p - 3;
  while (s[nn - 1].ed < p - 1) {
    int tmp = s[nn - 1].ed + 1;
    int d = tmp / 3;
    int e = tmp - tmp / 3;
    while (a < nn and d > s[a].ed) a++;
    while (b < nn and e > s[b].ed) b++;
    int aed = s[a].ed;
    int bed = s[b].ed;
    int now =
        min(aed * 3 + 2, (bed & 1) ? bed / 2 * 3 + 1
                                   : max((bed / 2 - 1) * 3 + 2, bed / 2 * 3));
    smin(now, p - 1);
    int val;
    runs++;
    vst[s[a].g] = runs;
    vst[s[b].g] = runs;
    for (int j = 0; j < 3; j++)
      if (vst[j] != runs) {
        val = j;
        break;
      }
    if (val == s[nn - 1].g) {
      s[nn - 1].ed = now;
    } else {
      s[nn++] = seg(tmp, now, val);
    }
    cnt[val] += calc(p - now, p - tmp);
  }
  memset(dp, 0, sizeof dp);
  dp[0][0] = 1;
  for (int i = 0; i <= 3; i++) cnt[i] %= 1000000007;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= 3; j++) {
      for (int k = 0; k <= 3; k++) {
        dp[i + 1][j ^ k] += dp[i][j] * cnt[k] % 1000000007;
        dp[i + 1][j ^ k] %= 1000000007;
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= 3; i++) ans += dp[n][i];
  ans %= 1000000007;
  cout << ans << endl;
  return 0;
}
