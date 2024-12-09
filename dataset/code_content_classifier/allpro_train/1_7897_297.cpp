#include <bits/stdc++.h>
using namespace std;
const int maxn = 125;
int a[8];
char s[maxn];
int pre = 0;
int reverse_x(int x) {
  int m = 0;
  memset(a, 0, sizeof(a));
  while (x) {
    a[m++] = (x & 1);
    x >>= 1;
  }
  x = 0;
  for (int i = 0; i < 8; ++i) x = (x << 1) + a[i];
  return x;
}
void calc(int x) {
  x = reverse_x(x);
  pre = ((pre - x) + 256) % 256;
  printf("%d\n", pre);
  pre = x;
}
int main() {
  ios::sync_with_stdio(false);
  gets(s);
  int len = strlen(s);
  for (int i = 0; i < len; ++i) calc(s[i]);
  return 0;
}
