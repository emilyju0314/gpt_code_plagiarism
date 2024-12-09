#include <bits/stdc++.h>
using namespace std;
bool ask(int x, int y) {
  static char ty[10];
  printf("1 %d %d\n", x, y);
  fflush(stdout);
  scanf("%s", ty);
  return *ty == 'T';
}
int find(int l, int r) {
  while (l < r) {
    int mid = (l + r) >> 1;
    int flag = ask(mid, mid + 1);
    if (flag)
      r = mid;
    else
      l = mid + 1;
  }
  return l;
}
int main() {
  int N, K;
  scanf("%d%d", &N, &K);
  int ans[2];
  ans[0] = find(1, N);
  ans[1] = 0;
  if (ans[0] > 1) {
    ans[1] = find(1, ans[0] - 1);
    if (!ask(ans[1], ans[0])) ans[1] = 0;
  }
  if (!ans[1] && ans[0] < N) ans[1] = find(ans[0] + 1, N);
  printf("2 %d %d\n", ans[0], ans[1]);
  fflush(stdout);
  return 0;
}
