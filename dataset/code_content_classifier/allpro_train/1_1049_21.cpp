#include <bits/stdc++.h>
const int mod = 1e9 + 7;
const int N = 1e6 + 7;
const long double PI = acos(-1.0);
using namespace std;
inline void read(int &first) {
  first = 0;
  char c = getchar();
  int f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    first = first * 10 + c - '0';
    c = getchar();
  }
  first *= f;
}
int n, b, ans = 0, k;
int ck(int a, int b, int k) {
  int tmp = 0;
  if (k == 0)
    b = 1;
  else
    b &= 1;
  a &= 1;
  return (a && b);
}
int main() {
  read(b);
  read(k);
  for (int first, i = 1; i <= k; ++i) {
    read(first);
    ans ^= ck(first, b, k - i);
  }
  if (ans)
    puts("odd");
  else
    puts("even");
}
