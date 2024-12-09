#include <bits/stdc++.h>
int n, X;
int c[100];
int main() {
  std::ifstream ifile("input.txt");
  if (ifile) freopen("input.txt", "rt", stdin);
  if (ifile) freopen("output.txt", "wt", stdout);
  scanf("%d%d", &n, &X);
  for (int i = 0; i < n; i++) {
    scanf("%d", &c[i]);
    c[i] *= n - i;
  }
  std::sort(c, c + n);
  int i;
  for (i = 0; i < n; i++) {
    if (X >= c[i])
      X -= c[i];
    else
      break;
  }
  printf("%d\n", i);
  return 0;
}
