#include <bits/stdc++.h>
#pragma comment(linker, "/stack:64000000")
const double pi = 3.1415926535897932384626433832795;
const int N = 5001;
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int bin_pow(int a, int n) {
  int res = 1;
  while (n) {
    if (n & 1) res *= a;
    a *= a;
    n = n >> 1;
  }
  return res;
}
void Read(int *a, int n) {
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
}
struct nam1 {
  string nam;
};
void iSort(nam1 *s, int n) {
  int min;
  for (int i = 0; i < n; ++i) {
    min = i;
    for (int j = i + 1; j < n; ++j)
      if (s[j].nam < s[min].nam) min = j;
    swap(s[i], s[min]);
  }
}
const int n = 2 * 10000000;
const int s = 6001;
int a[n];
int b[s];
int main() {
  memset(a, 0, sizeof a);
  memset(b, 0, sizeof b);
  int help;
  int m;
  cin >> m;
  help = m;
  if (m == 1) {
    cout << "-1";
    return 0;
  }
  m = (m + 1) * m / 2;
  int h;
  a[2] = 1;
  a[3] = 1;
  int x2 = 0;
  for (int i = 1; i * i <= m; ++i) {
    x2 += 2 * i - 1;
    int y2 = 0;
    for (int j = 1; j * j <= m; ++j) {
      y2 += 2 * j - 1;
      h = 4 * x2 + y2;
      if ((h <= m) && (h % 12 == 1 || h % 12 == 5)) a[h] = !a[h];
      h -= x2;
      if ((h <= m) && (h % 12 == 7)) a[h] = !a[h];
      h -= 2 * y2;
      if ((i > j) && (h <= m) && (h % 12 == 11)) a[h] = !a[h];
    }
  }
  for (int i = 5; i * i <= m; i++) {
    if (a[i]) {
      h = i * i;
      for (int j = h; j <= m; j += h) a[j] = 0;
    }
  }
  if (a[m]) {
    for (int i = 0; i < help; ++i) cout << "1 ";
    return 0;
  }
  int x = -1, y = -1, z = -1;
  for (int i = 2; i < m - 2; ++i)
    if (a[i])
      if (a[m - i]) {
        x = i;
        y = m - i;
        break;
      }
  if (x == -1) {
    int flag = 1;
    for (int i = m - 2; i >= 2; --i) {
      if (a[i])
        for (int j = 2; j < m - i; ++j)
          if (a[j])
            if (a[m - j - i]) {
              x = i;
              y = j;
              if (x > y) swap(x, y);
              z = m - j - i;
              if (((x == 2) && (y == 2)) || ((x == 2) && (z == 2)) ||
                  ((y == 2) && (z == 2))) {
                continue;
              } else {
                flag = 0;
                break;
              }
            }
      if (!flag) break;
    }
  }
  int k;
  int i;
  m = help;
  int sum = 0;
  k = 1;
  i = m - 1;
  while (sum != x) {
    if (sum + i + 1 <= x) {
      sum += i + 1;
      b[i] = k;
    }
    --i;
  }
  sum = 0;
  ++k;
  i = m - 1;
  while (sum != y) {
    if (!b[i])
      if (sum + i + 1 <= y) {
        sum += i + 1;
        b[i] = k;
      }
    --i;
  }
  if (z != -1) {
    sum = 0;
    ++k;
    i = m - 1;
    while (sum != z) {
      if (!b[i])
        if (sum + i + 1 <= z) {
          sum += i + 1;
          b[i] = k;
        }
      --i;
    }
  }
  for (i = 0; i < m; ++i) cout << b[i] << " ";
  return 0;
}
