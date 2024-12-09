#include <bits/stdc++.h>
char s[111], c[111];
int N, answer;
void bkt(int poz) {
  if (poz >= N) {
    if (c[0] == 'B' && c[N - 1] == 'A' && (s[0] != 'A' || s[N - 1] != 'B'))
      return;
    if (c[0] == 'A' && c[N - 1] == 'A' && s[N - 1] != 'A') return;
    if (c[0] == 'B' && c[N - 1] == 'B' && s[0] != 'B') return;
    answer++;
  } else {
    for (c[poz] = 'A'; c[poz] <= 'B'; c[poz]++) {
      if (c[poz] == 'B' && c[poz - 1] == 'A' &&
          (s[poz - 1] != 'B' || s[poz] != 'A'))
        continue;
      if (c[poz] == 'A' && c[poz - 1] == 'A' && s[poz - 1] != 'A') continue;
      if (c[poz] == 'B' && c[poz - 1] == 'B' && s[poz] != 'B') continue;
      bkt(poz + 1);
    }
  }
}
long long cnt[111][2], ans;
void dp() {
  int i, j, p, k;
  ans = 0;
  for (k = 0; k <= 1; k++) {
    cnt[0][k] = 1;
    cnt[0][1 - k] = 0;
    for (i = 1; i < N; i++) {
      for (j = 0; j <= 1; j++) {
        cnt[i][j] = 0;
        for (p = 0; p <= 1; p++) {
          if (j == 1 && p == 0 && (s[i - 1] != 'B' || s[i] != 'A')) continue;
          if (j == 0 && p == 0 && s[i - 1] != 'A') continue;
          if (j == 1 && p == 1 && s[i] != 'B') continue;
          cnt[i][j] += cnt[i - 1][p];
        }
      }
    }
    for (p = 0; p <= 1; p++) {
      if (k == 1 && p == 0 && (s[N - 1] != 'B' || s[0] != 'A')) continue;
      if (k == 0 && p == 0 && s[N - 1] != 'A') continue;
      if (k == 1 && p == 1 && s[0] != 'B') continue;
      ans += cnt[N - 1][p];
    }
  }
  printf("%I64d\n", ans);
}
int main() {
  scanf("%s", s);
  N = strlen(s);
  dp();
  return 0;
}
