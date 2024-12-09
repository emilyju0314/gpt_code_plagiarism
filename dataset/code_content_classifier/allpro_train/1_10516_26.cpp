#include <bits/stdc++.h>
using namespace std;
int on(int n, int k) { return (n | (1 << k)); }
int off(int n, int k) { return (n - (n & (1 << k))); }
bool chck(int n, int k) { return (n & (1 << k)); }
int mini(int a, int b) {
  if (a < b) return a;
  return b;
}
int maxi(int a, int b) {
  if (a > b) return a;
  return b;
}
int n;
int len1[5100];
char s1[5100], s2[5100];
struct state {
  int len, link;
  int count;
  map<char, int> next;
};
const int MAXLEN = 5100 + 2;
state st[MAXLEN * 2];
int sz, last;
pair<int, int> sorter[MAXLEN * 2 + 10];
inline void sa_init() {
  sz = last = 0;
  st[0].len = 0;
  st[0].link = -1;
  st[0].count = 1;
  st[0].next.clear();
  ++sz;
}
inline void sa_extend(char c) {
  int cur = sz++;
  st[cur].len = st[last].len + 1;
  st[cur].count = 1;
  st[cur].next.clear();
  int p;
  for (p = last; p != -1 && !st[p].next.count(c); p = st[p].link)
    st[p].next[c] = cur;
  if (p == -1)
    st[cur].link = 0;
  else {
    int q = st[p].next[c];
    if (st[p].len + 1 == st[q].len)
      st[cur].link = q;
    else {
      int clone = sz++;
      st[clone].len = st[p].len + 1;
      st[clone].next = st[q].next;
      st[clone].link = st[q].link;
      for (; p != -1 && st[p].next[c] == q; p = st[p].link)
        st[p].next[c] = clone;
      st[q].link = st[cur].link = clone;
    }
  }
  last = cur;
}
void post_process() {
  int i;
  for (i = 0; i < sz; i++) {
    sorter[i] = make_pair(st[i].len, i);
  }
  sort(sorter, sorter + sz);
  for (i = sz - 1; i >= 0; i--) {
    int ind = sorter[i].second;
    st[st[ind].link].count += st[ind].count;
  }
}
void cal_dup(char *s, int from[]) {
  int curr_st = 0, len = 0;
  for (int i = 0; s[i]; i++) {
    while (curr_st && !st[curr_st].next.count(s[i])) {
      curr_st = st[curr_st].link;
      len = st[curr_st].len;
    }
    if (st[curr_st].next.count(s[i])) {
      curr_st = st[curr_st].next[s[i]];
      len++;
    }
    if (st[curr_st].count > 1) {
      from[i] = -1;
      continue;
    }
    from[i] = st[st[curr_st].link].len + 1;
  }
}
int cal(char *s) {
  int i, j, k;
  int curr_st = 0, ret = (1 << 29), len = 0;
  for (i = 0; s[i]; i++) {
    while (curr_st && !st[curr_st].next.count(s[i])) {
      curr_st = st[curr_st].link;
      len = st[curr_st].len;
    }
    if (st[curr_st].next.count(s[i])) {
      curr_st = st[curr_st].next[s[i]];
      len++;
    }
    if (!curr_st || st[curr_st].count > 1 || len1[i] == -1) continue;
    int min_len = st[st[curr_st].link].len + 1;
    int ret1 = maxi(min_len, len1[i]);
    if (ret1 > i + 1 || ret1 > st[curr_st].len || ret1 > len) continue;
    ret = mini(ret, ret1);
  }
  return ret;
}
int main() {
  int i, j, k, l, q;
  scanf("%s", s1);
  sa_init();
  for (i = 0; s1[i]; i++) {
    sa_extend(s1[i]);
  }
  post_process();
  cal_dup(s1, len1);
  scanf("%s", s2);
  sa_init();
  for (i = 0; s2[i]; i++) {
    sa_extend(s2[i]);
  }
  post_process();
  int ans = cal(s1);
  if (ans >= (1 << 29)) ans = -1;
  printf("%d\n", ans);
  return 0;
}
