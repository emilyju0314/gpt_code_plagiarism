#include <bits/stdc++.h>
using namespace std;
struct node {
  long long int p, c, i;
} var;
bool fun(node a, node b) { return a.p < b.p; }
int main() {
  int n, k;
  cin >> n >> k;
  vector<node> a(n);
  vector<long long int> ans(n);
  unordered_map<long long int, int> ma;
  for (int i = 0; i < n; i++) {
    cin >> a[i].p;
    a[i].i = i;
    a[i].c = 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i].c;
    ma[a[i].c] = 0;
  }
  sort(a.begin(), a.end(), fun);
  long long int presum = 0, mini = a[0].c;
  set<long long int> s;
  for (int i = 0; i <= min(k, n - 1); i++) {
    s.insert(a[i].c);
    if (a[i].c < mini) mini = a[i].c;
    presum = presum + a[i].c;
    ma[a[i].c] = ma[a[i].c] + 1;
    ans[a[i].i] = presum;
  }
  presum = presum - mini;
  set<long long int>::iterator it = s.begin();
  if (ma[*it] == 1) {
    s.erase(it);
  }
  ma[mini] -= 1;
  for (int i = k + 1; i < n; i++) {
    it = s.begin();
    ans[a[i].i] = presum + a[i].c;
    if (*it < a[i].c) {
      presum = presum - *it + a[i].c;
      if (ma[*it] == 1) {
        s.erase(it);
      }
      ma[*it] = ma[*it] - 1;
      s.insert(a[i].c);
      ma[a[i].c] += 1;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
