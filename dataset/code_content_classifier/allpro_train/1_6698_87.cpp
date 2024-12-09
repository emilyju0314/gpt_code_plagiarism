#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int n, m, k, x;
map<int, int> mps;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 0; i < (n); ++i) {
    cin >> x;
    --mps[-x];
  }
  for (int i = 0; i < (m); ++i) {
    cin >> x;
    ++mps[-x];
  }
  map<int, int>::iterator it;
  int sum = 0;
  for (it = mps.begin(); it != mps.end(); ++it) {
    if (it->second == 0) continue;
    sum += it->second;
    if (sum < 0) break;
  }
  if (sum < 0)
    puts("YES");
  else
    puts("NO");
  return 0;
}
