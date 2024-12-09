#include <bits/stdc++.h>
const int inf = (1ll << 25) - 1;
const int maxn = (int)3e6 + 100;
const int mod = (int)1e9 + 7;
using namespace std;
struct node {
  map<char, int> nxt;
  int len;
  int link;
  int cnt;
  int mx;
} second[maxn];
int N;
int last = 0;
void init() {
  second[0].link = -1;
  second[0].len = 0;
  second[0].nxt.clear();
  N = 1;
  last = 0;
}
void add(char c) {
  int v = N;
  second[v].cnt = 1;
  N++;
  int p = last;
  second[v].nxt.clear();
  second[v].len = second[p].len + 1;
  while (p != -1 && !second[p].nxt.count(c)) {
    second[p].nxt[c] = v;
    p = second[p].link;
  }
  if (p == -1) {
    second[v].link = 0;
  } else {
    int q = second[p].nxt[c];
    if (second[q].len == second[p].len + 1) {
      second[v].link = q;
    } else {
      int cl = N++;
      second[cl].len = second[p].len + 1;
      second[cl].link = second[q].link;
      second[cl].nxt = second[q].nxt;
      while (p != -1 && second[p].nxt[c] == q) {
        second[p].nxt[c] = cl;
        p = second[p].link;
      }
      second[v].link = second[q].link = cl;
    }
  }
  last = v;
}
int cmp(int i, int j) { return second[i].len > second[j].len; }
void calc() {
  vector<int> p;
  for (int i = 0; i < N; i++) p.push_back(i);
  sort(p.begin(), p.end(), cmp);
  for (int i = 0; i < p.size(); i++) {
    if (second[p[i]].link != -1) {
      second[second[p[i]].link].cnt += second[p[i]].cnt;
    }
  }
}
int u[maxn];
int T;
int get(string t) {
  T++;
  int v = 0;
  int ans = 0;
  int L = 0;
  for (int i = 0; i < t.size(); i++) {
    while (v && !second[v].nxt.count(t[i])) {
      v = second[v].link;
      L = second[v].len;
    }
    if (second[v].nxt.count(t[i])) {
      v = second[v].nxt[t[i]];
      L++;
    }
  }
  if (L == t.size()) {
    u[v] = T;
    ans += second[v].cnt;
  }
  for (int i = 0; i < t.size(); i++) {
    if (L == t.size()) {
      L--;
      if (second[second[v].link].len == L) {
        v = second[v].link;
      }
    }
    while (v && !second[v].nxt.count(t[i])) {
      v = second[v].link;
      L = second[v].len;
    }
    if (second[v].nxt.count(t[i])) {
      v = second[v].nxt[t[i]];
      L++;
    }
    if (L == t.size() && u[v] != T) {
      ans += second[v].cnt;
      u[v] = T;
    }
  }
  return ans;
}
void solve() {
  string t;
  cin >> t;
  init();
  for (int i = 0; i < t.size(); i++) add(t[i]);
  calc();
  int x;
  cin >> x;
  for (int i = 0; i < x; i++) {
    cin >> t;
    cout << get(t) << "\n";
  }
}
int main() {
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
