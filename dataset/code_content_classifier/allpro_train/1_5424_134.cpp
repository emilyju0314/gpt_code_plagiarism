#include <bits/stdc++.h>
#pragma GCC target("avx,tune=native")
using namespace std;
int n, s1, s2, positions[100013];
int dp[100013];
int maxSeparation;
bool within(int a, int b) { return abs(a - b) <= maxSeparation; }
bool windowGood(const multiset<int> &window, int start) {
  return window.size() == 0 ||
         within(*window.begin(), start) && within(*(prev(window.end())), start);
}
bool solve() {
  set<int> possibleJumps;
  possibleJumps.insert(s1);
  possibleJumps.insert(s2);
  for (int i = 2; i < n; i++) {
    auto it = possibleJumps.begin();
    while (abs(*it - positions[i]) > maxSeparation) {
      possibleJumps.erase(it);
      if (possibleJumps.size() == 0) return 0;
      it = possibleJumps.begin();
    }
    it = prev(possibleJumps.end());
    while (abs(*it - positions[i]) > maxSeparation) {
      possibleJumps.erase(it);
      if (possibleJumps.size() == 0) return 0;
      it = prev(possibleJumps.end());
    }
    possibleJumps.insert(positions[i]);
  }
  return 1;
}
int main() {
  if (fopen("FILENAME.in", "r")) {
    freopen("FILENAME.in", "r", stdin);
    freopen("FILENAME.out", "w", stdout);
  }
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> s1 >> s2;
  positions[0] = s1;
  positions[1] = s2;
  for (int i = 0; i < n; i++) {
    cin >> positions[i + 2];
  }
  n += 2;
  int start = abs(s2 - s1);
  int end = 1000000000;
  while (start <= end) {
    int mid = (start + end) / 2;
    maxSeparation = mid;
    bool good = solve();
    if (good) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  cout << start << endl;
}
