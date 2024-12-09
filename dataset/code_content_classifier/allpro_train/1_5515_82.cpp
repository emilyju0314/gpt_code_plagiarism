#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &a) {
  register int b = 1, c = getchar();
  a = 0;
  for (; !isdigit(c); c = getchar())
    if (c == 45) b *= -1;
  for (; isdigit(c); c = getchar()) a = (a << 3) + (a << 1) + c - 48;
  a *= b;
}
map<long long, int> cnt;
map<pair<int, int>, int> same;
int main() {
  int n;
  long long a, b;
  read(n);
  read(a);
  read(b);
  long long ans = 0;
  for (int i = 0; i < int(n); i++) {
    long long x, vx, vy;
    read(x);
    read(vx);
    read(vy);
    ans += cnt[a * vx - vy] - same[make_pair(vx, vy)];
    cnt[a * vx - vy]++;
    same[make_pair(vx, vy)]++;
  }
  printf("%I64d\n", 2 * ans);
  return 0;
}
