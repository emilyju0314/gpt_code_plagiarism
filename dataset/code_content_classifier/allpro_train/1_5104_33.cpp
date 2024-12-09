/*
 * B.cc: 
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>

using namespace std;

/* constant */

const int N = 5;

/* typedef */

/* global variables */

int dp[2][N][N][N][N];

/* subroutines */

int rec(int k, int l0, int r0, int l1, int r1) {
  if (dp[k][l0][r0][l1][r1] >= 0) return dp[k][l0][r0][l1][r1];

  int ret;
  if (k == 0) {
    if ((l0 > 0 &&
	 ((l1 > 0 && rec(1, l0, r0, (l1 + l0) >= N ? 0 : l1 + l0, r1) == 0) ||
	  (r1 > 0 && rec(1, l0, r0, l1, (r1 + l0) >= N ? 0 : r1 + l0) == 0))) ||
	(r0 > 0 &&
	 ((l1 > 0 && rec(1, l0, r0, (l1 + r0) >= N ? 0 : l1 + r0, r1) == 0) ||
	  (r1 > 0 && rec(1, l0, r0, l1, (r1 + r0) >= N ? 0 : r1 + r0) == 0))))
      ret = 0;
    else
      ret = 1;
  }
  else {
    if ((l1 > 0 &&
	 ((l0 > 0 && rec(0, (l0 + l1) >= N ? 0 : l0 + l1, r0, l1, r1) == 1) ||
	  (r0 > 0 && rec(0, l0, (r0 + l1) >= N ? 0 : r0 + l1, l1, r1) == 1))) ||
	(r1 > 0 &&
	 ((l0 > 0 && rec(0, (l0 + r1) >= N ? 0 : l0 + r1, r0, l1, r1) == 1) ||
	  (r0 > 0 && rec(0, l0, (r0 + r1) >= N ? 0 : r0 + r1, l1, r1) == 1))))
      ret = 1;
    else
      ret = 0;
  }

  return (dp[k][l0][r0][l1][r1] = ret);
}

/* main */

int main() {
  int l0, r0, l1, r1;
  cin >> l0 >> r0 >> l1 >> r1;

  memset(dp, -1, sizeof(dp));

  int ans = rec(0, l0, r0, l1, r1);
  cout << (ans == 0 ? "ISONO" : "NAKAJIMA") << endl;
  return 0;
}