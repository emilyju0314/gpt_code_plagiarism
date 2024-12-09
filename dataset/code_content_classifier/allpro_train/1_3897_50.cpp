/*  -*- coding: utf-8 -*-
 *
 * 3000.cc: 
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

const double PI = acos(-1.0);

/* typedef */

/* global variables */

/* subroutines */



/* main */

int main() {
  int a0, a1;
  scanf("%d%d", &a0, &a1);

  double t0 = PI * a0 / 180, t1 = PI * a1 / 180;
  double t = atan2(sin(t0) + sin(t1), cos(t0) + cos(t1));
  if (t < 0.0) t += PI * 2;
  printf("%.1lf\n", t * 180 / PI);
  return 0;
}

