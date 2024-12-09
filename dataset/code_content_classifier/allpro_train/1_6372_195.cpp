#include <bits/stdc++.h>
const int MAXN = 200000;
using namespace std;
int zero[MAXN];
int k;
int main() {
  int n;
  scanf(" %d", &n);
  for (int i = 0; i < n; i++) {
    int num;
    scanf(" %d", &num);
    if (num == 0) zero[k++] = i;
  }
  int first = zero[0];
  for (; first > 0; first--) printf("%d ", first);
  for (int i = 1; i < k; i++) {
    int x = zero[i - 1], y = zero[i];
    int j;
    for (j = x; j <= (x + y) / 2; j++) printf("%d ", j - x);
    j -= (x + 1);
    if ((x + y) % 2 == 0) j--;
    for (; j > 0; j--) printf("%d ", j);
  }
  printf("0 ");
  if (zero[k - 1] != n - 1) {
    for (int i = 1; i < n - zero[k - 1]; i++) printf("%d ", i);
  }
  printf("\n");
  return 0;
}
