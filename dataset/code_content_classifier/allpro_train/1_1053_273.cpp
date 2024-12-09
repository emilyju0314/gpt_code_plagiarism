#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long a = 0, b = getchar(), c = 1;
  while (!isdigit(b)) c = b == '-' ? -1 : 1, b = getchar();
  while (isdigit(b)) a = a * 10 + b - '0', b = getchar();
  return a * c;
}
void print(long long x) {
  if (x < 0) putchar('-'), x = -x;
  int y = x % 10 + '0';
  if (x >= 10) print(x / 10);
  putchar(y);
}
int n, x, y, a[100005];
int main() {
  n = read(), x = read(), y = read();
  for (int i = 0; i < n; i++) a[i] = read();
  for (int i = 0; i < n; i++) {
    bool z = true;
    for (int j = max(0, i - x); j < i; j++)
      if (a[j] <= a[i]) z = false;
    for (int j = min(n - 1, i + y); j > i; j--)
      if (a[j] <= a[i]) z = false;
    if (z) return print(i + 1), 0;
  }
  return 0;
}
