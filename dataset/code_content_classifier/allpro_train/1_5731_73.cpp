#include <bits/stdc++.h>
using namespace std;
class Solver {
  mt19937 rng;
  int ans;
  int f[1000];
  char ask(int a, int b);
  char ask(int l0, int r0, int l1, int r1);

 public:
  Solver() : rng(chrono::steady_clock::now().time_since_epoch().count()) {
    iota(f, f + 1000, 1);
  }
  int solve(int n, int tries);
};
int main() {
  Solver S;
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("! %d\n", S.solve(n, 30));
    fflush(stdout);
  }
}
char Solver::ask(int l0, int r0, int l1, int r1) {
  printf("? %d %d\n", r0 - l0, r1 - l1);
  while (l0 < r0) printf("%d ", f[l0++]);
  putchar('\n');
  while (l1 < r1) printf("%d ", f[l1++]);
  putchar('\n');
  fflush(stdout);
  char ans[7];
  scanf("%s", ans);
  return ans[0];
}
char Solver::ask(int a, int b) { return ask(a, a + 1, b, b + 1); }
int Solver::solve(int n, int tries) {
  int argmax = 0;
  for (int i = 0; i < tries; ++i) {
    int a = rng() % n;
    if (a == argmax) a = (a + 1) % n;
    if (ask(argmax, a) == 'S') argmax = a;
  }
  rotate(f, f + argmax, f + argmax + 1);
  int l = 0, len;
  for (len = 1; l == 0 && len < n >> 1; len <<= 1) {
    switch (ask(0, len, len, len << 1)) {
      case 'F':
        l = len;
      case 'E':
        break;
      default:
        return -1;
    }
  }
  if (l > 0) {
    len >>= 1;
  } else {
    l = len;
    len = n - len;
  }
  while (len > 1) {
    switch (ask(0, len >> 1, l, l + (len >> 1))) {
      case 'F':
        len >>= 1;
        break;
      case 'E':
        l += len >> 1;
        len -= len >> 1;
        break;
      default:
        return -1;
    }
  }
  int res = f[l];
  rotate(f, f + 1, f + argmax + 1);
  return res;
}
