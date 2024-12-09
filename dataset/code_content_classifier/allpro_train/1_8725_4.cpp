#include <cstdio>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (n); i++)

const int cm = 1 << 17;
char cn[cm], *ci = cn + cm, ct;
inline char get_char() {
  if (ci - cn == cm) {
    fread(cn, 1, cm, stdin);
    ci = cn;
  }
  return *ci++;
}
inline int get_int() {
  int A = 0;
  if (ci - cn + 16 > cm)
    while ((ct = get_char()) >= '0') A = A * 10 + ct - '0';
  else
    while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';
  return A;
}

int cnt[1001][1001];

int main() {
  int N = get_int(), K = get_int();
  rep(i, N) {
    int x = get_int(), y = get_int(), b;
    char c = get_char();
    get_char();
    if(c=='W')y += K;
    b = x / K % 2 == y / K % 2 ? 1 : -1;
    if(b > 0) cnt[0][0]++;
    int nx = x % K + 1, ny = y % K + 1;
    cnt[nx][0] -= b;
    cnt[0][ny] -= b;
    cnt[nx][ny] += b * 2;
  }
  rep(i, K + 1)rep(j, K)cnt[i][j + 1] += cnt[i][j];
  rep(j, K + 1)rep(i, K)cnt[i + 1][j] += cnt[i][j];
  int ans = 0;
  rep(i, K)rep(j, K)ans = std::max(ans, std::max(cnt[i][j], N - cnt[i][j]));
  printf("%d", ans);
}
