#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  map<int, int> count;
  int MAX = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    count[a]++;
    MAX = max(MAX, count[a]);
  }
  cout << ((int)count.size()) * ceil((double)MAX / k) * k - n;
  return 0;
}
