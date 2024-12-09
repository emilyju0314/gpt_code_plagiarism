#include <bits/stdc++.h>
using namespace std;
const int M = 100005;
int a[M], stress[M];
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  int count = 0;
  for (int i = 1; i <= n - 1; i++) count += (a[i] != a[i - 1]);
  vector<int> v;
  v.push_back(a[0]);
  for (int i = 1; i <= n - 1; i++) {
    int x = v[v.size() - 1];
    if (a[i] == x) continue;
    v.push_back(a[i]);
  }
  for (int i = 0; i < v.size(); i++) {
    if (!i && i + 1 < v.size()) {
      stress[v[i]]++;
      continue;
    }
    if (i && i == v.size() - 1) {
      stress[v[i]]++;
      continue;
    }
    if (v[i - 1] == v[i + 1])
      stress[v[i]] += 2;
    else
      stress[v[i]]++;
  }
  int ans = 1e9, res;
  for (int i = 1; i <= k; i++) {
    int x = count - stress[i];
    if (x < ans) {
      ans = x;
      res = i;
    }
  }
  cout << res;
  return 0;
}
