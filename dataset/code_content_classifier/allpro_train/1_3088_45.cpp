#include <bits/stdc++.h>
int main(void) {
  long long int arr[100005];
  long long int ans[100005];
  long long int key[300][2];
  long long int n, k, i, j, pos;
  scanf("%lli %lli", &n, &k);
  for (i = 0; i <= 255; i++) {
    key[i][0] = -1;
    key[i][1] = 0;
  }
  for (i = 0; i < n; i++) {
    scanf("%lli", &arr[i]);
    if (key[arr[i]][0] == -1) {
      pos = ((arr[i] - k + 1) > 0) ? arr[i] - k + 1 : 0;
      while (key[pos][0] != -1) {
        pos++;
      }
      if (pos > 0 && key[pos - 1][1] != 0 &&
          key[pos - 1][1] + arr[i] - pos + 1 <= k) {
        for (j = pos; j <= arr[i]; j++) {
          key[j][0] = key[pos - 1][0];
          key[j][1] = key[pos - 1][1] + arr[i] - pos + 1;
        }
      } else {
        for (j = pos; j <= arr[i]; j++) {
          key[j][0] = pos;
          key[j][1] = arr[i] - pos + 1;
        }
      }
    }
    ans[i] = key[arr[i]][0];
  }
  for (i = 0; i < n; i++) {
    printf("%lli ", ans[i]);
  }
}
