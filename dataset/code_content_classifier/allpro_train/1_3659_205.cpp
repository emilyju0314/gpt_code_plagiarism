#include <bits/stdc++.h>
using namespace std;
int get_bit(int val, int id) { return (val >> id) & 1; }
struct node {
  int num;
  int child[2];
};
long long valInv[30 + 5][2];
vector<node> trie;
void new_node() {
  node New;
  New.num = 0;
  for (int i = 0; i <= 1; i++) New.child[i] = -1;
  trie.push_back(New);
}
void add(int val) {
  int indx = 0;
  for (int bit = 30; bit >= 0; bit--) {
    int x = get_bit(val, bit);
    trie[indx].num++;
    if (trie[indx].child[x] == -1) {
      new_node();
      trie[indx].child[x] = trie.size() - 1;
    }
    if (trie[indx].child[1 - x] >= 0)
      valInv[bit][x] += trie[trie[indx].child[1 - x]].num;
    indx = trie[indx].child[x];
  }
  trie[indx].num++;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  new_node();
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    add(x);
  }
  long long res = 0, resVal = 0;
  for (int bit = 0; bit <= 30; bit++) {
    res += min(valInv[bit][0], valInv[bit][1]);
    if (valInv[bit][0] > valInv[bit][1]) {
      resVal += (1 << bit);
    }
  }
  cout << res << ' ' << resVal << '\n';
}
