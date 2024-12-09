#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int MAXN = 1000000 + 100;
const int MOD = 1000007;
const int dir[][2] = {{1, 0}, {0, 1}};
int cases = 0;
set<int> s, ans;
int arr[MAXN];
int f[MAXN];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    set<int> ss;
    set<int>::iterator it = s.begin();
    for (; it != s.end(); it++) ss.insert(arr[i] | *it);
    ss.insert(arr[i]);
    s = ss;
    ans.insert(ss.begin(), ss.end());
  }
  cout << (int)ans.size() << endl;
  return 0;
}
