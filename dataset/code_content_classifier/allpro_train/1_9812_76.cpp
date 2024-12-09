#include <bits/stdc++.h>
using namespace std;
long long BIT[200010];
void update(long long val) {
  for (long long index = val; index <= 200000; index += (index & (-index)))
    BIT[index]++;
}
long long query(long long val) {
  long long ans = 0;
  for (long long index = val; index > 0; index -= (index & (-index)))
    ans += BIT[index];
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  long long n;
  cin >> n;
  string s, r;
  cin >> s;
  r = s;
  reverse(r.begin(), r.end());
  stack<long long> recent[26];
  for (long long i = n - 1; i >= 0; i--) {
    recent[r[i] - 'a'].push(i + 1);
  }
  vector<long long> arr(n, 0);
  for (long long i = 0; i < n; i++) {
    arr[i] = recent[s[i] - 'a'].top();
    recent[s[i] - 'a'].pop();
  }
  long long ans = 0;
  for (long long i = n - 1; i >= 0; i--) {
    ans += query(arr[i]);
    update(arr[i]);
  }
  cout << ans;
}
