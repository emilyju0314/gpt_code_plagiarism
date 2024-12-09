#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return (a == 0) ? b : (b == 0) ? a : gcd(b, a % b); }
int str_div(char *s, int n) {
  int y = 0, ln = strlen(s);
  for (int i = 0; i < ln; ++i) y = (y * 10 + (s[i] - 48)) % n;
  return y;
}
long long get() {
  long long y, s = 1, i = 10;
  y = 0;
  char c = getchar();
  while (!(c >= 48 && c <= 57)) {
    if (c == '-') s = -1;
    c = getchar();
  }
  while ((c >= 48 && c <= 57))
    y = (y << 1) + (y << 3) + (c & 15), c = getchar();
  if (c != '.') return y * s;
  c = getchar();
  while ((c >= 48 && c <= 57))
    y = y + (c & 15) / i, i = (i << 1) + (i << 3), c = getchar();
  return y * s;
}
void put(int x) {
  if (!x) {
    putchar('0');
    return;
  }
  char ch[21];
  int ln = 0;
  while (x) {
    ch[ln++] = x % 10;
    x /= 10;
  }
  ln--;
  while (ln >= 0) {
    putchar(ch[ln--] + 48);
  }
}
int dx[] = {1, -1, 0, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 0, -1, 1, -1, 1};
int arr[25000][15];
int chat[15], per[25000];
int main() {
  int n = get(), m = get(), k = get();
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) arr[i][j] = get();
  for (int i = 0; i < k; ++i) {
    int x = get(), y = get();
    per[x - 1]--, chat[y - 1]++;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (arr[i][j]) per[i] += chat[j];
    }
  }
  for (int i = 0; i < n; ++i) put(per[i]), putchar(' ');
}
