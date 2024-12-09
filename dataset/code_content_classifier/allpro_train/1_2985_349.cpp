#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
using ll = long long;
using pii = pair<int, int>;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, m;
  cin >> n >> m;
  ll choice;
  if (n & 1) {
    if (m > n / 2) {
      choice = max(m - 1, 1ll);
    } else {
      choice = min(m + 1, n);
    }
  } else {
    if (m > n / 2) {
      choice = max(m - 1, 1ll);
    } else {
      choice = min(m + 1, n);
    }
  }
  cout << choice << "\n";
  return 0;
}
