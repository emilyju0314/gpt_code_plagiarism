#include <bits/stdc++.h>
using namespace std;
int n;
int a[55];
int main() {
  int ans = 52;
  int k = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    ans = min(ans, a[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] > ans) k++;
  }
  if (k >= n / 2)
    printf("Alice\n");
  else
    printf("Bob\n");
}
