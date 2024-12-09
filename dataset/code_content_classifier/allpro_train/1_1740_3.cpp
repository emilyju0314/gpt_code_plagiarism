#include <bits/stdc++.h>
using namespace std;
struct Point {
  long long x, y;
  bool operator<(const Point &_) const {
    if (x != _.x) return x < _.x;
    return y > _.y;
  }
} A[100005];
int top, stk[100005];
bool cmp(Point A, Point B, Point C) {
  return 1ll * (B.y - A.y) * (C.x - B.x) <= 1ll * (C.y - B.y) * (B.x - A.x);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    A[i] = (Point){x, y - 1ll * x * x};
  }
  sort(A + 1, A + n + 1);
  for (int i = 1; i <= n; i++) {
    if (i != 1 && A[i].x == A[i - 1].x) continue;
    while (top > 1 && cmp(A[stk[top - 1]], A[stk[top]], A[i])) top--;
    stk[++top] = i;
  }
  printf("%d\n", top - 1);
  return 0;
}
