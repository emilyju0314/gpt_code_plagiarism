#include <bits/stdc++.h>
using namespace std;
long long n, l, r, x;
long long arr[20];
int ans = 0;
void solve(int z) {
  int i = 0;
  vector<int> v;
  while (z) {
    if (z % 2) v.push_back(arr[i]);
    i++;
    z /= 2;
  }
  int c = v.size();
  long long sum = 0;
  for (int i = 0; i < c; i++) sum += v[i];
  if (c < 2) return;
  if (v[c - 1] - v[0] >= x)
    if (sum <= r && sum >= l) ans++;
}
int main() {
  cin >> n >> l >> r >> x;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  for (int i = 3; i < pow(2, n); i++) {
    solve(i);
  }
  cout << ans;
  return 0;
}
