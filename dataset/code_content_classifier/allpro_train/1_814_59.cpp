#include <bits/stdc++.h>
using namespace std;
const long long LLINF = 1LL << 61;
const int INF = 1e9;
const double EPS = 1e-9;
const int N = 111;
int n, cnt[N], pile[N][N];
int main() {
  cin >> n;
  int sum = 0, best = 0;
  vector<int> mid;
  for (int i = (int)(1), _b = (int)(n); i <= _b; ++i) {
    cin >> cnt[i];
    for (int j = (int)(1), _b = (int)(cnt[i]); j <= _b; ++j) {
      cin >> pile[i][j];
      sum += pile[i][j];
    }
    for (int j = (int)(1), _b = (int)(cnt[i] / 2); j <= _b; ++j)
      best += pile[i][j];
    if (cnt[i] % 2 == 1) mid.push_back(pile[i][cnt[i] / 2 + 1]);
  }
  sort(mid.rbegin(), mid.rend());
  for (int i = 0; i < mid.size(); i += 2) best += mid[i];
  printf("%d %d\n", best, sum - best);
  return 0;
}
