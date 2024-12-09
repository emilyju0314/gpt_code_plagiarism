#include <bits/stdc++.h>
using namespace std;
int n;
int x[1 << 17], k[1 << 17];
int cnt[1 << 17];
int info[1 << 17];
int main() {
  cnt[0] = 1 << 30;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> k[i];
  }
  for (int i = 1; i <= n; i++) {
    if (x[i] > info[k[i]]) {
      cout << "NO" << endl;
      return 0;
    }
    if (x[i] < info[k[i]]) {
      continue;
    }
    if (info[k[i]] == x[i]) info[k[i]]++;
  }
  cout << "YES" << endl;
  return 0;
}
