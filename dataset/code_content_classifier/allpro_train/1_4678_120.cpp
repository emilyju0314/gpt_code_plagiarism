#include <bits/stdc++.h>
using namespace std;
int n, m;
int food[120];
void init() { memset(food, 0, sizeof(food)); }
bool cmp(int a, int b) { return a > b; }
int judge(int quantity) {
  int a[110], cnt = 0;
  int sum = 0;
  for (int i = 0; i < 110 && food[i] != 0; i++) {
    a[i] = food[i];
    sum += food[i];
    cnt++;
  }
  int species = cnt;
  cnt = 0;
  for (int j = 0, i = 0; i < 110 && j < species;) {
    if (a[j] >= quantity) {
      i++;
      a[j] -= quantity;
      cnt++;
    } else
      j++;
  }
  if (cnt >= n)
    return 1;
  else
    return 0;
}
int main() {
  std::ios::sync_with_stdio(false);
  while (cin >> n >> m) {
    init();
    int foodtmp;
    for (int i = 0; i < m; i++) {
      cin >> foodtmp;
      food[foodtmp]++;
    }
    sort(food, food + 110, cmp);
    int l, r, mid;
    l = 1;
    r = 100;
    int res = 0;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (judge(mid)) {
        res = mid;
        l = mid + 1;
      } else
        r = mid - 1;
    }
    cout << res << endl;
  }
  return 0;
}
