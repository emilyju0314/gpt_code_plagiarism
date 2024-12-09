#include <bits/stdc++.h>
using namespace std;
int main() {
  FILE* fin = stdin;
  int n, i;
  fscanf(fin, "%d", &n);
  printf("%d\n", n + n / 2);
  for (i = 2; i <= n; i += 2) printf("%d ", i);
  for (i = 1; i <= n; i += 2) printf("%d ", i);
  for (i = 2; i <= n; i += 2) printf("%d ", i);
  return 0;
}
