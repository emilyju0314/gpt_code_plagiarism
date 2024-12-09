/*  -*- coding: utf-8 -*-
 *
 * 2928.cc: Mail Order
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

const int MAX_H = 100000;
const int MAX_W = 100000;

/* typedef */

typedef long long ll;

template <typename T, const int MAX_N>
struct BIT {
  int n;
  T bits[MAX_N + 1];
  BIT() {}

  void init(int _n) {
    n = _n;
    memset(bits, 0, sizeof(bits));
  }

  T sum(int x) {
    T s = 0;
    while (x > 0) {
      s += bits[x];
      x -= (x & -x);
    }
    return s;
  }

  void add(int x, T v) {
    while (x <= n) {
      bits[x] += v;
      x += (x & -x);
    }
  }
};

/* global variables */

int as[MAX_H], uas[MAX_H];
BIT<int,MAX_H> abit;
BIT<ll,MAX_H> sbit;

/* subroutines */

/* main */

int main() {
  int h, w;
  scanf("%d%d", &h, &w);

  for (int i = 0; i < h; i++)
    scanf("%d", as + i), uas[i] = as[i];

  sort(uas, uas + h);
  int un = unique(uas, uas + h) - uas;

  abit.init(un), sbit.init(un);
  for (int i = 0; i < h; i++) {
    int k = lower_bound(uas, uas + un, as[i]) - uas;
    abit.add(k + 1, 1);
    sbit.add(k + 1, as[i]);
  }

  ll sum = 0;
  for (int i = 0; i < w; i++) {
    int bi;
    scanf("%d", &bi);

    int k = upper_bound(uas, uas + un, bi) - uas;
    int j = abit.sum(k);
    sum += sbit.sum(k) + (ll)bi * (h - j);
  }

  printf("%lld\n", sum);
  return 0;
}

