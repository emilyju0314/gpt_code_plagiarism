#include <bits/stdc++.h>
using namespace std;
int res[101][101];
void fullyConnect(int n) {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i != j) res[i][j] = 1;
    }
  }
}
int main() {
  int arr[101], k, minNode = 0, next = 0;
  scanf("%d", &k);
  for (int n = 3; n <= 100; ++n) {
    arr[n] = (n * (n - 1) * (n - 2)) / 6;
    if (arr[n] <= k) minNode = n;
  }
  next = minNode, fullyConnect(minNode), k -= arr[minNode];
  while (k != 0) {
    ++next;
    for (int i = 1; i <= minNode; ++i) {
      if (k >= (i - 1))
        k -= (i - 1), res[next][i] = 1, res[i][next] = 1;
      else
        break;
    }
  }
  printf("%d\n", next);
  for (int i = 1; i <= next; ++i) {
    for (int j = 1; j <= next; ++j) printf("%d", res[i][j]);
    printf("\n");
  }
  return 0;
}
