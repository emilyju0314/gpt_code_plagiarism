#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000009;
const char tab = 'a';
const int max_next = 4;
int rev[256];
struct trie {
  struct trie *fail;
  struct trie *next[max_next];
  int isword;
  int index;
};
struct AC {
  trie *que[100005], *root, ac[100005];
  int head, tail;
  int idx;
  trie *New() {
    trie *temp = &ac[idx];
    for (int i = 0; i < max_next; i++) temp->next[i] = NULL;
    temp->fail = NULL;
    temp->isword = 0;
    temp->index = idx++;
    return temp;
  }
  void init() {
    idx = 0;
    root = New();
  }
  void Insert(trie *root, char *word, int len) {
    trie *t = root;
    for (int i = 0; i < len; i++) {
      if (t->next[rev[word[i]]] == NULL) t->next[rev[word[i]]] = New();
      t = t->next[rev[word[i]]];
    }
    t->isword = len;
  }
  void acbuild(trie *root) {
    int head = 0, tail = 0;
    que[tail++] = root;
    root->fail = NULL;
    while (head < tail) {
      trie *temp = que[head++], *p;
      for (int i = 0; i < max_next; i++) {
        if (temp->next[i]) {
          if (temp == root)
            temp->next[i]->fail = root;
          else {
            p = temp->fail;
            while (p != NULL) {
              if (p->next[i]) {
                temp->next[i]->fail = p->next[i];
                break;
              }
              p = p->fail;
            }
            if (p == NULL) temp->next[i]->fail = root;
          }
          if (temp->next[i]->fail->isword)
            temp->next[i]->isword =
                max(temp->next[i]->isword, temp->next[i]->fail->isword);
          que[tail++] = temp->next[i];
        } else if (temp == root)
          temp->next[i] = root;
        else
          temp->next[i] = temp->fail->next[i];
      }
    }
  }
  void tra() {
    for (int i = 0; i < idx; i++) {
      if (ac[i].fail != NULL) printf("fail = %d ", ac[i].fail->index);
      for (int k = 0; k < max_next; k++) printf("%d ", ac[i].next[k]->index);
      puts("");
    }
  }
} sa, sb;
string cq[55];
char word[55];
int dp[1005][105][11];
void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int solve(int L) {
  memset(dp, 0, sizeof dp);
  dp[0][0][0] = 1;
  for (int i = 0; i < L; i++) {
    for (int j = 0; j < sa.idx; j++) {
      for (int k = 0; k < 10; k++) {
        for (int d = 0; d < 4; d++) {
          if (sa.ac[j].next[d]->isword >= k + 1)
            add(dp[i + 1][sa.ac[j].next[d]->index][0], dp[i][j][k]);
          else if (k + 1 <= 10)
            add(dp[i + 1][sa.ac[j].next[d]->index][k + 1], dp[i][j][k]);
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < sa.idx; i++) {
    add(ans, dp[L][i][0]);
  }
  return ans;
}
int main() {
  rev['A'] = 0;
  rev['C'] = 1;
  rev['G'] = 2;
  rev['T'] = 3;
  int m, L;
  while (cin >> L >> m) {
    sa.init();
    for (int i = 1; i <= m; i++) {
      cin >> word;
      sa.Insert(sa.root, word, strlen(word));
    }
    sa.acbuild(sa.root);
    printf("%d\n", solve(L));
  }
  return 0;
}
