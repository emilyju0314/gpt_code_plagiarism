#include <bits/stdc++.h>
void Msort(int t[], int L, int R) {
  int temp[R - L + 1];
  int M = (L + R) / 2;
  int k = 0;
  int i = L;
  int j = M + 1;
  while (i <= M && j <= R) {
    if (t[i] <= t[j]) {
      temp[k] = t[i];
      i++;
      k++;
    } else {
      temp[k] = t[j];
      j++;
      k++;
    }
  }
  while (i <= M) {
    temp[k] = t[i];
    i++;
    k++;
  }
  for (int z = 0; z < k; z++) {
    t[z + L] = temp[z];
  }
}
void mergesort(int t[], int L, int R) {
  if (L == R)
    return;
  else {
    int M = (L + R) / 2;
    mergesort(t, M + 1, R);
    mergesort(t, L, M);
    Msort(t, L, R);
  }
}
int main() {
  int t;
  scanf("%d", &t);
  getchar();
  while (t--) {
    int n, x, ctr = 0;
    scanf("%d %d", &n, &x);
    getchar();
    int num[100004];
    for (int i = 0; i < n; i++) {
      scanf("%d", &num[i]);
    }
    getchar();
    mergesort(num, 0, n - 1);
    int j;
    for (int i = n - 1; i >= 0; i--) {
      if (num[i] >= x) {
        ctr++;
      } else {
        int k = 1;
        for (j = i; j >= 0; j--, k++) {
          if (num[j] * k >= x) {
            ctr++;
            break;
          }
        }
        i = j;
      }
    }
    printf("%d\n", ctr);
  }
}
