#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  unordered_map<int, map<int, int> > m1;
  unordered_map<int, int> m2;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    int numSteps = 0;
    while (a[i] > 0) {
      m2[a[i]]++;
      m1[a[i]][numSteps]++;
      a[i] /= 2;
      ++numSteps;
    }
  }
  long long target = 0;
  long long steps = INT_MAX;
  for (auto it : m2) {
    if (it.second >= k) {
      long long numSteps = 0;
      int nums = 0;
      auto it1 = m1[it.first].begin();
      while (nums < k) {
        long long tmp = min(k - nums, it1->second);
        numSteps += (tmp * it1->first);
        nums += tmp;
        it1++;
      }
      if (numSteps < steps) {
        steps = numSteps;
        target = it.first;
      }
    }
  }
  cout << steps << endl;
  return 0;
}
