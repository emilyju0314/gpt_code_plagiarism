#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
long long n, tree[4040404], s = 1, a;
pair<long long, long long> d[1010101];
void update(int x, int y) {
  x += s - 1;
  tree[x] = y;
  while (x /= 2) tree[x] = tree[x * 2] + tree[x * 2 + 1];
}
long long sum(int x, int y) {
  x += s - 1;
  y += s - 1;
  long long ans = 0;
  while (x <= y) {
    if (x % 2 == 1) ans += tree[x++];
    if (y % 2 == 0) ans += tree[y--];
    if (x > y) break;
    x /= 2;
    y /= 2;
  }
  return ans;
}
int main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &d[i].first);
    d[i].second = i;
  }
  while (s < n) s *= 2;
  sort(d + 1, d + n + 1);
  for (long long i = 1; i <= n; i++) {
    update(d[i].second, 1);
    a += sum(d[i].second + 1, n);
  }
  if (n % 2 == 1) {
    if (a % 2 == 1)
      puts("Petr");
    else
      puts("Um_nik");
  } else {
    if (a % 2 == 1)
      puts("Um_nik");
    else
      puts("Petr");
  }
}
