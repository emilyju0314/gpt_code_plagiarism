#include <bits/stdc++.h>
using namespace std;
int isDone[1000000];
int main() {
  int n, m;
  cin >> n >> m;
  int boy[n];
  int girl[m];
  for (int i = 0; i < n; i++) {
    cin >> boy[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> girl[i];
  }
  sort(boy, boy + n);
  sort(girl, girl + m);
  if (boy[n - 1] > girl[0] || (m == 1 && boy[n - 1] < girl[0])) {
    cout << -1 << endl;
    return 0;
  }
  long long ans = 0;
  for (int i = 0; i < n - 1; i++) {
    ans += (long long)boy[i];
  }
  ans = ans * (long long)m;
  for (int i = 0; i < m; i++) {
    ans += (long long)girl[i];
  }
  if (girl[0] > boy[n - 1]) {
    ans += (long long)(boy[n - 1] - boy[n - 2]);
  }
  cout << ans << endl;
}
