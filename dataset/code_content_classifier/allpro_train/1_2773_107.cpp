#include <bits/stdc++.h>
using namespace std;
const int P = 131;
const int M = 1e9 + 7;
const int maxs = 1e5 + 5;
const int maxt = 1e6 + 5;
int lens, lent;
char s[maxs], t[maxt];
int tot0, tot1;
long long pre[maxt], Ppow[maxt];
void prework(int len) {
  pre[0] = 0;
  Ppow[0] = 1;
  for (int i = 1; i <= len; i++) {
    pre[i] = pre[i - 1] * P + (t[i] - 'a' + 1), pre[i] %= M;
    Ppow[i] = Ppow[i - 1] * P % M;
  }
}
inline long long Hash(int l, int r) {
  return (pre[r] - pre[l - 1] * Ppow[r - (l - 1)] % M + M) % M;
}
int main() {
  scanf("%s%s", s + 1, t + 1);
  lens = strlen(s + 1), lent = strlen(t + 1);
  tot0 = tot1 = 0;
  for (int i = 1; i <= lens; i++) tot0 += (s[i] == '0'), tot1 += (s[i] == '1');
  int ans = 0;
  int len0, len1;
  prework(lent);
  for (len0 = 1; len0 < lent; len0++) {
    if (tot0 * len0 >= lent) break;
    if ((lent - tot0 * len0) % tot1 > 0) continue;
    len1 = (lent - tot0 * len0) / tot1;
    bool ok = 1;
    int cnt0 = 0, cnt1 = 0;
    long long hash_r0 = 0, hash_r1 = 0;
    for (int i = 1; i <= lens; i++) {
      if (s[i] == '0') {
        int l = cnt0 * len0 + cnt1 * len1 + 1, r = l + len0 - 1;
        long long has = Hash(l, r);
        if (hash_r0 == 0) {
          hash_r0 = has;
        } else {
          if (hash_r0 != has) {
            ok = 0;
            break;
          }
        }
        cnt0++;
      }
      if (s[i] == '1') {
        int l = cnt0 * len0 + cnt1 * len1 + 1, r = l + len1 - 1;
        long long has = Hash(l, r);
        if (hash_r1 == 0) {
          hash_r1 = has;
        } else {
          if (hash_r1 != has) {
            ok = 0;
            break;
          }
        }
        cnt1++;
      }
      if (hash_r0 != 0 && hash_r1 != 0 && hash_r0 == hash_r1) {
        ok = 0;
        break;
      }
    }
    if (ok) ans++;
  }
  printf("%d\n", ans);
}
