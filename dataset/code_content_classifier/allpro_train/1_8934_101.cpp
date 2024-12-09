#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    int l_limit = n * (a - b);
    int r_limit = n * (a + b);
    if (l_limit <= c + d && c - d <= r_limit)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}
