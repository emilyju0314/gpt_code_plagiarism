#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n, a, b, c;
int lu[3][3];
void dfs(int time, int sum, int now) {
  if (time == n) {
    printf("%d\n", sum);
    return;
  }
  int temp = lu[now][0], t = 0;
  for (int i = 1; i < 3; i++) {
    if (lu[now][i] < temp) {
      temp = lu[now][i];
      t = i;
    }
  }
  dfs(++time, sum + temp, t);
}
int main() {
  scanf("%d%d%d%d", &n, &a, &b, &c);
  memset(lu, INF, sizeof(lu));
  lu[0][1] = lu[1][0] = a;
  lu[0][2] = lu[2][0] = b;
  lu[1][2] = lu[2][1] = c;
  dfs(1, 0, 0);
  return 0;
}
