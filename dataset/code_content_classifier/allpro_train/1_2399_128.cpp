#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int a[N], b[N];
int main() {
  int sum = 0;
  int n;
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    scanf("%d", &b[i]);
  }
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    if (a[i] != a[b[i]]) sum++;
  }
  printf("%d\n", sum);
  return 0;
}
