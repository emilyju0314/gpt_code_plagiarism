#include <bits/stdc++.h>
using namespace std;
int n;
int m[1123];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> m[i];
  vector<int> res;
  long long best = 0;
  for (int k = 0; k < n; k++) {
    vector<int> a;
    for (int i = 0; i < n; i++) a.push_back(m[i]);
    for (int i = k - 1; i >= 0; i--) a[i] = min(a[i + 1], m[i]);
    for (int i = k + 1; i < n; i++) a[i] = min(a[i - 1], m[i]);
    long long sum = 0;
    for (int v : a) sum += v;
    if (sum > best) {
      best = sum;
      res = a;
    }
  }
  for (int v : res) cout << v << " ";
}
