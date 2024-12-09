/*
 * 2664.cc: Shopping
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

const int MAX_N = 5000;

/* typedef */

typedef map<string,int> msi;

struct UFT {
  int links[MAX_N], ranks[MAX_N], sizes[MAX_N];

  void clear(int n) {
    for (int i = 0; i < n; i++) links[i] = i, ranks[i] = sizes[i] = 1;
  }

  UFT() {}
  UFT(int n) { clear(n); }

  int root(int i) {
    int i0 = i;
    while (links[i0] != i0) i0 = links[i0];
    return (links[i] = i0);
  }

  int rank(int i) { return ranks[root(i)]; }
  int size(int i) { return sizes[root(i)]; }
  bool same(int i, int j) { return root(i) == root(j); }

  int merge(int i0, int i1) {
    int r0 = root(i0), r1 = root(i1), mr;
    if (ranks[r0] == ranks[r1]) {
      links[r1] = r0;
      sizes[r0] += sizes[r1];
      ranks[r0]++;
      mr = r0;
    }
    else if (ranks[r0] > ranks[r1]) {
      links[r1] = r0;
      sizes[r0] += sizes[r1];
      mr = r0;
    }
    else {
      links[r0] = r1;
      sizes[r1] += sizes[r0];
      mr = r1;
    }
    return mr;
  }
};

/* global variables */

UFT uft;
string as[MAX_N];
msi amap;
int xs[MAX_N];

/* subroutines */

/* main */

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> as[i] >> xs[i];
    amap[as[i]] = i;
  }

  uft.clear(n);

  int m;
  cin >> m;
  
  for (int i = 0; i < m; i++) {
    string a0, a1;
    cin >> a0 >> a1;

    int i0 = amap[a0], i1 = amap[a1];
    int r0 = uft.root(i0), r1 = uft.root(i1);
    if (r0 != r1) {
      int r = uft.merge(r0, r1);
      xs[r] = (xs[r0] < xs[r1]) ? xs[r0] : xs[r1];
    }
  }

  int sum = 0;
  for (int i = 0; i < n; i++) sum += xs[uft.root(i)];
  printf("%d\n", sum);
  return 0;
}