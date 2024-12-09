#include <bits/stdc++.h>
using namespace std;
const int maxq = 13;
long long ask(const vector<int> &v) {
  cout << "? " << v.size();
  for (auto x : v) cout << ' ' << x + 1;
  cout << endl;
  long long ret;
  cin >> ret;
  return ret;
}
vector<int> q[maxq];
int n;
long long ret[maxq];
int main() {
  cin >> n;
  vector<int> mask(n);
  int tail = 0;
  for (int(i) = (0); (i) <= ((1 << maxq) - 1); (i)++)
    if (__builtin_popcount(i) == 6) {
      mask[tail] = i;
      for (int(j) = (0); (j) <= ((maxq)-1); (j)++)
        if ((i & (1 << j)) == 0) q[j].emplace_back(tail);
      if (++tail == n) break;
    }
  for (int(i) = (0); (i) <= ((maxq)-1); (i)++)
    if (!q[i].empty()) ret[i] = ask(q[i]);
  vector<long long> ans(n);
  for (int(i) = (0); (i) <= ((n)-1); (i)++)
    for (int(j) = (0); (j) <= ((maxq)-1); (j)++)
      if (mask[i] & (1 << j)) ans[i] |= ret[j];
  cout << "!";
  for (auto x : ans) cout << ' ' << x;
  cout << endl;
}
