#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, p[300005], i, x, ans;
  priority_queue<long long int, vector<long long int>, greater<long long int> >
      q;
  ans = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x;
    if (q.empty() == 0 && q.top() < x) {
      ans += (x - q.top());
      q.pop();
      q.push(x);
      q.push(x);
    } else {
      q.push(x);
    }
  }
  cout << ans;
  return 0;
}
