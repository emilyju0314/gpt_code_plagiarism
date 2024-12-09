#include <bits/stdc++.h>
using namespace std;
const int limit = 1000000;
int n, k;
int amount[limit];
long long int sol;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int h;
    cin >> h;
    amount[h]++;
  }
  int c = 0;
  long long int s = 0;
  for (int h = limit - 1; h >= 1 and c < n; h--) {
    if (s + c + amount[h] > k or c + amount[h] == n) {
      if (c) sol++;
      c += amount[h];
      s = c;
    } else {
      c += amount[h];
      s += c;
    }
  }
  cout << sol << endl;
}
