#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
bool how[maxn];
int ind[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie();
  int n, a;
  cin >> n;
  int fix[n];
  for (int i = 0; i < n; i++) {
    cin >> a;
    ind[a] = i;
    fix[i] = a;
  }
  for (int i = n - 1; i > 0; i--) {
    bool beat = false;
    for (int x = i; x <= n; x += i) {
      if (ind[i] - x > -1) {
        if (fix[ind[i] - x] > i && !how[fix[ind[i] - x]]) {
          beat = true;
          break;
        }
      }
      if (ind[i] + x < n) {
        if (fix[ind[i] + x] > i && !how[fix[ind[i] + x]]) {
          beat = true;
          break;
        }
      }
    }
    how[i] = beat;
  }
  for (int i = 0; i < n; i++) {
    cout << (!how[fix[i]] ? "B" : "A");
  }
  return 0;
}
