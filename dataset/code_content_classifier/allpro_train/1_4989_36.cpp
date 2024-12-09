#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M = 0;
  int may = 0, men = 0;
  scanf("%d", &N);
  int aux;
  for (int i = 0; i < N; i++) {
    scanf("%d", &aux);
    if (aux > 25)
      may++;
    else
      men++;
    if (aux > M) M = aux;
  }
  int r1 = 0, r2 = 0;
  if (may > 0) {
    r2 = may;
    r1 = (M - 25) - may;
  }
  printf("%d", r1 + r2);
}
