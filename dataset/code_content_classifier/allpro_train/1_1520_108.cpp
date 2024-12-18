#include <bits/stdc++.h>
using namespace std;
long long a, b, c;
long long ansA, ansB, ansC, ansL;
long long pw[13];
int cal_len(long long x) {
  int ret = 0;
  while (x) ret++, x /= 10;
  return ret;
}
void dfs(long long a, long long b, long long c, long long curA, long long curB,
         int add, int len, int pos) {
  if (len >= ansL || len > 12) return;
  if (a + b + c + add == 0 && len < ansL) {
    ansA = curA;
    ansB = curB;
    ansL = len;
    return;
  }
  if (c == 0) {
    dfs(0, 0, 0, curA + a * pw[pos], curB + b * pw[pos], 0,
        len + cal_len(a + b + add), pos);
    return;
  }
  if (a % 10 + b % 10 + add == c % 10) {
    dfs(a / 10, b / 10, c / 10, curA + (a % 10) * pw[pos],
        curB + (b % 10) * pw[pos], 0, len, pos + 1);
  }
  if (a % 10 + b % 10 + add == c % 10 + 10) {
    dfs(a / 10, b / 10, c / 10, curA + (a % 10) * pw[pos],
        curB + (b % 10) * pw[pos], 1, len, pos + 1);
  }
  int d;
  d = (c % 10 + 10 - add - b % 10) % 10;
  if (a % 10 != d) {
    dfs(a * 10 + d, b, c, curA, curB, add, len + 1, pos);
  }
  d = (c % 10 + 10 - add - a % 10) % 10;
  if (b % 10 != d) {
    dfs(a, b * 10 + d, c, curA, curB, add, len + 1, pos);
  }
  d = (a % 10 + b % 10 + add) % 10;
  if (c % 10 != d) {
    dfs(a, b, c * 10 + d, curA, curB, add, len + 1, pos);
  }
}
int main() {
  char tm;
  pw[0] = 1;
  for (int i = 1; i <= 12; i++) pw[i] = pw[i - 1] * 10;
  while (cin >> a >> tm >> b >> tm >> c) {
    ansL = 12;
    dfs(a, b, c, 0, 0, 0, 0, 0);
    cout << ansA << "+" << ansB << "=" << ansA + ansB << endl;
  }
  return 0;
}
