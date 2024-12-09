#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
map<int, bool> mmap;
int a[maxn];
int inv(int a, int p) {
  return a == 1 ? 1 : (long long)inv(p % a, p) * (p - p / a) % p;
}
int main() {
  int p, n, find = 0;
  scanf("%d%d", &p, &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    mmap[a[i]] = true;
  }
  if (2 * n > p) {
    n = 0;
    find = 1;
    for (int i = 0; i < p; i++) {
      if (!mmap[i]) a[++n] = i;
      mmap[i] = !mmap[i];
    }
  }
  sort(a + 1, a + 1 + n);
  if (n <= 1 || n == p) {
    printf("%d 1\n", (a[1] + find) % p);
    return 0;
  }
  int x = a[2] - a[1], k = n;
  for (int i = 1; i <= n; i++) k -= mmap[(a[i] + x) % p];
  int d = (long long)x * inv(k, p) % p, first = a[1];
  while (mmap[(first - d + p) % p]) first = (first - d + p) % p;
  for (int i = 0; i < n; i++)
    if (!mmap[(first + (long long)i * d) % p]) find = -1;
  if (find == -1) {
    printf("-1\n");
    return 0;
  } else if (find == 1)
    first = (first + (long long)n * d) % p;
  printf("%d %d\n", first, d);
  return 0;
}
