#include <bits/stdc++.h>
using namespace std;
struct queries {
  int start;
  int end;
  int index;
};
int n;
int bucketsize;
long long int ans[1000010];
int nums[1000010];
int vals[1000010];
vector<queries> v;
bool comp(queries a, queries b) {
  if ((a.start / bucketsize) != (b.start / bucketsize))
    return (a.start / bucketsize) < (b.start / bucketsize);
  else
    return (a.end < b.end);
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  queries temp;
  int t;
  cin >> n >> t;
  bucketsize = 2 * sqrt(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  for (int i = 0; i < t; i++) {
    temp.index = i;
    cin >> temp.start;
    temp.start--;
    cin >> temp.end;
    temp.end--;
    v.push_back(temp);
  }
  sort(v.begin(), v.end(), comp);
  int start = 0, end = 0;
  long long int cval = nums[0];
  vals[nums[0]]++;
  for (int i = 0; i < t; i++) {
    while (v[i].start < start) {
      start--;
      cval += (2 * 1LL * vals[nums[start]] + 1) * nums[start];
      vals[nums[start]]++;
    }
    while (v[i].start > start) {
      cval -= (2 * 1LL * vals[nums[start]] - 1) * nums[start];
      vals[nums[start]]--;
      start++;
    }
    while (v[i].end > end) {
      end++;
      cval += (2 * 1LL * vals[nums[end]] + 1) * nums[end];
      vals[nums[end]]++;
    }
    while (v[i].end < end) {
      cval -= (2 * 1LL * vals[nums[end]] - 1) * nums[end];
      vals[nums[end]]--;
      end--;
    }
    ans[v[i].index] = cval;
  }
  for (int i = 0; i < t; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}
