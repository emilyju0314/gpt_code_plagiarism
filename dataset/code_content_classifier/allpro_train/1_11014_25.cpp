#include <bits/stdc++.h>
using namespace std;
bool check(map<int, int> t1, int maxi) {
  for (int i = 1; i <= maxi; i++) {
    if (t1.count(i) == 0 || t1[i] == 0) {
      return false;
    }
  }
  return true;
}
void Permutations(int n, vector<int> a, int maxi) {
  map<int, int> t1, t2;
  map<pair<int, int>, int> ans;
  int k = 0;
  for (int i = 0; i < maxi; i++) {
    t1[a[i]]++;
  }
  for (int i = maxi; i < n; i++) {
    t2[a[i]]++;
  }
  if (check(t1, maxi) && check(t2, n - maxi)) {
    k++;
    ans[{maxi, n - maxi}]++;
  }
  maxi = n - maxi;
  t1.clear();
  t2.clear();
  for (int i = 0; i < maxi; i++) {
    t1[a[i]]++;
  }
  for (int i = maxi; i < n; i++) {
    t2[a[i]]++;
  }
  if (check(t1, maxi) && check(t2, n - maxi)) {
    ans[{maxi, n - maxi}]++;
  }
  k = ans.size();
  cout << k << endl;
  if (k > 0) {
    for (auto it : ans) {
      pair<int, int> temp = it.first;
      cout << temp.first << " " << temp.second << endl;
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int maxi = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] > maxi) maxi = a[i];
    }
    Permutations(n, a, maxi);
  }
  return 0;
}
