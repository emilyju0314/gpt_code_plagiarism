/*  -*- coding: utf-8 -*-
 *
 * 2844.cc: Almost Infinite Glico
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

const int MAX_N = 800;
const int MOD = 1000000007;

/* typedef */

typedef long long ll;
typedef int vec[MAX_N];

/* global variables */

vec av, bv, cv;
vec sv, tv;

/* subroutines */

inline void addmod(int &a, int b) { a = (a + b) % MOD; }

inline void initvec(const int n, vec a) {
  memset(a, 0, sizeof(vec));
}

inline void copyvec(const int n, const vec a, vec b) {
  memcpy(b, a, sizeof(vec));
}

inline void mulvec(const int n, const vec a, const vec b, vec c) {
  initvec(n, c);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      addmod(c[(i + j) % n], (ll)a[i] * b[j] % MOD);
}

/* main */

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);

  initvec(n, av);
  av[0] = 1;
  for (int i = 0; i < m; i++) {
    int pi;
    scanf("%d", &pi);
    av[pi % n]++;
  }

  initvec(n, bv);
  bv[0] = 1;
  while (k > 0) {
    if (k & 1) {
      mulvec(n, bv, av, sv);
      copyvec(n, sv, bv);
    }

    mulvec(n, av, av, sv);
    copyvec(n, sv, av);
    k >>= 1;
  }

  for (int i = 0; i < n; i++) printf("%d\n", bv[i]);
  return 0;
}

