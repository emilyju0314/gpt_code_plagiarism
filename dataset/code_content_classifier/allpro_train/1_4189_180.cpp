#include <bits/stdc++.h>
using namespace std;
const int INF = 1E9 + 7;
template <class C>
void mini(C& a4, C b4) {
  a4 = min(a4, b4);
}
template <class C>
void maxi(C& a4, C b4) {
  a4 = max(a4, b4);
}
vector<int> G[100007];
string s[100007], pat;
int pi[100007], k, n, w, res;
bool KMP(char c) {
  while (k && pat[k + 1] != c) k = pi[k];
  if (pat[k + 1] == c) k++;
  return (k == w);
}
void go(int x) {
  int state = k;
  for (__typeof((G[x]).begin()) i = ((G[x]).begin()); i != (G[x]).end(); ++i) {
    k = state;
    for (__typeof((s[*i]).begin()) j = ((s[*i]).begin()); j != (s[*i]).end();
         ++j)
      res += KMP(*j);
    go(*i);
  }
}
int main() {
  std::ios_base::sync_with_stdio(0);
  cout << setprecision(15) << fixed;
  cin >> n;
  for (int i = (2); i <= (n); ++i) {
    int x;
    cin >> x >> s[i];
    G[x].push_back(i);
  }
  cin >> pat;
  w = ((int)(pat).size());
  pat = "#" + pat + "$";
  for (int i = (2); i <= (w); ++i) {
    while (k && pat[k + 1] != pat[i]) k = pi[k];
    if (pat[k + 1] == pat[i]) k++;
    pi[i] = k;
  }
  for (int i = (2); i <= (w); ++i)
    if (pat[pi[i] + 1] == pat[i + 1]) pi[i] = pi[pi[i]];
  k = 0;
  go(1);
  cout << res << endl;
  return 0;
}
