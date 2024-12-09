#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const double PI = acos(-1);
const int N = 2e5 + 10;
int n, q;
set<int> cells, negcells;
set<int>::iterator it;
unordered_map<int, int> blocked;
unordered_map<int, char> dir;
int getUP(int at) {
  it = cells.lower_bound(at);
  if (it != cells.end()) {
    if (*it == at) return -1;
    return (dir[*it] == 'U') ? blocked[*it] : (n + 1 - *it);
  }
  return 0;
}
int getDOWN(int at) {
  it = negcells.lower_bound(-at);
  if (it != negcells.end()) {
    if (-*it == at) return -1;
    return (dir[-*it] == 'L') ? blocked[-*it] : -*it;
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> q;
  for (int i = 0; i < (q); i++) {
    int x, y;
    char d;
    cin >> x >> y >> d;
    if (d == 'U') {
      int next = getUP(x);
      if (next != -1) {
        blocked[x] = next;
        dir[x] = 'U';
        cout << (n + 1 - x) - next << endl;
      } else
        cout << 0 << endl;
    } else {
      int next = getDOWN(x);
      if (next != -1) {
        blocked[x] = next;
        dir[x] = 'L';
        cout << x - next << endl;
      } else
        cout << 0 << endl;
    }
    cells.insert(x);
    negcells.insert(-x);
  }
  return 0;
}
