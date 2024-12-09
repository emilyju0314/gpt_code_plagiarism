#include <bits/stdc++.h>
using namespace std;
long long n, k, m, l;
struct juzhen {
  long long zz[2][2];
};
juzhen cheng(juzhen p, juzhen q) {
  juzhen qq = {{{0, 0}, {0, 0}}};
  for (int a = 0; a < 2; a++) {
    for (int b = 0; b < 2; b++) {
      for (int c = 0; c < 2; c++) {
        qq.zz[a][b] += (p.zz[a][c] * q.zz[c][b]) % m;
      }
    }
  }
  return qq;
}
juzhen ksm(juzhen di, long long zhishu) {
  juzhen fanhui;
  for (int a = 0; a < 2; a++) {
    for (int b = 0; b < 2; b++) {
      if (a == b)
        fanhui.zz[a][b] = 1;
      else
        fanhui.zz[a][b] = 0;
    }
  }
  while (zhishu) {
    if (zhishu & 1) fanhui = cheng(fanhui, di);
    zhishu >>= 1;
    di = cheng(di, di);
  }
  return fanhui;
}
long long kksm(long long di, long long zhishu) {
  long long fanhui = 1;
  while (zhishu) {
    if (zhishu & 1) fanhui *= di;
    fanhui %= m;
    zhishu >>= 1;
    di *= di;
    di %= m;
  }
  return fanhui % m;
}
int main() {
  cin >> n >> k >> l >> m;
  if (pow(2, l) <= k) {
    cout << 0;
    return 0;
  }
  juzhen kp;
  kp.zz[0][0] = kp.zz[0][1] = kp.zz[1][0] = 1;
  kp.zz[1][1] = 0;
  long long ling, yi;
  kp = ksm(kp, n);
  ling = (kp.zz[0][0] + kp.zz[0][1]) % m;
  long long quan = kksm(2, n);
  yi = quan - ling;
  long long jg = 1;
  while (k) {
    if (k & 1)
      jg *= yi;
    else
      jg *= ling;
    k >>= 1;
    jg %= m;
    l--;
  }
  while (l >= 1) {
    jg *= ling;
    jg %= m;
    l--;
  }
  jg += m;
  jg %= m;
  cout << jg;
  return 0;
}
