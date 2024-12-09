#include <bits/stdc++.h>
using namespace std;
int ans[100005];
pair<int, int> arr[100005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, i, cur = -1, temp = -1;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> arr[i].first;
    arr[i].second = i;
  }
  sort(arr, arr + n);
  for (i = 0; i < n; i++) {
    if (i == 0) {
      ans[arr[i].second] = -1;
      cur = arr[i].second;
      continue;
    }
    if (arr[i].first == arr[i - 1].first) {
      ans[arr[i].second] = max(cur - arr[i].second - 1, -1);
      temp = max(temp, arr[i].second);
    } else {
      cur = max(cur, temp);
      ans[arr[i].second] = max(cur - arr[i].second - 1, -1);
      cur = temp = max(cur, arr[i].second);
    }
  }
  for (i = 0; i < n; i++) cout << ans[i] << ' ';
  cout << '\n';
  return 0;
}
