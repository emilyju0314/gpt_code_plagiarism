#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;
using vvii = vector<vii>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vd = vector<double>;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    ll sum = 0.5 * n * (n + 1);
    int p2 = 1;
    while (p2 <= n) {
      sum -= 2 * p2;
      p2 *= 2;
    }
    cout << sum << '\n';
  }
}
