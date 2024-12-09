#include <bits/stdc++.h>
using namespace std;
char t[200];
int rev(char x) {
  unsigned long xx = (unsigned long)x;
  bitset<8> bitx(xx);
  bitset<8> bitt;
  for (int i = 0; i < 8; i++) bitt[i] = bitx[7 - i];
  int val = (int)bitt.to_ulong();
  return val;
}
int main() {
  gets(t);
  int len = strlen(t);
  printf("%d\n", (512 - rev(t[0])) % 256);
  for (int i = 1; i < len; i++) {
    printf("%d", (rev(t[i - 1]) - rev(t[i]) + 256 * 1000) % 256);
    if (i < len - 1) printf("\n");
  }
}
