#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
struct Node {
  int len, v;
  bool ok;
  Node *next[26], *p;
  Node(int _len) : len(_len), v(0), p(NULL), ok(true) {
    for (int i = 0; i < 26; i++) next[i] = NULL;
  }
} * root, *last[601000];
vector<Node *> node;
inline bool cmp(Node *a, Node *b) { return a->len < b->len; }
int n, L[12], R[12];
char str[50100], s[12][50100];
int trie[601000][26], cnt;
void insert(int now, int fa, int x) {
  Node *p = last[fa];
  Node *np = new Node(p->len + 1);
  while (p && p->next[x] == NULL) p->next[x] = np, p = p->p;
  if (!p) {
    np->p = root;
  } else {
    Node *q = p->next[x];
    if (q->len == p->len + 1) {
      np->p = q;
    } else {
      Node *nq = new Node(p->len + 1);
      memcpy(nq->next, q->next, sizeof nq->next);
      nq->p = q->p;
      q->p = np->p = nq;
      node.push_back(nq);
      while (p && p->next[x] == q) p->next[x] = nq, p = p->p;
    }
  }
  node.push_back(np);
  last[now] = np;
}
void DFS(int x) {
  for (int i = 0; i < 26; i++)
    if (trie[x][i]) {
      insert(trie[x][i], x, i);
      DFS(trie[x][i]);
    }
}
void clear(Node *rt) {
  for (int i = 0; i < node.size(); i++) node[i]->v = 0;
}
void push(int l, int r) {
  for (int i = node.size() - 1; i >= 0; i--) {
    node[i]->ok &= l <= node[i]->v && node[i]->v <= r;
    node[i]->p->v += node[i]->v;
  }
}
int main() {
  scanf("%s", str);
  int idx = 0;
  for (int i = 0; str[i]; i++) {
    if (!trie[idx][str[i] - 'a']) trie[idx][str[i] - 'a'] = ++cnt;
    idx = trie[idx][str[i] - 'a'];
  }
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i]);
    int idx = 0;
    for (int j = 0; s[i][j]; j++) {
      if (!trie[idx][s[i][j] - 'a']) trie[idx][s[i][j] - 'a'] = ++cnt;
      idx = trie[idx][s[i][j] - 'a'];
    }
    scanf("%d%d", &L[i], &R[i]);
  }
  root = last[0] = new Node(0);
  DFS(0);
  sort(node.begin(), node.end(), cmp);
  for (int i = 1; i <= n; i++) {
    clear(root);
    int idx = 0;
    Node *rt = root;
    for (int j = 0; s[i][j]; j++) {
      rt = rt->next[s[i][j] - 'a'];
      idx = trie[idx][s[i][j] - 'a'];
      rt->v++;
    }
    push(L[i], R[i]);
  }
  clear(root);
  Node *rt = root;
  for (int i = 0; str[i]; i++) {
    rt = rt->next[str[i] - 'a'];
    rt->v = 1;
  }
  long long ans(0);
  for (int i = node.size() - 1; i >= 0; i--) {
    if (node[i]->v && node[i]->ok) {
      ans += node[i]->len - node[i]->p->len;
    }
    node[i]->p->v |= node[i]->v;
  }
  cout << ans << endl;
  return 0;
}
