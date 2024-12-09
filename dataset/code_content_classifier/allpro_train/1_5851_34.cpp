#include <bits/stdc++.h>
using namespace std;
long int mod = 1e9 + 7;
int pos[200005];
int n, m;
bitset<200005> has;
string t, s;
bool isSubSequence(int range) {
  has.reset();
  for (int p = 1; p <= range; p++) has.set(pos[p] - 1);
  int j = 0;
  for (int i = 0; i < n && j < m; i++) {
    if (!has.test(i) && (s[j] == t[i])) j++;
  }
  return (j == m);
}
int main() {
  cin >> t >> s;
  int i;
  n = t.size();
  m = s.size();
  for (i = 1; i <= n; i++) cin >> pos[i];
  int ans = -1;
  int low = 0;
  int high = n;
  int mid;
  while (low <= high) {
    mid = (low + high) >> 1;
    if (isSubSequence(mid)) {
      low = mid + 1;
      ans = mid;
    } else
      high = mid - 1;
  }
  cout << (ans) << '\n';
}
