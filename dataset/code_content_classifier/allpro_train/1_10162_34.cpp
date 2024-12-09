#include <bits/stdc++.h>
inline int get_last(long long x) { return x % 10; }
inline int get_first(long long x) {
  while (x >= 10) x /= 10;
  return x;
}
inline int get_size(long long x) {
  int c = 0;
  while (x > 0) {
    x /= 10;
    c++;
  }
  return c;
}
inline long long pow10to(int x) {
  long long r = 1;
  while (x > 0) {
    r *= 10;
    x--;
  }
  return r;
}
long long get_middle(long long x) {
  return (x / 10) - get_first(x) * pow10to(get_size(x) - 2);
}
long long get_n(long long x) {
  if (x < 10) return x;
  long long c = 9;
  int f = get_first(x);
  int l = get_last(x);
  int size = get_size(x) - 2;
  for (int i = 0; i <= size; ++i) {
    for (int d = 1; d < 10; ++d) {
      if (i < size || d < f && i == size) {
        c += pow10to(i);
      } else if (d == f && i == size) {
        c += get_middle(x);
        if (l >= d) c++;
      }
    }
  }
  return c;
}
int main() {
  long long l, r, c = 0;
  std::cin >> l >> r;
  std::cout << get_n(r) - get_n(l - 1) << std::endl;
}
