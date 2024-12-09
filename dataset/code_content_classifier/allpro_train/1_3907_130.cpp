#include <bits/stdc++.h>
using namespace std;
double pi = 3.141592653589793238462;
string numkey = "0123456789";
string uni = "abcdefghijklmnopqrstuvwxyz";
long long int dx[4] = {0, 0, 1, -1};
long long int dy[4] = {1, -1, 0, 0};
long long int INF = (1LL << 62);
void increase_bit(long long int n, long long int cnt[]) {
  long long int p = 0;
  while (n > 0) {
    if (n & 1) cnt[p]++;
    p++;
    n = n >> 1;
  }
}
signed main() {
  long long int n;
  cin >> n;
  stack<long long int> s;
  s.push(1);
  long long int great = 1LL << 32;
  long long int ans = 0;
  for (long long int i = 0; i < n; i++) {
    string p;
    cin >> p;
    if (p == "for") {
      long long int x;
      cin >> x;
      s.push(min(great, s.top() * x));
    } else if (p == "end") {
      s.pop();
    } else if (p == "add") {
      ans += s.top();
    }
    if (ans >= great) {
      cout << "OVERFLOW!!!";
      return 0;
    }
  }
  cout << ans;
}
