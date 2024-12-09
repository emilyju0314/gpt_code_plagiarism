#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i, j = 0, m, pos = 11;
  cin >> n >> k;
  set<int> se;
  vector<char> str(n);
  string ans;
  char x;
  vector<int> res;
  int arr[n], brr[n];
  for (i = 0; i < n; i++) cin >> arr[i];
  for (i = 0; i < n; i++) cin >> brr[i];
  for (i = 0; i < n; i++) {
    if (se.find(arr[i]) != se.end())
      se.erase(arr[i]);
    else
      se.insert(arr[i]);
    if (se.find(brr[i]) != se.end())
      se.erase(brr[i]);
    else
      se.insert(brr[i]);
    if (se.size() == 0) res.push_back(i);
  }
  m = res.size();
  if (m < k)
    cout << "NO" << endl;
  else {
    k--;
    cout << "YES" << endl;
    for (i = 0; i < m; i++) {
      x = 'a' + min(k, i);
      for (; j <= res[i]; j++) str[arr[j] - 1] = x;
    }
    for (i = 0; i < n; i++) cout << str[i];
    cout << endl;
  }
  return 0;
}
