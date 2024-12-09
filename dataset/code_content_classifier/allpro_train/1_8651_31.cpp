#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
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

const int MAX_X = 1000000;
const int MAX_Y = 1000000;

/* typedef */

/* global variables */

int x, y;
int rems[MAX_Y];

/* subroutines */

/* main */

int main() {
  for (;;) {
    cin >> x >> y;
    if (x == 0) break;

    for (int i = 0; i < y; i++) rems[i] = -1;

    int rp = 0;

    while (x && rems[x] < 0) {
      rems[x] = rp++;
      x = (x * 10) % y;
    }
    //printf("rp=%d, x=%d, rems[x]=%d\n", rp, x, rems[x]);

    if (x == 0)
      printf("%d 0\n", rp);
    else
      printf("%d %d\n", rems[x], rp - rems[x]);
  }

  return 0;
}