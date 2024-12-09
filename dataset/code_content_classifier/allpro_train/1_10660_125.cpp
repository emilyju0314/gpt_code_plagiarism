#include <bits/stdc++.h>
using namespace std;
int n;
int pos[1005], num[1005];
int row[1005], col[1005];
void solve(int t[1005]) {
  for (int i = (1); i <= (n - 1); i++) {
    if (num[i] != i) {
      int p = i, q = pos[i];
      t[p] = q;
      swap(num[p], num[q]);
      swap(pos[num[p]], pos[num[q]]);
    } else {
      t[i] = i;
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); i++) {
    scanf("%d", &num[i]);
    pos[num[i]] = i;
  }
  solve(row);
  for (int i = (1); i <= (n); i++) {
    scanf("%d", &num[i]);
    pos[num[i]] = i;
  }
  solve(col);
  int cnt = 0;
  for (int i = (1); i <= (n - 1); i++) cnt += !(row[i] == i && i == col[i]);
  printf("%d\n", cnt);
  for (int i = (1); i <= (n - 1); i++) {
    if (row[i] == i && i == col[i]) continue;
    printf("%d %d %d %d\n", row[i], i, i, col[i]);
  }
  return 0;
}
