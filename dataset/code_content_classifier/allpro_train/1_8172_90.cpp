#include <bits/stdc++.h>
int n;
int* a;
int pot4(int n) {
  if (n == 4) return 1;
  int i = 4, cont = 1;
  for (; n > i; i *= 4, cont++)
    ;
  return cont;
}
int main(int argc, char* argv[]) {
  int x = pot4(16);
  scanf("%d", &n);
  a = new int[n];
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  if (n == 0)
    printf("0\n");
  else if (n == 1)
    printf("%d\n", a[0]);
  else {
    std::sort(a, a + n);
    int p4 = pot4(n);
    long long ans = 0LL;
    int i = n - 1;
    int ant = 0;
    for (int p = p4 + 1; p > 0; p--) {
      int tot = (1 << (2 * (p4 + 1 - p))) - ant;
      for (int j = 0; j < tot; j++) {
        ans += (long long)p * (long long)a[i--];
      }
      ant = 1 << 2 * (p4 + 1 - p);
    }
    printf("%I64d\n", ans);
  }
  delete[] a;
  return 0;
}
