#include <bits/stdc++.h>
long long arr[200009], res[200009];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n / 2; i++) scanf("%lld", &arr[i]);
  res[1] = 0, res[n] = arr[1];
  long long last = arr[1];
  for (int i = 2; i <= (n / 2); i++) {
    if (last > arr[i]) {
      res[i] = res[i - 1];
      res[n - i + 1] = (arr[i] - res[i]);
    } else {
      res[i] = res[i - 1] + (arr[i] - last);
      res[n - i + 1] = (arr[i] - res[i]);
    }
    last = arr[i];
  }
  for (int i = 1; i <= n; i++) printf("%lld ", res[i]);
  return 0;
}
