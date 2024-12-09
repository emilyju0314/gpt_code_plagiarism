#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    long long int sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      sum += arr[i];
      if (arr[i] == 0) count++;
    }
    long long int ans = 0;
    ans = count;
    sum += count;
    if (sum == 0) {
      ans += 1;
    }
    cout << ans << endl;
  }
}
