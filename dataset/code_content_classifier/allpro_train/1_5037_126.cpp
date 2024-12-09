#include <bits/stdc++.h>
using namespace std;
void init() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  init();
  int n;
  cin >> n;
  vector<int> arr(n), ans(n);
  for (int i = 0; i < n; ++i) cin >> arr[i];
  sort(begin(arr), end(arr));
  ans[0] = 1;
  for (int i = 1; i < n; ++i) ans[i] = arr[i - 1];
  if (arr[n - 1] == 1) ans[n - 1] = 2;
  for (int i = 0; i < n; ++i) cout << ans[i] << " ";
}
