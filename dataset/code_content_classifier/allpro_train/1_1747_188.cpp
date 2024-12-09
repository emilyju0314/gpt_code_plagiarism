#include <bits/stdc++.h>
using namespace std;
vector<int> subset;
vector<bool> is_in;
int n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int count_l = 0, count_r = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'L') {
      ++count_l;
    } else {
      ++count_r;
    }
  }
  cout << count_l + count_r + 1;
}
