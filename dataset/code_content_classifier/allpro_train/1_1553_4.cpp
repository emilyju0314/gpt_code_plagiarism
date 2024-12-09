/*  -*- coding: utf-8 -*-
 *
 * 1583.cc: Equivalent Vertices
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

const int MAX_N = 3000;
const int MAX_GN = MAX_N * (MAX_N + 1) / 2;
const int INF = 1 << 30;

/* typedef */

typedef vector<int> vi;
typedef queue<int> qi;

/* global variables */

int vs[MAX_N], nbrs[MAX_N][2], cs[MAX_N];
vi gnbrs[MAX_GN];
int pids[MAX_N][MAX_N], pis[MAX_GN], pjs[MAX_GN];
bool ds[MAX_GN];

/* subroutines */

/* main */

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  for (int i = 0; i < n; i++)
    scanf("%d%d%d", vs + i, nbrs[i], nbrs[i] + 1);

  memset(pids, -1, sizeof(pids));
  for (int i = 0, p = 0; i < n; i++)
    for (int j = i; j < n; j++, p++)
      pids[i][j] = p, pis[p] = i, pjs[p] = j;

  qi q;
  for (int i = 0, p = 0; i < n; i++)
    for (int j = i; j < n; j++, p++) {
      for (int di = 0; di < 2; di++) {
	int ri = nbrs[i][di], rj = nbrs[j][di];
	if (ri > rj) swap(ri, rj);
	gnbrs[pids[ri][rj]].push_back(p);
      }
      if (vs[i] != vs[j]) {
	ds[p] = true;
	q.push(p);
      }
    }

  while (! q.empty()) {
    int u = q.front(); q.pop();
    int ui = pis[u], uj = pjs[u];
    vi &gnbru = gnbrs[u];

    for (vi::iterator vit = gnbru.begin(); vit != gnbru.end(); vit++) {
      int &v = *vit;
      if (! ds[v]) {
	ds[v] = true;
	q.push(v);
      }
    }
  }

  for (int i = 0, p = 0; i < n; i++)
    for (int j = i; j < n; j++, p++)
      if (! ds[p]) cs[i]++, cs[j]++;

  while (m--) {
    int q;
    scanf("%d", &q);
    printf("%d\n", cs[q] - 1);
  }
  return 0;
}

