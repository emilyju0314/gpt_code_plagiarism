#include <bits/stdc++.h>
using namespace std;
vector<pair<bool, int> > nums;
int main() {
  int n, k, q;
  cin >> n >> k;
  int N = n;
  int K = n / k;
  int distinctCards = 0;
  nums.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i].second;
    nums[i].first = false;
  }
  long double minAns = INT_MAX;
  long double maxAns = INT_MIN;
  cin >> q;
  while (q--) {
    long double sum = 0;
    for (int j = 0; j < K; j++) {
      int a;
      cin >> a;
      a--;
      if (nums[a].first) {
        sum = -1;
        continue;
      }
      nums[a].first = true;
      N--;
      sum += nums[a].second;
    }
    if (sum >= 0) {
      distinctCards++;
      sum /= K;
      if (sum < minAns) minAns = sum;
      if (sum > maxAns) maxAns = sum;
    }
  }
  if (distinctCards < k && N >= K) {
    sort(nums.begin(), nums.end());
    long double sum = 0;
    for (int i = 0; i < K; i++) sum += nums[N - 1 - i].second;
    sum /= K;
    if (sum > maxAns) maxAns = sum;
    sum = 0;
    for (int i = 0; i < K; i++) sum += nums[i].second;
    sum /= K;
    if (sum < minAns) minAns = sum;
  }
  printf("%.10lf %.10lf", minAns, maxAns);
  return 0;
}
