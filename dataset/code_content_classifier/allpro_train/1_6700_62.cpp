#include <bits/stdc++.h>
using namespace std;
long long head[100005];
long long memory[100005];
int n, m;
bool possible(long long t) {
  int curr = 1;
  for (int i = 1; i <= n; i++) {
    long long headloc = head[i];
    if (headloc <= memory[curr]) {
      headloc += t;
      while (headloc >= memory[curr] && curr <= m) curr++;
    } else {
      if (headloc - t > memory[curr]) return false;
      long long d = headloc - memory[curr];
      long long next = max(headloc + (t - d) / 2, headloc + (t - 2 * d));
      headloc = next;
      while (headloc >= memory[curr] && curr <= m) curr++;
    }
    if (curr == m + 1) return true;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> head[i];
  for (int i = 1; i <= m; i++) cin >> memory[i];
  long long start = 0;
  long long endi = 20000000000;
  while (start < endi) {
    long long mid = (start + endi) / 2;
    if (possible(mid))
      endi = mid;
    else
      start = mid + 1;
  }
  cout << endi;
}
