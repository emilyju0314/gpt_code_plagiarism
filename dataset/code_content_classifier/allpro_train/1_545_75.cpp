#include <bits/stdc++.h>
using namespace std;
void print(int n, int a[]) {
  for (int i = 0; i < n; i++) printf("%d%c", a[i], ((i + 1) == n) ? '\n' : ' ');
}
void init(int n, int a[]) {
  for (int k = 0; k < n; k++) a[k] = k + 1;
}
int *f(int n, int *a, int k) {
  int *b = a + 1;
  if (n % k) {
    b[n - 1] = b[n - (n % k) - 1];
  }
  for (int s = n / k; s >= 1; s--) {
    int j = s * k - 1;
    b[j] = b[j - k];
  }
  return b;
}
int *pretty(int n, int *a) {
  for (int k = 2; k <= n; k++) a = f(n, a, k);
  return a;
}
int main() {
  int buf[1000000 * 2 + 1];
  int n;
  cin >> n;
  int *a = buf;
  init(n, a);
  a = pretty(n, a);
  print(n, a);
}
