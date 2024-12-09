#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d;
  int sum = 0;
  cin >> n >> d;
  vector<int> V(n);
  for (size_t i = 0; i < n; ++i) {
    cin >> V[i];
    sum += V[i];
  }
  sort(V.begin(), V.end());
  vector<bool> S(sum + 1, false);
  S[0] = true;
  for (int i = 0; i < V.size(); ++i) {
    for (int j = sum; j > 0; --j) {
      int t = j - V[i];
      if (t < 0) break;
      if (S[t]) S[j] = true;
    }
  }
  int ret = 0, ssum = 0;
  while (true) {
    int next = -1;
    for (int i = ssum + 1; i <= min(ssum + d, sum); ++i) {
      if (S[i]) next = i;
    }
    if (next < 0) break;
    ssum = next;
    ret++;
  }
  cout << ssum << " ";
  cout << ret << endl;
  return 0;
}
