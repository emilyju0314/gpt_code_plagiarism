#include <bits/stdc++.h>
using namespace std;
const int ms = 1e7;
int trie[ms][2], cnt[ms][2], sz = 0, a[ms], p[ms];
void insert(string s) {
  int node = 0;
  for (int i = 0; i < 64; i++) {
    if (trie[node][s[i] - '0'] != -1) {
      cnt[node][s[i] - '0']++;
      node = trie[node][s[i] - '0'];
    } else {
      trie[node][s[i] - '0'] = ++sz;
      cnt[node][s[i] - '0']++;
      node = trie[node][s[i] - '0'];
    }
  }
}
long long find_best(string s) {
  int node = 0;
  string ans = "";
  for (int i = 0; i < 64; i++) {
    if (s[i] == '1') {
      if (trie[node][1] != -1 && cnt[node][1] > 0) {
        ans.push_back('0');
        cnt[node][1]--;
        node = trie[node][1];
      } else {
        ans.push_back('1');
        cnt[node][0]--;
        node = trie[node][0];
      }
    } else {
      if (trie[node][0] != -1 && cnt[node][0] > 0) {
        ans.push_back('0');
        cnt[node][0]--;
        node = trie[node][0];
      } else {
        ans.push_back('1');
        cnt[node][1]--;
        node = trie[node][1];
      }
    }
  }
  bitset<64> a(ans);
  return a.to_ullong();
}
int main() {
  memset(trie, -1, sizeof trie);
  memset(cnt, 0, sizeof cnt);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < n; i++) scanf("%d", p + i);
  for (int i = 0; i < n; i++) {
    bitset<64> bs(p[i]);
    insert(bs.to_string());
  }
  for (int i = 0; i < n; i++) {
    bitset<64> bs(a[i]);
    cout << find_best(bs.to_string()) << " ";
  }
  return 0;
}
