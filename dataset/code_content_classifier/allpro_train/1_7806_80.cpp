#include <bits/stdc++.h>
using namespace std;
struct SaNode {
  int length, link, nrAp;
  int sons[26];
};
SaNode sa[2 * 100005];
int last = 0, nNodes = 0, ord[2 * 100005];
long long ans;
string s;
void addToSa(int c) {
  int node = (++nNodes);
  int p;
  sa[node].length = sa[last].length + 1;
  sa[node].nrAp = 1;
  for (p = last; p >= 0 && !sa[p].sons[c]; p = sa[p].link) sa[p].sons[c] = node;
  if (p < 0) {
    last = node;
    return;
  }
  int q = sa[p].sons[c];
  if (sa[p].length + 1 == sa[q].length)
    sa[node].link = q;
  else {
    int clone = (++nNodes);
    sa[clone].length = sa[p].length + 1;
    for (; p >= 0 && sa[p].sons[c] == q; p = sa[p].link) sa[p].sons[c] = clone;
    for (int i = 0; i < 26; ++i) sa[clone].sons[i] = sa[q].sons[i];
    sa[clone].link = sa[q].link;
    sa[q].link = sa[node].link = clone;
  }
  last = node;
}
long long f(int x) { return 1LL * x * (x + 1) / 2; }
void calcNrAp() {
  for (int i = 1; i <= nNodes; ++i) ord[i] = i;
  sort(ord + 1, ord + nNodes + 1,
       [&](int a, int b) { return sa[a].length > sa[b].length; });
  for (int i = 1; i <= nNodes; ++i) {
    int x = ord[i];
    sa[sa[x].link].nrAp += sa[x].nrAp;
    int numSubstrings = sa[x].length - sa[sa[x].link].length;
    ans += f(sa[x].nrAp) * numSubstrings;
  }
}
int main() {
  ios::sync_with_stdio(0);
  sa[0].link = -1;
  cin >> s;
  for (char c : s) addToSa(c - 'a');
  calcNrAp();
  cout << ans << "\n";
  return 0;
}
