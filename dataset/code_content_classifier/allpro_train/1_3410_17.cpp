#include <bits/stdc++.h>
int n;
int a[5009], b[5009];
void ReadData() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
}
int a1, a2;
int d[5009][5009];
int tmp[5009];
int merge(int *arr, int l1, int r1, int l2, int r2) {
  int result = 0;
  int id1 = l1, id2 = l2;
  int len = (r1 - l1) + 1 + (r2 - l2) + 1;
  int id = 0;
  while (id != len) {
    if (id1 > r1) {
      tmp[id] = arr[id2];
      id++;
      id2++;
      continue;
    } else if (id2 > r2) {
      tmp[id] = arr[id1];
      id++;
      id1++;
      continue;
    }
    if (arr[id1] <= arr[id2]) {
      tmp[id] = arr[id1];
      id++;
      id1++;
    } else if (arr[id1] > arr[id2]) {
      tmp[id] = arr[id2];
      result += r1 + 1 - id1;
      id++;
      id2++;
    }
  }
  int len1 = (r1 - l1) + 1;
  for (int i = 0; i < len1; i++) {
    arr[i + l1] = tmp[i];
  }
  int len2 = (r2 - l2) + 1;
  for (int i = 0; i < len2; i++) {
    arr[i + l2] = tmp[i + len1];
  }
  return result;
}
int mergeSort(int *arr, int l, int r) {
  if (l >= r) {
    return 0;
  }
  int nr = l + (r - l) / 2;
  int nl = nr + 1;
  int result = mergeSort(arr, l, nr) + mergeSort(arr, nl, r);
  result += merge(arr, l, nr, nl, r);
  return result;
}
void Solve() {
  memset(d, 0, sizeof(d));
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++) {
      d[i][j] = d[i - 1][j] + (a[i] < j ? 1 : 0);
    }
  }
  int inv = mergeSort(a, 0, n - 1);
  a1 = inv;
  a2 = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int t = j - i - 1;
      int p = d[j - 1][b[i]] - d[i][b[i]];
      int k = t - (d[j - 1][b[j]] - d[i][b[j]]);
      int current = inv + 2 * (-p - k + t);
      if (b[i] < b[j]) {
        current++;
      } else {
        current--;
      }
      if (current == a1) {
        a2++;
      } else if (current < a1) {
        a1 = current;
        a2 = 1;
      }
    }
  }
}
void WriteData() { printf("%d %d\n", a1, a2); }
int main() {
  int QWE = 1;
  for (int T = 0; T < QWE; T++) {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
