#include <bits/stdc++.h>
int result[1010];
int arr[1010];
int main(void) {
  int n, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", arr + i);
  std::sort(arr, arr + n);
  if (n % 2 == 1) {
    for (i = 0; i <= n / 2; i++) result[2 * i + 1] = arr[i];
    for (i = n / 2 + 1; i < n; i++) result[(i - n / 2) * 2] = arr[i];
  } else {
    for (i = 0; i < n / 2; i++) result[2 * i + 1] = arr[i];
    for (i = n / 2; i < n; i++) result[(i - n / 2 + 1) * 2] = arr[i];
  }
  for (i = 1; i <= n; i++) printf("%d ", result[i]);
  return 0;
}
