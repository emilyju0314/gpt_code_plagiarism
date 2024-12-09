#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int x = 1;
vector<int> color;
vector<vector<int> > gr;
int ans = 0;
bool prime(long long x) {
  if (x == 1) return 0;
  if (x == 2) return 1;
  if (x % 2 == 0) return 0;
  for (int i = 3; i * i <= x; i++) {
    if (x % i == 0) return 0;
  }
  return 1;
}
vector<int> prefix_function(const string& s) {
  int len = s.length();
  vector<int> p(len);
  p[0] = 0;
  int k = 0;
  for (int i = 1; i < len; i++) {
    while ((k > 0) && (s[k] != s[i])) k = p[k - 1];
    if (s[k] == s[i]) k++;
    p[i] = k;
  }
  return p;
}
int kmp_algorithm(const string& s, int& coun, int l) {
  int len = s.length();
  vector<int> p(len);
  p[0] = 0;
  int k = 0;
  for (int i = 1; i < len; i++) {
    while ((k > 0) && (s[k] != s[i])) k = p[k - 1];
    if (s[k] == s[i]) k++;
    p[i] = k;
    if (p[i] == l) coun++;
  }
  return coun;
}
void dfs(int v) {
  color[v] = 2;
  for (auto to : gr[v]) {
    if (color[to] == 2) {
      ans++;
    } else {
      dfs(to);
    }
  }
}
struct derevo {
  int x;
  derevo *l, *r;
};
struct derevo* add(derevo* tree, int elem) {
  if ((tree) == NULL) {
    (tree) = new derevo;
    (tree)->x = elem;
    (tree)->l = (tree)->r = NULL;
    return tree;
  } else {
    if (elem < (tree)->x)
      tree->l = add((tree)->l, elem);
    else
      tree->r = add((tree)->r, elem);
    return tree;
  }
}
void pr(derevo* tree) {
  if (tree != NULL) {
    pr(tree->l);
    cout << tree->x << " ";
    pr(tree->r);
  }
}
int main() {
  long long a, b;
  cin >> a >> b;
  if (b * log(a) < a * log(b)) {
    cout << "<";
    return 0;
  }
  if (b * log(a) > a * log(b)) {
    cout << ">";
    return 0;
  } else {
    cout << "=";
    return 0;
  }
  return 0;
}
