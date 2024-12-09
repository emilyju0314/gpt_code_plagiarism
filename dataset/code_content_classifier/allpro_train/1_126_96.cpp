#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, k;
  cin >> n >> k;
  long long int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (n == 4 || k < n + 1) {
    cout << -1 << "\n";
    return 0;
  }
  long long int i;
  deque<long long int> q, q2;
  for (i = 1; i <= n; i++) {
    if (i == a || i == b || i == c || i == d) {
      continue;
    }
    q.push_back(i);
  }
  q.push_front(c);
  q.push_front(a);
  q.push_back(d);
  q.push_back(b);
  for (auto i : q) cout << i << " ";
  cout << "\n";
  long long int x = q.front();
  q.pop_front();
  q2.push_back(x);
  q2.push_front(q.front());
  q.pop_front();
  q2.push_back(q.front());
  q.pop_front();
  while (true) {
    x = q.front();
    q.pop_front();
    if (x == d) {
      q.push_front(x);
      break;
    }
    q2.push_back(x);
  }
  while (true) {
    x = q.back();
    q.pop_back();
    q2.push_back(x);
    if (x == d) break;
  }
  for (auto i : q2) cout << i << " ";
  cout << "\n";
  return 0;
}
