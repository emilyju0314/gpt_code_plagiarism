#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int base = 10;
char a[1000005];
int s[1000005], l;
int bas[1000005], in[1000005];
int sum[1000005];
int len1, len2, len3, pos1, pos2, pos3;
int hhh(int a, int b) {
  int ans = 1;
  while (b) {
    if (b % 2) ans = 1ll * ans * a % mod;
    a = 1ll * a * a % mod;
    b /= 2;
  }
  return ans;
}
bool kk1(int pos1, int pos2, int pos3) {
  int start1 = pos2 - 1, start2 = pos3 - 1, start3 = l - 1;
  int now = 0;
  while (start3 >= pos3) {
    int s1 = start1 < pos1 ? 0 : s[start1];
    int s2 = start2 < pos2 ? 0 : s[start2];
    int s3 = s[start3];
    if ((s1 + s2 + now) % 10 != s3) return false;
    now = (s1 + s2 + now) / 10;
    start1--;
    start2--;
    start3--;
  }
  if (now == 0) {
    for (int i = pos1; i < pos2; i++) printf("%c", a[i]);
    printf("+");
    for (int i = pos2; i < pos3; i++) printf("%c", a[i]);
    printf("=");
    for (int i = pos3; i < l; i++) printf("%c", a[i]);
    printf("\n");
    return true;
  }
  return false;
}
bool kk(int pos1, int pos2, int pos3) {
  if (pos1 < 0 || pos2 < 0 || (pos2 - pos1 > 1 && !s[pos1]) ||
      (pos3 - pos2 > 1 && !s[pos2]) || (l - pos3 > 1 && !s[pos3]))
    return 0;
  int s1;
  s1 = 1ll * ((sum[pos1] - sum[pos2]) % mod + mod) * in[l - pos2] % mod;
  int s2;
  s2 = 1ll * ((sum[pos2] - sum[pos3]) % mod + mod) * in[l - pos3] % mod;
  int s3 = sum[pos3];
  if ((s1 + s2) % mod == s3 && kk1(pos1, pos2, pos3)) return 1;
  return 0;
}
int main() {
  scanf("%s", a);
  l = strlen(a);
  bas[0] = 1;
  for (int i = 1; i < l; i++) bas[i] = 1ll * bas[i - 1] * base % mod;
  for (int i = 0; i < l; i++) in[i] = hhh(bas[i], mod - 2);
  for (int i = 0; i < l; i++) s[i] = a[i] - '0';
  sum[l] = 0;
  for (int i = l - 1; i >= 0; i--)
    sum[i] = (sum[i + 1] + 1ll * s[i] * bas[l - i - 1]) % mod;
  for (int i = 0; i < l; i++) {
    len3 = l - i;
    pos3 = i;
    len2 = len3;
    pos2 = pos3 - len2;
    len1 = l - len2 - len3;
    pos1 = pos2 - len1;
    if (len1 >= 1 && len2 >= 1 && len3 >= 1 && kk(pos1, pos2, pos3)) return 0;
    len2 = len3 - 1;
    pos2 = pos3 - len2;
    len1 = l - len2 - len3;
    pos1 = pos2 - len1;
    if (len1 >= 1 && len2 >= 1 && len3 >= 1 && kk(pos1, pos2, pos3)) return 0;
    len2 = l - len3 * 2;
    pos2 = pos3 - len2;
    len1 = len3;
    pos1 = pos2 - len1;
    if (len1 >= 1 && len2 >= 1 && len3 >= 1 && kk(pos1, pos2, pos3)) return 0;
    len2 = l - 2 * len3 + 1;
    pos2 = pos3 - len2;
    len1 = len3 - 1;
    pos1 = pos2 - len1;
    if (len1 >= 1 && len2 >= 1 && len3 >= 1 && kk(pos1, pos2, pos3)) return 0;
  }
}
