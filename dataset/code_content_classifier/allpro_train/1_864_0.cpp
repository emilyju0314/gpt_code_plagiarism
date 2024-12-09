/*  -*- coding: utf-8 -*-
 *
 * 2931.cc: 
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

const int MAX_N = 100000;

/* typedef */

typedef stack<int> sti;

/* global variables */

int qs[MAX_N];
char s[MAX_N * 2 + 4];
sti st;

/* subroutines */

/* main */

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int pi;
    scanf("%d", &pi);
    pi--;
    qs[pi] = i;
  }
  //for (int i = 0; i < n; i++) printf("%d ", qs[i]); putchar('\n');

  for (int i = 0, j = 0, k = 0; i < n || j < n; i++) {
    while (! st.empty() && st.top() == j)
      s[k++] = ')', j++, st.pop();

    if (i >= n) {
      if (j < n) {
	puts(":(");
	return 0;
      }
      break;
    }

    st.push(qs[i]);
    s[k++] = '(';
  }

  puts(s);
  return 0;
}

