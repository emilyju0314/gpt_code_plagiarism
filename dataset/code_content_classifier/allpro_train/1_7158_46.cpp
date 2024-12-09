#include <bits/stdc++.h>
using std::endl;
using std::string;
int main(void) {
  using std::cin;
  using std::cout;
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  string S;
  cin >> S;
  const int N = S.size();
  int prettyCnt = 0;
  for (int left = 0; left < N - 1; ++left) {
    int mn = 0, mx = 0;
    for (int right = left; right < N; ++right) {
      assert(mx >= 0);
      assert(mn >= 0);
      assert(mn <= mx);
      const char& ch = S[right];
      if (ch == '(') {
        ++mn;
        ++mx;
      } else if (ch == ')') {
        --mx;
        if (mx == -1) break;
        --mn;
        if (mn == -1) {
          if (mx == 0) break;
          mn = 1;
        } else if (mn == 0) {
          ++prettyCnt;
        }
      } else {
        assert(ch == '?');
        ++mx;
        --mn;
        if (mn == -1) {
          mn = 1;
        } else if (mn == 0) {
          ++prettyCnt;
        }
      }
    }
  }
  cout << prettyCnt << endl;
  return 0;
}
