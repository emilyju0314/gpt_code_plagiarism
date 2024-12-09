#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using ull = unsigned long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vd = vector<double>;
using vvd = vector<vd>;
using vvvd = vector<vvd>;
using vs = vector<string>;
using vvs = vector<vs>;
using vc = vector<char>;
using vvc = vector<vc>;
using ii = pair<int, int>;
using vii = vector<ii>;
using vvii = vector<vii>;
using dd = pair<double, double>;
using vdd = vector<dd>;
using vvdd = vector<vdd>;
using Mii = map<int, int>;
using vMii = vector<Mii>;
using Si = set<int>;
using vSi = vector<Si>;
using vvSi = vector<vSi>;
vi a;
bool rec(int i, int j, int left, int right) {
  if (right == 0) {
    return left & 1;
  }
  if (left == 0) return right & 1;
  if (a[i] == a[j]) {
    return (left & 1) or (right & 1);
  }
  if (a[i] > a[j]) {
    if (left & 1) return true;
    return not rec(i, j - 1, left, right - 1);
  }
  if (right & 1) return true;
  return not rec(i + 1, j, left - 1, right);
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n;
  while (cin >> n) {
    a = vi(n);
    for (int& x : a) cin >> x;
    int left = 1;
    for (int i = 1; i < n; ++i) {
      if (a[i] > a[i - 1])
        left++;
      else
        break;
    }
    int right = 1;
    for (int i = n - 2; i >= 0; --i) {
      if (a[i] > a[i + 1])
        right++;
      else
        break;
    }
    bool guanya = rec(0, n - 1, left, right);
    cout << (guanya ? "Alice" : "Bob") << '\n';
  }
}
