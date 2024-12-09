#include <bits/stdc++.h>
using namespace std;
const int max_n = 1e3;
int n;
int cor[max_n + 1];
void input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> cor[i];
  }
}
bool check(int l1, int r1, int l2, int r2) {
  if (l1 == l2 && r1 == r2) return true;
  if (l2 > l1 && l2 < r1 && r2 > r1) return true;
  if (l2 < l1 && r2 > l1 && r2 < r1) return true;
  return false;
}
void output() {
  bool flag = false;
  for (int i = 0; i < n - 1; i++) {
    int cur_l = min(cor[i], cor[i + 1]), cur_r = max(cor[i + 1], cor[i]);
    for (int j = 0; j < n - 1; j++) {
      if (j == i) continue;
      if (check(cur_l, cur_r, min(cor[j], cor[j + 1]),
                max(cor[j], cor[j + 1]))) {
        flag = true;
        goto ans;
      }
    }
  }
ans:;
  if (flag)
    cout << "yes\n";
  else
    cout << "no\n";
}
int main() {
  input();
  output();
  return 0;
}
