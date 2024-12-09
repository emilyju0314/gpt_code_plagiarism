#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
char s[maxn];
struct node {
  char c;
  int len;
};
double a[maxn];
int n, m;
void judge(int x, int d, int po) {}
void work() {
  scanf("%d%d", &n, &m);
  double sub = 0, add = 0, xm = 0;
  while (m--) {
    int x, d;
    scanf("%d%d", &x, &d);
    xm += x;
    if (d > 0) {
      add += d;
    } else {
      sub += d;
    }
  }
  double ans = 0;
  for (int i = 0; i < n; i++) ans += xm + add * i + sub * abs(i - n / 2);
  printf("%f\n", ans / (double)n);
}
int main() {
  work();
  return 0;
}
