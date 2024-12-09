#include <bits/stdc++.h>
using namespace std;
struct trie {
  trie *child[2];
  int cnt[2];
  trie() {
    child[0] = child[1] = 0;
    cnt[0] = cnt[1] = 0;
  }
  void add(int x, int i) {
    if (i == -1) return;
    int cur = ((1 << i) & x) ? 1 : 0;
    if (child[cur] == 0) child[cur] = new trie();
    cnt[cur]++;
    child[cur]->add(x, i - 1);
  }
  void delet(int x, int i) {
    if (i == -1) return;
    int cur = ((1 << i) & x) ? 1 : 0;
    cnt[cur]--;
    child[cur]->delet(x, i - 1);
  }
  int solve(int x, int i) {
    if (i == -1) return 0;
    int cur = ((1 << i) & x) ? 1 : 0;
    if (cur == 0) {
      if (child[1] != 0 && cnt[1] > 0)
        return (1 << i) + child[1]->solve(x, i - 1);
      else
        return child[0]->solve(x, i - 1);
    } else {
      if (child[0] != 0 && cnt[0] > 0)
        return child[0]->solve(x, i - 1);
      else
        return (1 << i) + child[1]->solve(x, i - 1);
    }
  }
};
int q, x;
char c;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  trie tree;
  cin >> q;
  tree.add(0, 30);
  while (q--) {
    cin >> c >> x;
    if (c == '+')
      tree.add(x, 30);
    else if (c == '-')
      tree.delet(x, 30);
    else
      cout << max(x, x ^ (tree.solve(x, 30))) << endl;
  }
}
