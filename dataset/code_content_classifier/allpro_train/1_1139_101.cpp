#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> mp;
int main() {
  int n;
  cin >> n;
  set<int> s;
  int x;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    s.insert(x);
    s.erase(i);
    if (s.size() == 0) ans++;
  }
  printf("%d\n", ans);
}
