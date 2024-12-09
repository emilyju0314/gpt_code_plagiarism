#include <bits/stdc++.h>
#define N (long long)(1e9 + 7)
using namespace std;

long long k = 0, bnr, pls, allnum;
long long memo[35][2][2] = {0}, fmemo[2][2][2] = {0},
          f[2] = {0};

long long binary();
void memoset();
long long solve();
void calcfmemo(int x, int p);

int main() {
  memoset();
  cin >> k;
  bnr = binary();
  allnum = bnr / 2;
  pls = k - allnum * ((bnr - 1) / 2);
  if((allnum + 1) / 2 >= pls) {
    f[0] = pls * 2 - 1;
    f[1] = bnr - f[0];
  }
  else {
    f[0] = 2 * (allnum + 1 - pls);
    f[1] = bnr - f[0];
  }
  cout << solve() << endl;
  return 0;
}

long long binary() {
  long long l = 2, r = 10000000000, now;
  while(r - l > 0) {
    if(r - l == 1) {
      if((l / 2) * ((l + 1) / 2) < k)
        now = r;
      else
        now = l;
      break;
    }
    now = (l + r) / 2;
    if((now / 2) * ((now + 1) / 2) < k)
      l = now;
    else
      r = now;
  }
  return now;
}

void memoset() {
  memo[0][0][0] = memo[0][0][1] = memo[0][1][0] = 1;
  for(int i = 1; i <= 32; ++i) {
    for(int j = 0; j < 2; ++j)
      for(int l = 0; l < 2; ++l)
        for(int m = 0; m < 2; ++m) {
          memo[i][j][l] +=
              (memo[i - 1][j][m] * memo[i - 1][m][l]) % N;
          memo[i][j][l] %= N;
        }
  }
}

long long solve() {
  int fnum, i;
  long long ans = 1, now;
  for(fnum = 0; fnum < 2; ++fnum) {
    fmemo[fnum][0][0] = fmemo[fnum][1][1] = 1;
    now = 30;
    while(f[fnum] > 0) {
      if(f[fnum] >= (1 << now)) {
        calcfmemo(fnum, now);
        f[fnum] -= (1 << now);
      }
      --now;
    }
  }
  for(i = 0; i < 2; ++i)
    ans *= (fmemo[i][1][0] + fmemo[i][1][1]) % N;

  return ans % N;
}
void calcfmemo(int x, int p) {
  long long dummy[2][2] = {0};
  for(int i = 0; i < 2; ++i)
    for(int j = 0; j < 2; ++j)
      for(int l = 0; l < 2; ++l) {
        dummy[i][j] += fmemo[x][i][l] * memo[p][l][j];
        dummy[i][j] %= N;
      }
  for(int i = 0; i < 2; ++i)
    for(int j = 0; j < 2; ++j) fmemo[x][i][j] = dummy[i][j];
}
