#include <bits/stdc++.h>
using namespace std;
double PI = 3.1415926535897932384626433832795;
int arr[100004], ans[100005], vis[100005];
int main() {
  int n, m, d, ans = 0;
  cin >> n >> d;
  for (int i = 0; i < n; cin >> arr[i], ++i)
    ;
  sort(arr, arr + n);
  cin >> m;
  int i = 0;
  while (m && i < n) {
    ans += arr[i];
    ++i;
    --m;
  }
  while (m) {
    ans -= d;
    --m;
  }
  cout << ans;
  return 0;
}
