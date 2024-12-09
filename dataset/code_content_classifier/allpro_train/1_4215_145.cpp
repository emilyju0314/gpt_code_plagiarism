#include <bits/stdc++.h>
using namespace std;
long long z = 1, tmp, half, k;
bool isOdd, isZero;
char s[55];
long long getNum(int w) {
  half = 1LL << (w >> 1), tmp = ((z - 1) << 1) * (1LL << w);
  if (w == 0) return tmp + 2 - isZero;
  if (isOdd)
    return tmp + ((half << 1) + (((1LL << w) - (half << 1)) >> 1) - isZero) +
           (half + (((1LL << w) - (half << 1)) >> 1));
  return tmp + ((half << 1) + ((1LL << w) - half) - isZero);
}
void update(int &i) {
  if (k > tmp) {
    isZero = false;
    k -= tmp;
    s[i] = '1';
  } else
    s[i] = '0';
}
int main() {
  int n;
  scanf("%d%I64d", &n, &k);
  if ((n == 2 && k > 1) || (n == 3 && k > 2)) {
    puts("-1");
    return 0;
  }
  if (n == 2) {
    puts("01");
    return 0;
  }
  if (n == 3) {
    if (k == 1)
      puts("001");
    else
      puts("010");
    return 0;
  }
  isOdd = n & 1, isZero = true;
  if (k > getNum(n - 2)) {
    puts("-1");
    return 0;
  }
  s[0] = '0';
  int mid = n >> 1, i = 1, len = n - 2;
  for (; i < mid; ++i) {
    z <<= 1;
    tmp = getNum(len - 2);
    len -= 2;
    if (k > tmp) z >>= 1, z += (z - 1);
    update(i);
  }
  int j = i - 1;
  if (isOdd) {
    tmp = (z << 1) - isZero;
    update(i);
    ++i;
  }
  int com = 0, big = 0;
  if (isOdd) big = (s[mid] == '0') ? 1 : 2;
  for (int m = n - 1; i < m; ++i, --j) {
    if (s[j] == '0') {
      z >>= 1;
      tmp = (z << 1) - isZero - (com == 2);
      update(i);
      if (s[i] > s[j])
        com = 1;
      else
        big = 1;
    } else {
      z = (z + 1) >> 1;
      tmp = (z << 1) - 1 - (big == 2);
      update(i);
      if (s[i] < s[j])
        com = 2;
      else
        big = 2;
    }
  }
  if (k > 1)
    s[n - 1] = '1';
  else
    s[n - 1] = ((com <= 1 && !isZero) ? '0' : '1');
  s[n] = 0;
  puts(s);
  return 0;
}
