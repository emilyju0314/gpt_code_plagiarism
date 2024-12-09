#include <bits/stdc++.h>
using namespace std;
int N, K;
void rip() {
  puts("-1");
  exit(0);
}
int main() {
  scanf("%d %d", &N, &K);
  if (K == 1) {
    rip();
  } else if (K == 2) {
    if (N <= 4)
      rip();
    else {
      printf("%d\n", N - 1);
      for (int i = (1); i < (N); i++) printf("%d %d\n", i, i + 1);
    }
  } else if (K == 3) {
    if (N <= 3)
      rip();
    else {
      printf("%d\n", N - 1);
      printf("1 2\n2 3\n");
      for (int i = (4); i < (N + 1); i++) printf("%d %d\n", 3, i);
    }
  } else
    rip();
  return 0;
}
