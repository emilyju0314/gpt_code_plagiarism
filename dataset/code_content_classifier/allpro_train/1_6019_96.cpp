#include <bits/stdc++.h>
using namespace std;
int n, K;
int ar[1002000];
int S[1002000];
long long res;
struct node {
  int cnt;
  node *left;
  node *right;
  node() {
    left = NULL;
    right = NULL;
    cnt = 0;
  }
} root;
void add(int x) {
  node *temp = &root;
  for (int i = 30; i >= 0; i--) {
    temp->cnt++;
    if ((1 << i) & x) {
      if (temp->right == NULL) temp->right = new node;
      temp = temp->right;
    } else {
      if (temp->left == NULL) temp->left = new node;
      temp = temp->left;
    }
  }
  temp->cnt++;
}
void check(int x) {
  node *temp = &root;
  node *temp2;
  for (int i = 30; temp != NULL && i >= 0; i--) {
    if ((1 << i) & K) {
      if ((1 << i) & x) {
        temp = temp->left;
      } else {
        temp = temp->right;
      }
    } else {
      if ((1 << i) & x) {
        temp2 = temp->left;
        if (temp2 != NULL) res += temp2->cnt;
        temp = temp->right;
      } else {
        temp2 = temp->right;
        if (temp2 != NULL) res += temp2->cnt;
        temp = temp->left;
      }
    }
    if (i == 0 && temp != NULL) res += temp->cnt;
  }
}
int main() {
  scanf(" %d %d", &n, &K);
  for (int i = 1; i <= n; i++) {
    scanf(" %d", &ar[i]);
    S[i] = ar[i] xor S[i - 1];
  }
  for (int i = 0; i <= n; i++) {
    check(S[i]);
    add(S[i]);
  }
  cout << res << endl;
  return 0;
}
