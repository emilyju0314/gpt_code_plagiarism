#include <bits/stdc++.h>
char arr[10][10];
void swap(char *x, char *y) {
  char temp;
  temp = *x;
  *x = *y;
  *y = temp;
}
int diff = INT_MAX;
void geto(char a[], int num, int l) {
  int i, j;
  int min = INT_MAX;
  int max = INT_MIN;
  for (i = 0; i < num; i++) {
    int val = 0;
    for (j = 0; j <= l; j++) {
      int no = a[j] - 49;
      val = val * 10 + (arr[i][no] - 48);
    }
    if (val < min) min = val;
    if (val > max) max = val;
  }
  if ((max - min) < diff) {
    diff = (max - min);
  }
}
void permute(char *a, int i, int n, int num) {
  int j;
  if (i == n) {
    geto(a, num, n);
  } else {
    for (j = i; j <= n; j++) {
      swap((a + i), (a + j));
      permute(a, i + 1, n, num);
      swap((a + i), (a + j));
    }
  }
}
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int i;
  for (i = 0; i < n; i++) scanf("%s", arr[i]);
  char a[10];
  diff = INT_MAX;
  for (i = 0; i < k; i++) a[i] = i + 1 + 48;
  a[k] = '\0';
  int l = strlen(a);
  permute(a, 0, l - 1, n);
  printf("%d\n", diff);
  return 0;
}
