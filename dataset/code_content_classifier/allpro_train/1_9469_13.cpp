#include <bits/stdc++.h>
using namespace std;
int main() {
  string first, second;
  cin >> first;
  cin >> second;
  int L = second.length();
  int ans = 200000;
  for (int i = 0; i < first.length(); i++) {
    int misMatch = 0;
    int left = max(0, L - (i + 1));
    for (int j = i; j >= max(0, i - L + 1); j--) {
      if (first[j] != second[L - (i - j) - 1]) misMatch++;
    }
    ans = min(ans, left + misMatch);
  }
  int L2 = first.size();
  for (int i = second.length() - 1; i >= 0; i--) {
    int misMatch = 0;
    int leftR = L - i - 1;
    int leftL = max(0, i - L2);
    for (int j = i; j >= max(i - L2, 0); j--) {
      if (second[j] != first[L2 - (i - j) - 1]) misMatch++;
    }
    ans = min(ans, leftR + leftL + misMatch);
  }
  cout << ans << endl;
  return 0;
}
