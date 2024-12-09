#include <bits/stdc++.h>
using namespace std;
int n, start, p, ans;
set<pair<int, int> > st;
int main() {
  srand(time(nullptr));
  scanf("%d%d%d", &n, &start, &p);
  for (int i = 1; i < 1000; ++i) {
    if (i > n) break;
    int x = rand() * rand() % n + 1;
    printf("? %d\n", x);
    fflush(stdout);
    int y;
    scanf("%d%d", &x, &y);
    fflush(stdout);
    if (x < p && x > ans) {
      start = y;
      ans = x;
    }
  }
  int x = start;
  if (x == -1) {
    printf("! -1");
    fflush(stdout);
    return 0;
  }
  for (int i = 0; i < 1000; ++i) {
    printf("? %d\n", x);
    fflush(stdout);
    int y;
    scanf("%d%d", &x, &y);
    fflush(stdout);
    if (x >= p) {
      printf("! %d\n", x);
      fflush(stdout);
      return 0;
    }
    if (y == -1) {
      printf("! -1");
      fflush(stdout);
      return 0;
    }
    x = y;
  }
  printf("! -1");
  fflush(stdout);
}
