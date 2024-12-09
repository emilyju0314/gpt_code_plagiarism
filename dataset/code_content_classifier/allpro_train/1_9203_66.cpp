#include <bits/stdc++.h>
using namespace std;
int N, M, T;
int tb[1005];
int main() {
  int i, j, k, a, b, c;
  scanf("%d%d", &N, &M);
  for (i = 0; i < N; i++) {
    scanf("%d%d", &a, &b);
    if (b < a) {
      c = b;
      b = a;
      a = c;
    }
    for (j = a; j <= b; j++) tb[j]++;
  }
  k = 999999;
  for (i = 0; i < 1000; i++) {
    if (tb[i] == N) {
      j = abs(i - M);
      if (j < k) k = j;
    }
  }
  if (k == 999999)
    printf("-1\n");
  else
    printf("%d\n", k);
  scanf(" ");
}
