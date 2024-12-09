#include <bits/stdc++.h>
using namespace std;
int getint() {
  unsigned int c;
  int x = 0;
  while (((c = getchar()) - '0') >= 10) {
    if (c == '-') return -getint();
    if (!~c) exit(0);
  }
  do {
    x = (x << 3) + (x << 1) + (c - '0');
  } while (((c = getchar()) - '0') < 10);
  return x;
}
const int MAXN = 66;
unsigned long long bn[MAXN + 1][MAXN + 1];
void make_bn(int n) {
  for (int i = 0; i <= n; i++) {
    bn[i][0] = bn[i][i] = 1;
    for (int j = 1; j < i; j++) bn[i][j] = bn[i - 1][j - 1] + bn[i - 1][j];
  }
}
unsigned long long m, k;
unsigned long long solve(unsigned long long d, int rest_bit) {
  if (rest_bit == 0) {
    if (d == 0) return 1;
    return 0;
  }
  if (d == 0) {
    return 0;
  }
  int most_sig = 0;
  while ((1ULL << most_sig + 1) <= d) most_sig++;
  unsigned long long assign_zero = bn[most_sig][rest_bit];
  unsigned long long top_1 = solve(d - (1ULL << most_sig), rest_bit - 1);
  return assign_zero + top_1;
}
int main() {
  int i, j, tcc, tc = 1;
  make_bn(65);
  for (tcc = 0; tcc < tc; tcc++) {
    cin >> m >> k;
    unsigned long long lo = 1, hi = (unsigned long long)1e18, md1, md2;
    for (; lo <= hi;) {
      md1 = lo + hi >> 1;
      md2 = md1 << 1;
      unsigned long long cnt2 = solve(md2, k);
      unsigned long long cnt1 = solve(md1, k);
      unsigned long long cnt = cnt2 - cnt1;
      if (cnt == m) {
        hi = md1;
        break;
      }
      if (cnt > m) {
        hi = md1 - 1;
      } else {
        lo = md1 + 1;
      }
    }
    cout << hi << endl;
  }
  return 0;
}
