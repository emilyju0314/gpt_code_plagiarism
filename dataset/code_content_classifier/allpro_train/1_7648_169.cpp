#include <bits/stdc++.h>
using namespace std;
int n, k;
string walls[2];
bool got[2][100006];
void dfs(int p, int l, int w) {
  if (got[p % 2][l]) return;
  if (l <= w) return;
  if (walls[p % 2][l] == 'X') return;
  got[p % 2][l] = 1;
  if (l + k > n) {
    cout << "YES";
    exit(0);
  }
  dfs(p + 1, l + k, w + 1);
  dfs(p, l - 1, w + 1);
  dfs(p, l + 1, w + 1);
}
int main() {
  cin >> n >> k;
  cin >> walls[0] >> walls[1];
  dfs(0, 0, -1);
  cout << "NO";
  return 0;
}
