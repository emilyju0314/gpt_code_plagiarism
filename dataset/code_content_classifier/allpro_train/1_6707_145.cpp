#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;
  vector<pair<int, int> > V(N);
  for (int i = 0; i < N; ++i) cin >> V[i].first >> V[i].second;
  string s;
  for (int i = N - 1; i >= 0; --i) {
    int pos = 0;
    bool found = false;
    if (V[i].first == 1) {
      s.insert(0, ")");
      found = true;
    }
    for (int j = 0; j < s.size() && !found; ++j) {
      if (s[j] == '(')
        pos++;
      else
        pos--;
      if (pos == 0 && j + 2 >= V[i].first && j + 2 <= V[i].second) {
        s.insert(j + 1, ")");
        found = true;
      }
    }
    if (found)
      s.insert(0, "(");
    else
      goto HELL;
  }
  cout << s << "\n";
  return 0;
HELL:;
  cout << "IMPOSSIBLE\n";
  return 0;
}
