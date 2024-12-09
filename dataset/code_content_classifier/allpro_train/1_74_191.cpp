#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n, n) {
    auto c = vector<int>(n);
    for (int i = 0; i < n; ++i) {
      string w; cin >> w;
      c[i] = w.length();
    }
    auto s = vector<int>(n + 1, 0);
    auto phrase = vector<int>{5, 7, 5, 7, 7};
    for (int i = 0; i < n; ++i) s[i + 1] = s[i] + c[i];

    auto solve = [&]() {
      for (int i = 0; i < n; ++i) {
        int cur = i, nxt = n + 1;
        for (int j = 0; j < 5; ++j, cur = nxt) {
          nxt = distance(begin(s), find(begin(s), end(s), s[cur] + phrase[j]));
          if (nxt == n + 1) break;
          if (j == 4) return i + 1;
        }
      }
      return 0;
    };
    cout << solve() << endl;
  }
  return 0;
}

