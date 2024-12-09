#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, sum, i;
  scanf("%d", &N);
  int rt = (int)sqrt((double)N);
  sum = N;
  for (i = 2; N > 1 && i <= rt; i++) {
    while (N % i == 0) {
      sum += N / i;
      N /= i;
    }
  }
  if (N > 1) sum++;
  printf("%d\n", sum);
  return 0;
}
