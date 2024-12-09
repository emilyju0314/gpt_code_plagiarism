#include <bits/stdc++.h>
using namespace std;
void swap(int &a, int &b) {
  int temp = a;
  a = b, b = temp;
}
int main(int argc, char const *argv[]) {
  int n, m, i, j, l, r, x;
  cin >> n >> m;
  set<int> alive;
  for (i = 0; i <= n; i++) alive.insert(i);
  set<int>::iterator it, it1;
  vector<int> winner(n + 1, 0);
  for ((j) = 0; (j) < (int)(m); (j)++) {
    cin >> l >> r >> x;
    it = alive.lower_bound(l);
    while (it != alive.end()) {
      it1 = it;
      it1++;
      if (*it > r) break;
      if (*it != x) {
        winner[*it] = x;
        alive.erase(it);
      }
      it = it1;
    }
  }
  for (i = 1; i <= n; i++) cout << winner[i] << " ";
  cout << endl;
  return 0;
}
