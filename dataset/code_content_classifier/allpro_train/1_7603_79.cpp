#include <bits/stdc++.h>
using namespace std;

int main() {
  int T, K;
  cin >> K >> T;

  vector<int> v(T);
  for (auto& i : v) cin >> i;

  sort(v.begin(), v.end());

  cout << max(0, v[T-1] - (K - v[T-1] + 1)) << endl;

  return 0;
}
