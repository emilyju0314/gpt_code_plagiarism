#include <bits/stdc++.h>
using namespace std;
bool mark[100];
void f(long long x, long long cnt, long long sz) {
  if (cnt == 0 || sz == 0) return;
  if (cnt <= sz / 2) {
    mark[x] = true;
    cout << x << ' ';
    f(x + 1, cnt, sz / 2);
  } else {
    cnt -= sz / 2;
    f(x + 1, cnt, sz / 2);
  }
}
int main() {
  long long n, m;
  cin >> n >> m;
  f(1, m, (1LL << (n - 1)));
  for (int i = n; i >= 1; i--)
    if (!mark[i]) cout << i << ' ';
  cout << endl;
  return 0;
}
