#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n;
int a[N];
bool used[N];
int main() {
  int test;
  cin >> test;
  while (test--) {
    cin >> n;
    for (int i = 0; i < 2 * n; ++i) {
      cin >> a[i];
    }
    memset(used, false, N);
    vector<int> ans;
    for (int i = 0; i < 2 * n; ++i) {
      if (used[a[i]] == false) {
        ans.push_back(a[i]);
        used[a[i]] = true;
      }
    }
    for (int i = 0; i < (int)ans.size(); ++i) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
