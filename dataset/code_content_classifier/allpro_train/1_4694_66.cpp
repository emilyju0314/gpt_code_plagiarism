#include <bits/stdc++.h>
using namespace std;
pair<int, int> arr[200005];
long long loc[200005];
void solve(long long left, long long right) {
  if (left > right) return;
  int mid = (left + right) / 2;
  arr[mid].first = left - right;
  arr[mid].second = mid;
  solve(mid + 1, right);
  solve(left, mid - 1);
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    solve(1, n);
    sort(arr + 1, arr + n + 1);
    for (long long i = 1; i <= n; i++) loc[arr[i].second] = i;
    for (long long i = 1; i <= n; ++i) cout << loc[i] << ' ';
    cout << "\n";
  }
}
