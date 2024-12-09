#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  bitset<32> a(n);
  vector<int> nums;
  for (int i = 0; i < 32; ++i) {
    if (a[i]) {
      nums.push_back(i);
    }
  }
  for (int i = 0; i < nums.size() && nums.size() < k; ++i) {
    while (nums[i] != 0 && nums.size() < k) {
      --nums[i];
      nums.push_back(nums[i]);
    }
  }
  if (nums.size() != k) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  for (int& i : nums) cout << (1 << i) << ' ';
}
