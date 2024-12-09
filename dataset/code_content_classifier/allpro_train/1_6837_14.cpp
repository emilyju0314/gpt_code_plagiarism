/*  -*- coding: utf-8 -*-
 *
 * 2912.cc: Sum of QQ
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

const int MAX_S = 100000;

/* typedef */

/* global variables */

int ps[500], cs[MAX_S + 1];

/* subroutines */

int countp(int k) {
  int c = 0;
  for (int i = 1; ps[i] <= k; i++)
    if ((k - ps[i]) % i == 0) c++;
  return c;
}

/* main */

int main() {
  int s;
  scanf("%d", &s);

  int pn = 1;
  while ((ps[pn] = pn * (pn + 1) / 2) <= s) pn++;
  //printf("pn=%d:", pn);
  //for (int i = 1; i <= pn; i++) printf(" %d", ps[i]); putchar('\n');

  int cnt = 0;
  for (int x = 1; x <= s; x++)
    if (s % x == 0) {
      int y = s / x;
      if (! cs[x]) cs[x] = countp(x);
      if (! cs[y]) cs[y] = countp(y);
      cnt += cs[x] * cs[y];
      //printf("(%d,%d) = %dx%d\n", x, y, cs[x], cs[y]);
    }

  printf("%d\n", cnt);
  return 0;
}

