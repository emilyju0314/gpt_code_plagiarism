#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    string a;
    cin >> n >> k >> a;
    vector<long long> xx;
    int cnt = 0, i, j;
    for (i = 0; i < n; i++) {
      if (a[i] == '0') {
        xx.push_back(cnt);
        cnt = 0;
      } else
        cnt++;
    }
    string ans;
    for (i = 0; i < xx.size() && k; i++) {
      int tmp = min(xx[i], k);
      xx[i] -= tmp;
      k -= tmp;
      if (i + 1 < xx.size()) xx[i + 1] += tmp;
    }
    for (i = 0; i < xx.size(); i++) {
      for (j = 1; j <= xx[i]; j++) ans.push_back('1');
      ans.push_back('0');
    }
    j = n - ans.size();
    for (i = 1; i <= j; i++) ans.push_back('1');
    cout << ans;
    printf("\n");
  }
  return 0;
}
