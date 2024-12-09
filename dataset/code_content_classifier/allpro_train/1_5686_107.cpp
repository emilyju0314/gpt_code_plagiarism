#include <bits/stdc++.h>
using namespace std;
const double eps = 1.0e-10;
const double EPS = 1.0e-4;
const int turn[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
long long Mod = 1000000007;
set<int> need;
map<int, bool> mp[200005];
vector<int> ans;
int main() {
  long long n, k;
  cin >> n >> k;
  long long cnt = 0;
  for (long long i = 61; i >= 0; i--) {
    if ((1LL << i) & n) {
      cnt = i;
      break;
    }
  }
  if (k == 1) {
    cout << n << endl;
  } else {
    cout << (1LL << (cnt + 1)) - 1 << endl;
  }
  return 0;
}
