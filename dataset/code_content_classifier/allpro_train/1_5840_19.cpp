#include <bits/stdc++.h>
long long num[4], max = 0, n = 0;
long long is(char x) {
  if (x == 'A') return 0;
  if (x == 'C') return 1;
  if (x == 'G')
    return 2;
  else
    return 3;
}
long long ks(long long a, long long b) {
  long long r = 1, base = a;
  while (b != 0) {
    if (b & 1) r = r * base % 1000000007;
    base = base * base % 1000000007;
    b >>= 1;
  }
  return r;
}
int main() {
  long long len, i;
  char ch;
  scanf("%I64d\n", &len);
  for (i = 1; i <= len; i++) {
    scanf("%c", &ch);
    num[is(ch)]++;
  }
  for (i = 0; i <= 3; i++)
    if (num[i] > max) max = num[i];
  for (i = 0; i <= 3; i++)
    if (num[i] == max) n++;
  printf("%I64d", ks(n, len));
  getchar();
  getchar();
  return 0;
}
