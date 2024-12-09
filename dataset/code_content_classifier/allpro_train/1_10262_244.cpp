#include <bits/stdc++.h>
using namespace std;
vector<bool> visited(1000007, false);
vector<long long int> data;
struct A {
  long long int a, b;
  A(int x, int y) {
    a = x;
    b = y;
  }
};
bool operator<(A x, A y) { return x.b < y.b; }
vector<A> info;
int main() {
  long long int a, b, p, q, r, s, n, m, x, y, avg, sum, mx, mn;
  int cnt, z, c;
  bool ys, no;
  cin >> n >> r >> avg;
  sum = 0;
  for (int j = 0; j < n; j++) {
    scanf("%lld", &a);
    scanf("%lld", &b);
    sum += a;
    info.push_back(A(a, b));
  }
  x = (n * avg) - sum;
  if (x <= 0) {
    cout << "0\n";
    return 0;
  }
  sort(info.begin(), info.end());
  long long ans = 0;
  for (auto it : info) {
    p = it.a;
    q = it.b;
    s = (r - p);
    s = min(x, s);
    ans += s * q;
    x -= s;
    if (x == 0) {
      break;
    }
  }
  cout << ans << endl;
}
