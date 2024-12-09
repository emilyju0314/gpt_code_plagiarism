#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, k, a[maxn];
vector<int> ans;
long long sum;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  int partsum = sum / k;
  int tmp = 0, lastpos = 0;
  bool flag = false;
  for (int i = 1; i <= n; ++i) {
    tmp += a[i];
    if (tmp == partsum) {
      ans.push_back(i - lastpos);
      lastpos = i;
      tmp = 0;
    }
    if (tmp >= partsum) {
      flag = true;
      break;
    }
  }
  if (flag)
    cout << "No" << endl;
  else if (ans.size() * partsum != sum)
    cout << "No" << endl;
  else {
    cout << "Yes" << endl;
    for (auto s : ans) cout << s << " ";
  }
  return 0;
}
