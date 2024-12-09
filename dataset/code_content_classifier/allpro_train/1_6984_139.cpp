#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<pair<int, int> > w;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    w.push_back(make_pair(temp, i));
  }
  sort(w.begin(), w.end());
  stack<int> introvert;
  string s;
  cin >> s;
  int t = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (s[i] == '0') {
      introvert.push(w[t].second);
      cout << w[t].second + 1 << " ";
      t++;
    } else {
      cout << introvert.top() + 1 << " ";
      introvert.pop();
    }
  }
  return 0;
}
