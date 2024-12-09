#include <bits/stdc++.h>
using namespace std;
int a[10], b[10];
bool book[10], flag = 0;
void dfs(int sum) {
  if (sum == 6)
    if (b[0] + b[1] + b[2] == b[3] + b[4] + b[5]) {
      cout << "YES";
      flag = 1;
    }
  if (flag == 1) return;
  for (int i = 0; i < 6; i++) {
    if (book[i] == 0) {
      b[sum] = a[i];
      book[i] = 1;
      dfs(sum + 1);
      book[i] = 0;
    }
  }
  return;
}
int main() {
  for (int i = 0; i < 6; i++) cin >> a[i];
  dfs(0);
  if (flag == 0) cout << "NO";
}
