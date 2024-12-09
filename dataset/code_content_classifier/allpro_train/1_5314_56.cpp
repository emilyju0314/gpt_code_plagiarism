#include <bits/stdc++.h>
using namespace std;
int n, m;
struct tt {
  int x, y;
  tt(int x, int y) : x(x), y(y) {}
  tt() {}
};
bool operator<(tt a, tt b) { return (a.x + a.y) % m < (b.x + b.y) % m; }
int main() {
  scanf("%d%d", &n, &m);
  multiset<int> a, b;
  priority_queue<tt> q;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    a.insert(x);
  }
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    b.insert(x);
  }
  for (multiset<int>::iterator i = a.begin(); i != a.end(); i++) {
    int x = *i;
    multiset<int>::iterator j = b.upper_bound(m - x - 1);
    if (j == b.begin()) j = b.end();
    j--;
    tt tmp(x, *j);
    j = b.end();
    j--;
    tmp = max(tmp, tt(x, *j));
    q.push(tmp);
  }
  for (int i = 0; i < n; i++) {
    int x = q.top().x, y = q.top().y;
    q.pop();
    if (b.find(y) == b.end()) {
      multiset<int>::iterator j = b.upper_bound(m - x - 1);
      if (j == b.begin()) j = b.end();
      j--;
      tt tmp(x, *j);
      j = b.end();
      j--;
      tmp = max(tmp, tt(x, *j));
      q.push(tmp);
      i--;
      continue;
    }
    printf("%d ", (x + y) % m);
    a.erase(a.find(x));
    b.erase(b.find(y));
  }
  return 0;
}
