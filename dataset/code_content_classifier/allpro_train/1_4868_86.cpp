#include <bits/stdc++.h>
using namespace std;
set<long long int> s;
multiset<long long int> m;
void add(long long int x) {
  s.insert(x);
  auto it = s.find(x);
  if (it != s.begin()) {
    m.insert((*it) - (*prev(it)));
  }
  if (next(it) != s.end()) {
    m.insert((*next(it)) - (*it));
  }
  if (next(it) != s.end() && it != s.begin()) {
    m.erase(m.find((*next(it)) - (*prev(it))));
  }
}
void remove(long long int x) {
  auto it = s.find(x);
  if (it != s.begin()) {
    m.erase(m.find((*it) - (*prev(it))));
  }
  if (next(it) != s.end()) {
    m.erase(m.find(*next(it) - (*it)));
  }
  if (next(it) != s.end() && it != s.begin()) {
    m.insert((*next(it)) - (*prev(it)));
  }
  s.erase(x);
}
void query() {
  if (s.empty()) {
    cout << 0 << '\n';
    return;
  }
  if (m.empty()) {
    cout << 0 << '\n';
    return;
  }
  long long int ans = (*s.rbegin()) - (*s.begin()) - (*m.rbegin());
  cout << ans << '\n';
}
void mainSolve() {
  long long int n;
  cin >> n;
  long long int q;
  cin >> q;
  for (int i = 0; i < n; i++) {
    long long int a;
    cin >> a;
    add(a);
  }
  query();
  while (q--) {
    long long int a;
    cin >> a;
    long long int b;
    cin >> b;
    if (a == 0)
      remove(b);
    else
      add(b);
    query();
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  while (t--) {
    mainSolve();
  }
  return 0;
}
