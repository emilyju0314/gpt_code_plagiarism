#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long a[n], i;
    long long ans = 1e18;
    vector<long long> vp;
    vector<long long> vn;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] < 0)
        vn.push_back(a[i]);
      else
        vp.push_back(a[i]);
    }
    sort(vp.begin(), vp.end());
    sort(vn.begin(), vn.end(), greater<long long>());
    long long temp = 0;
    long long prev = 0;
    long long x = vp.size();
    long long c = x % k;
    long long q = k;
    for (i = 0; i < x; i++) {
      if (c != -1 && c != 0) {
        if (q == 0) {
          temp += prev;
          prev = 0;
          q = k;
        }
        temp += abs(vp[i] - prev);
        prev = vp[i];
        c--;
        q--;
      } else {
        if (c == 0) {
          q = k;
          c = -1;
          temp += abs(prev);
          prev = 0;
        }
        if (q == 0) {
          temp += prev;
          prev = 0;
          q = k;
        }
        temp += abs(vp[i] - prev);
        prev = vp[i];
        q--;
      }
    }
    long long temp1 = 0, prev1 = 0;
    x = vn.size();
    c = x % k;
    q = k;
    for (i = 0; i < x; i++) {
      if (c != -1 && c != 0) {
        if (q == 0) {
          temp1 += prev1;
          prev1 = 0;
          q = k;
        }
        temp1 += abs(vn[i] - prev1);
        prev1 = vn[i];
        c--;
        q--;
      } else {
        if (c == 0) {
          q = k;
          c = -1;
          temp1 += abs(prev1);
          prev1 = 0;
        }
        if (q == 0) {
          temp1 += abs(prev1);
          prev1 = 0;
          q = k;
        }
        temp1 += abs(vn[i] - prev1);
        prev1 = vn[i];
        q--;
      }
    }
    if (vn.size() == 0) {
      ans = temp;
    } else if (vp.size() == 0) {
      ans = temp1;
    } else {
      ans = temp + prev + temp1;
      ans = min(ans, temp1 + abs(prev1) + temp);
    }
    cout << ans << "\n";
  }
  return 0;
}
