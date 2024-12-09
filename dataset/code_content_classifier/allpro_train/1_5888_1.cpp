#include <bits/stdc++.h>
using namespace std;
bool ok[100100];
int gcd(int a, int b) {
  while (b) a %= b, swap(a, b);
  return a;
}
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int g = k;
  for (int i = 0; i < n; i++) {
    int first;
    scanf("%d", &first);
    g = gcd(g, first % k);
  }
  printf("%d\n", 1 + (k - 1) / g);
  for (int i = 0; i < k; i++)
    if (i % g == 0) printf("%d ", i);
  printf("\n");
  return 0;
}
