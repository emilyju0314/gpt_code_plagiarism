#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
set<int> cant;
int n, q;
bool grid[2][N];
int main() {
  cin >> n >> q;
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    if (!grid[x][y]) {
      grid[x][y] = true;
      if (grid[(x + 1) % 2][y]) {
        cant.insert(y);
      }
      if (y != 0 && grid[(x + 1) % 2][y - 1]) {
        cant.insert(y);
      }
      if (y != n - 1 && grid[(x + 1) % 2][y + 1]) {
        cant.insert(y + 1);
      }
    } else if (grid[x][y]) {
      grid[x][y] = false;
      if (y != n - 1 && !grid[x][y + 1]) {
        cant.erase(y + 1);
      }
      if (y != 0 && !grid[x][y - 1]) {
        cant.erase(y);
      }
    }
    if (!cant.size()) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
