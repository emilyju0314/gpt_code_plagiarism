#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, t, r = 0, n, x, k, a[100005];
  stack<int> q;
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  q.push(a[0]);
  for (i = 1; i < n; i++) {
    if (a[i] == q.top()) continue;
    if (a[i] > q.top()) {
      while (q.size() > 0 && a[i] >= q.top()) {
        k = q.top();
        q.pop();
        if (q.size() > 0) r = max(r, q.top() ^ k);
      }
    }
    q.push(a[i]);
  }
  while (q.size() > 1) {
    k = q.top();
    q.pop();
    r = max(r, q.top() ^ k);
  }
  q.pop();
  q.push(a[n - 1]);
  for (i = n - 2; i >= 0; i--) {
    if (a[i] == q.top()) continue;
    if (a[i] > q.top()) {
      while (q.size() > 0 && a[i] >= q.top()) {
        k = q.top();
        q.pop();
        if (q.size() > 0) r = max(r, q.top() ^ k);
      }
    }
    q.push(a[i]);
  }
  while (q.size() > 1) {
    k = q.top();
    q.pop();
    r = max(r, q.top() ^ k);
  }
  cout << r << endl;
  return 0;
}
