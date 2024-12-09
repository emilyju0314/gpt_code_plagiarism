#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long double PI = 3.14159265358979323846;
const long double EPS = 0.000000001;
const long long MD_7 = 1000000007;
const long long MD_9 = 1000000009;
const long long MD = 228228227;
const long long INF = INT64_MAX;
const long long K = 26;
struct Node {
  long long son[K];
  long long go[K];
  long long parent;
  long long suffLink;
  long long up;
  char charToParent;
  multiset<long long> leaves;
  Node() {
    suffLink = 0;
    up = 0;
    for (long long i = 0; i < (K); ++i) {
      son[i] = 0;
      go[i] = 0;
    }
  }
};
Node* aho = new Node[300010];
Node help;
long long sz = 2;
vector<long long> pos;
vector<long long> dang;
long long getSuffLink(long long v);
long long getLink(long long v, char c);
long long gerUp(long long v);
long long getSuffLink(long long v) {
  if (aho[v].suffLink == 0) {
    if (v == 1 || aho[v].parent == 1) {
      aho[v].suffLink = 1;
    } else {
      aho[v].suffLink =
          getLink(getSuffLink(aho[v].parent), aho[v].charToParent);
    }
  }
  return aho[v].suffLink;
}
long long getLink(long long v, char c) {
  if (aho[v].go[c] == 0) {
    if (aho[v].son[c])
      aho[v].go[c] = aho[v].son[c];
    else if (v == 1)
      aho[v].go[c] = 1;
    else
      aho[v].go[c] = getLink(getSuffLink(v), c);
  }
  return aho[v].go[c];
}
long long getUp(long long v) {
  if (aho[v].up == 0) {
    if (!aho[getSuffLink(v)].leaves.empty() > 0)
      aho[v].up = getSuffLink(v);
    else if (getSuffLink(v) == 1)
      aho[v].up = 1;
    else
      aho[v].up = getUp(getSuffLink(v));
  }
  return aho[v].up;
}
long long addString(string& s1, long long patternNumber) {
  long long cur = 1;
  long long n = (long long)(s1.size());
  for (char c1 : s1) {
    long long c = c1 - 'a';
    if (aho[cur].son[c] == 0) {
      long long q = sz++;
      aho[q].parent = cur;
      aho[q].charToParent = c;
      aho[cur].son[c] = q;
    }
    cur = aho[cur].son[c];
  }
  aho[cur].leaves.insert(0);
  return cur;
}
long long processText(string& t) {
  long long v = 1;
  long long ans = -1;
  for (long long i = 0; i < (long long)(t.size()); i++) {
    char c = t[i] - 'a';
    v = getLink(v, c);
    long long v1 = v;
    if (!aho[v1].leaves.empty()) {
      ans = max(ans, *aho[v1].leaves.rbegin());
    }
    while (v1 != 1) {
      v1 = getUp(v1);
      if (!aho[v1].leaves.empty()) {
        ans = max(ans, *aho[v1].leaves.rbegin());
      }
    }
  }
  return ans;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  pos.resize(n);
  dang.resize(n);
  for (long long i = 0; i < (n); ++i) {
    string s;
    cin >> s;
    long long q = addString(s, i);
    pos[i] = q;
  }
  while (m--) {
    long long tp;
    cin >> tp;
    if (tp == 1) {
      long long i, x;
      cin >> i >> x;
      aho[pos[i - 1]].leaves.erase(aho[pos[i - 1]].leaves.find(dang[i - 1]));
      dang[i - 1] = x;
      aho[pos[i - 1]].leaves.insert(dang[i - 1]);
    } else {
      string s;
      cin >> s;
      cout << processText(s) << '\n';
    }
  }
  delete[] aho;
  return 0;
}
