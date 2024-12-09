#include <bits/stdc++.h>
const int size = 1001;
int next[size], amount[size];
bool tank[size];
int n, p, cnt;
int main() {
  scanf("%d%d", &n, &p);
  memset(amount, 0, (n + 1) * sizeof(int));
  memset(next, 0, (n + 1) * sizeof(int));
  for (int i = 1; i <= n; i++) tank[i] = 1;
  for (int i = 0; i < p; i++) {
    int a, b, d;
    scanf("%d%d%d", &a, &b, &d);
    tank[b] = 0;
    next[a] = b;
    amount[a] = d;
  }
  for (int i = 1; i <= n; i++)
    if (tank[i] && next[i]) cnt++;
  printf("%d\n", cnt);
  if (cnt) {
    for (int i = 1; i <= n; i++)
      if (tank[i] && next[i]) {
        int tap = next[i];
        int min = amount[i];
        while (next[tap]) {
          min = min < amount[tap] ? min : amount[tap];
          tap = next[tap];
        }
        printf("%d %d %d\n", i, tap, min);
      }
  }
  return 0;
}
