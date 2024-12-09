#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 100;
struct node {
  int val;
  node *br[26];
};
node *root;
node A[maxn];
string B[100010];
int dp[10010];
int tot;
string S;
void init(node *a) {
  for (int i = 0; i < 26; i++) a->br[i] = NULL;
  a->val = 0;
}
void insert(string s, int pos) {
  reverse(s.begin(), s.end());
  node *p = root;
  for (int i = 0; i < s.length(); i++) {
    int id = s[i] >= 'a' ? s[i] - 'a' : s[i] - 'A';
    if (p->br[id] == NULL) {
      p->br[id] = &A[++tot];
      p = p->br[id];
      init(p);
    } else
      p = p->br[id];
  }
  p->val = pos;
}
void query(int pos, node *p) {
  while (p) {
    p = p->br[S[pos] - 'a'];
    if (!p) return;
    if (p->val != 0) dp[pos] = p->val;
    pos++;
    if (pos >= S.length()) break;
  }
}
void output(int a) {
  if (a < 0) return;
  output(a - B[dp[a]].length());
  cout << B[dp[a]] << " ";
}
int main() {
  ios::sync_with_stdio(false);
  root = &A[0];
  init(root);
  int n, m;
  int i, j, k;
  cin >> n;
  cin >> S >> m;
  for (i = 1; i <= m; i++) {
    cin >> B[i];
    insert(B[i], i);
  }
  memset(dp, 0, sizeof dp);
  for (i = 0; i < n; i++) {
    if (i == 0 || dp[i - 1] != 0) query(i, root);
  }
  output(n - 1);
  return 0;
}
