#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch - '0' < 0 || ch - '0' > 9) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch - '0' >= 0 && ch - '0' <= 9) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, m;
char s[505];
struct P {
  int S, e;
} p[505];
int tot;
int f[505][(1 << 16) + 5];
int a[(1 << 16) + 5], b[(1 << 16) + 5];
void FWT_and(int *A, int type) {
  for (int mid = 1; mid < (1 << n); mid <<= 1) {
    for (int j = 0; j < (1 << n); j += (mid << 1)) {
      for (int k = 0; k < mid; k++) {
        int x = A[j + k], y = A[j + k + mid];
        if (type == 1)
          A[j + k] = (x + y) % 1000000007;
        else
          A[j + k] = (x - y + 1000000007) % 1000000007;
      }
    }
  }
}
void FWT_or(int *A, int type) {
  for (int mid = 1; mid < (1 << n); mid <<= 1) {
    for (int j = 0; j < (1 << n); j += (mid << 1)) {
      for (int k = 0; k < mid; k++) {
        int x = A[j + k], y = A[j + k + mid];
        if (type == 1)
          A[j + k + mid] = (x + y) % 1000000007;
        else
          A[j + k + mid] = (y - x + 1000000007) % 1000000007;
      }
    }
  }
}
void merge1(int *A, int *B, int *C) {
  for (int i = 0; i < (1 << n); i++) a[i] = A[i], b[i] = B[i];
  FWT_and(a, 1);
  FWT_and(b, 1);
  for (int i = 0; i < (1 << n); i++) a[i] = 1ll * a[i] * b[i] % 1000000007;
  FWT_and(a, -1);
  for (int i = 0; i < (1 << n); i++) C[i] = (C[i] + a[i]) % 1000000007;
}
void merge2(int *A, int *B, int *C) {
  for (int i = 0; i < (1 << n); i++) a[i] = A[i], b[i] = B[i];
  FWT_or(a, 1);
  FWT_or(b, 1);
  for (int i = 0; i < (1 << n); i++) a[i] = 1ll * a[i] * b[i] % 1000000007;
  FWT_or(a, -1);
  for (int i = 0; i < (1 << n); i++) C[i] = (C[i] + a[i]) % 1000000007;
}
int solve(int l, int r) {
  if (l > r) return 0;
  tot++;
  if (l == r) {
    if (s[l] >= 'A' && s[r] <= 'D') {
      int sta = 0, d = s[l] - 'A';
      for (int i = 0; i < n; i++) sta += (((p[i].S >> d) & 1) << i);
      f[tot][sta] = 1;
    } else if (s[l] >= 'a' && s[r] <= 'd') {
      int sta = 0, d = s[l] - 'a';
      for (int i = 0; i < n; i++) sta += ((((p[i].S >> d) & 1) ^ 1) << i);
      f[tot][sta] = 1;
    } else {
      for (int d = 0; d < 4; d++) {
        int sta = 0;
        for (int i = 0; i < n; i++) sta += (((p[i].S >> d) & 1) << i);
        f[tot][sta]++;
        sta = 0;
        for (int i = 0; i < n; i++) sta += ((((p[i].S >> d) & 1) ^ 1) << i);
        f[tot][sta]++;
      }
    }
    return tot;
  }
  int cnt = 0, mid, id = tot;
  for (int i = l; i <= r; i++) {
    if (s[i] == '(') cnt++;
    if (s[i] == ')') cnt--;
    if (cnt == 0) {
      mid = i + 1;
      break;
    }
  }
  int ls = solve(l + 1, mid - 2);
  int rs = solve(mid + 2, r - 1);
  if (s[mid] != '|') merge1(f[ls], f[rs], f[id]);
  if (s[mid] != '&') merge2(f[ls], f[rs], f[id]);
  return id;
}
int main() {
  scanf("%s", s + 1);
  m = strlen(s + 1);
  n = read();
  int tar = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) p[i].S += (read() << j);
    p[i].e = read();
    tar |= (p[i].e << i);
  }
  solve(1, m);
  printf("%d\n", f[1][tar]);
  return 0;
}
