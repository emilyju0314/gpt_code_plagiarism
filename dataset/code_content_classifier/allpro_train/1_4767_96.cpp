#include <bits/stdc++.h>
int main() {
  int N, i;
  long long s = 0;
  long long mas[110];
  scanf("%d", &N);
  for (i = 1; i <= N; i++) {
    scanf("%I64d", &mas[i]);
  }
  for (i = 1; i <= N; i++) {
    s += mas[i];
    s += (mas[i] - 1) * (i - 1);
  }
  printf("%I64d\n", s);
}
