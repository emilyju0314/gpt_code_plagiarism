#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll point[8][3];
ll d[70];
ll dis(int x, int y) {
  return (point[x][0] - point[y][0]) * (point[x][0] - point[y][0]) +
         (point[x][1] - point[y][1]) * (point[x][1] - point[y][1]) +
         (point[x][2] - point[y][2]) * (point[x][2] - point[y][2]);
}
bool check() {
  int now = 0;
  ll minn = 1ll << 60;
  for (int i = 0; i < 8; i++) {
    for (int j = i + 1; j < 8; j++) {
      d[now] = dis(i, j);
      minn = min(minn, d[now++]);
    }
  }
  int cnt1 = 0, cnt2 = 0, cnt3 = 0;
  if (minn == 0) return false;
  for (int i = 0; i < now; i++) {
    if (d[i] == minn)
      cnt1 += 1;
    else if (d[i] == minn * 2)
      cnt2 += 1;
    else if (d[i] == minn * 3)
      cnt3 += 1;
  }
  if (cnt1 == 12 && cnt2 == 12 && cnt3 == 4) return true;
  return false;
}
bool dfs(int cnt) {
  if (cnt >= 8) return false;
  sort(point[cnt], point[cnt] + 3);
  do {
    if (check() || dfs(cnt + 1)) return true;
  } while (next_permutation(point[cnt], point[cnt] + 3));
  return false;
}
int main() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%lld", &point[i][j]);
    }
  }
  if (dfs(0)) {
    puts("YES");
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 3; j++) {
        printf("%lld ", point[i][j]);
      }
      puts("");
    }
  } else
    puts("NO");
  return 0;
}
