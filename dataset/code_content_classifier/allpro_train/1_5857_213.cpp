#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5010;
int n, pref[MAXN];
int pref1[MAXN];
int get(int a, int b) {
  int ret = pref[b];
  if (a) ret -= pref[a - 1];
  return ret;
}
int get1(int a, int b) {
  int ret = pref1[b];
  if (a) ret -= pref1[a - 1];
  return ret;
}
char s[MAXN];
int valid[MAXN][MAXN];
int valid1[MAXN][MAXN];
vector<int> v[MAXN];
set<int> st[MAXN];
bool find(int a, int b) {
  for (int i = (0); i < int((int)v[a].size()); i++) {
    if (st[b].find(v[a][i] + 1) != st[b].end()) return 1;
  }
  return 0;
}
int main() {
  scanf("%s", s);
  n = strlen(s);
  int sol = 0;
  for (int i = (0); i < int(n); i++) {
    int tmp = 0, up = 0;
    for (int j = (i); j < int(n); j++) {
      if (s[j] == '?')
        up++;
      else if (s[j] == '(')
        tmp++;
      else
        tmp--;
      if (tmp < 0 && !up) break;
      if (tmp < 0) {
        tmp++;
        up--;
      }
      if (tmp >= 0 && up >= tmp && (up - tmp) % 2 == 0) valid[i][j] = 1;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    int tmp = 0, up = 0;
    for (int j = i; j >= 0; j--) {
      if (s[j] == '?')
        up++;
      else if (s[j] == ')')
        tmp++;
      else
        tmp--;
      if (tmp < 0 && !up) break;
      if (tmp < 0) {
        tmp++;
        up--;
      }
      if (tmp >= 0 && up >= tmp && (up - tmp) % 2 == 0) {
        valid1[j][i] = 1;
      }
    }
  }
  for (int i = (0); i < int(n); i++)
    for (int j = (0); j < int(n); j++) sol += valid[i][j] * valid1[i][j];
  printf("%d\n", sol);
  return 0;
}
