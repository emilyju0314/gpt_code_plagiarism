#include <bits/stdc++.h>
using namespace std;
long long power(long long b, long long e, long long m) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b % m, e / 2, m) % m;
  return power(b * b % m, e / 2, m);
}
long long power(long long b, long long e) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b, e / 2);
  return power(b * b, e / 2);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k, x, r;
    cin >> n >> k;
    vector<set<int>> v;
    v.resize(k);
    for (int i = 0; i < k; i++) {
      cin >> x;
      for (int j = 0; j < x; j++) {
        cin >> r;
        v[i].insert(r);
      }
    }
    cout << "? " << n << " ";
    for (int i = 1; i <= n; i++) {
      cout << i << " ";
    }
    cout << '\n' << flush;
    int globmax, z;
    cin >> globmax;
    int low = 1;
    int high = n;
    int cc = 1;
    while (high >= low) {
      if (high == low) break;
      int mid = (high + low) / 2;
      cout << "? " << mid - low + 1 << " ";
      for (int i = low; i <= mid; i++) cout << i << " ";
      cout << '\n' << flush;
      cin >> z;
      if (z == globmax) {
        high = mid;
      } else {
        low = mid + 1;
      }
      cc++;
    }
    assert(cc <= 11);
    int ans[k], ind;
    for (int i = 0; i < k; i++) {
      if (!v[i].count(high))
        ans[i] = globmax;
      else
        ind = i;
    }
    cout << "? " << n - (int)v[ind].size() << " ";
    for (int i = 1; i <= n; ++i)
      if (!v[ind].count(i)) cout << i << " ";
    cout << '\n' << flush;
    cin >> z;
    ans[ind] = z;
    cout << "! ";
    for (int i = 0; i < k; i++) cout << ans[i] << " ";
    cout << '\n' << flush;
    string zz;
    cin >> zz;
  }
  return 0;
}
