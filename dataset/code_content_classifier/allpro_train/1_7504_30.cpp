#include <bits/stdc++.h>
using namespace std;
int d[200010], a[200010];
map<int, int> m;
vector<int> v;
int main() {
  int n, k = 0, ind;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i + 1];
  for (int i = 1; i < n + 1; i++) d[i] = m[a[i] - 1] + 1, m[a[i]] = d[i];
  for (int i = 1; i < n + 1; i++) k = max(k, d[i]);
  for (int i = 1; i < n + 1; i++)
    if (d[i] == k) ind = a[i];
  cout << k << endl;
  for (int i = 0; i < n; i++) {
    int x = n - i;
    if (a[x] == ind) ind--, v.push_back(x);
  }
  for (int i = 0; i < k; i++) cout << v[k - 1 - i] << " ";
}
