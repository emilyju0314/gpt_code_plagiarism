#include <bits/stdc++.h>
using namespace std;
const int N = 1500007;
int T, n, m;
int qz[N];
int ans[155][15];
inline int read() {
  int x = 0, c = getchar(), f = 0;
  for (; c > '9' || c < '0'; f = c == '-', c = getchar())
    ;
  for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + c - '0';
  return f ? -x : x;
}
void init() {
  int t, num;
  for (int i = 1; i <= N; i++) {
    t = 0;
    num = i;
    while (num) {
      t += num % 10;
      num /= 10;
    }
    qz[i] = qz[i - 1] + t;
    for (int j = 0; j <= 9; j++) {
      if (i - j - 1 < -1 || qz[i] - qz[i - j - 1] > 150) break;
      if (ans[qz[i] - qz[i - j - 1]][j] == -1) {
        ans[qz[i] - qz[i - j - 1]][j] = i - j;
      }
    }
  }
}
int main() {
  for (int i = 0; i <= 153; i++) {
    for (int j = 0; j <= 13; j++) {
      ans[i][j] = -1;
    }
  }
  init();
  T = read();
  while (T--) {
    n = read();
    m = read();
    if (m == 0) {
      if (n % 9) printf("%d", n % 9);
      for (int i = 1; i <= n / 9; i++) printf("9");
      printf("\n");
      continue;
    }
    if (m == 1 && n > 70) {
      if (n % 2 == 0) {
        n -= 26;
        n /= 2;
        if (n % 9) printf("%d", n % 9);
        for (int i = 1; i <= n / 9; i++) printf("9");
        printf("89\n");
        continue;
      } else {
        n -= 17;
        n /= 2;
        if (n % 9) printf("%d", n % 9);
        for (int i = 1; i <= n / 9; i++) printf("9");
        printf("8\n");
        continue;
      }
    }
    printf("%d\n", ans[n][m]);
  }
  return 0;
}
