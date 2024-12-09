#include <bits/stdc++.h>
using namespace std;
const int MAX_COUNT = 1e5;
int data[MAX_COUNT];
int main() {
  ios::sync_with_stdio(false);
  long long n;
  cin >> n;
  long long ans = 0;
  for (int i = 1; i < (1000000); ++i) {
    long long min_cards = 1.5 * i * i + 0.5 * i;
    if (min_cards > n) {
      break;
    }
    if ((n - min_cards) % 3 == 0) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
