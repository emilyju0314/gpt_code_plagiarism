#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:134217728")
using namespace std;
const int MOD = (int)1e9 + 7;
char s1[1000001];
char s2[1000001];
int sz = 0;
char buf[1 << 8];
int n, m;
int cnt[10];
int c[10];
string s;
void init() {
  s = "";
  memcpy(cnt, c, sizeof(c));
}
vector<string> a;
void add(string s) {
  if (s[0] == '0') return;
  a.push_back(s);
}
int main() {
  scanf("%s", s1);
  scanf("%s", s2);
  n = strlen(s1);
  m = strlen(s2);
  for (int i = 0; i < n; ++i) cnt[s1[i] - '0']++;
  for (int i = 0; i < m; ++i) cnt[s2[i] - '0']--;
  int L = 0, R = (int)1e9;
  while (R - L > 1) {
    int M = (L + R) / 2;
    sprintf(buf, "%d", M);
    int len = strlen(buf);
    if (M + len <= n)
      L = M;
    else
      R = M;
  }
  sprintf(buf, "%d", L);
  for (int i = 0; buf[i]; ++i) cnt[buf[i] - '0']--;
  memcpy(c, cnt, sizeof(cnt));
  init();
  for (int i = 0; i <= 9; ++i) {
    while (cnt[i] > 0) {
      s += (char)('0' + i);
      cnt[i]--;
    }
  }
  add(string(s2) + s);
  init();
  for (int i = 1; i <= 9; ++i) {
    if (cnt[i] > 0) {
      s += (char)('0' + i);
      cnt[i]--;
      break;
    }
  }
  for (int i = 0; i < s2[0] - '0'; ++i) {
    while (cnt[i] > 0) {
      s += (char)('0' + i);
      cnt[i]--;
    }
  }
  s += string(s2);
  for (int i = s2[0] - '0'; i <= 9; ++i) {
    while (cnt[i] > 0) {
      s += (char)('0' + i);
      cnt[i]--;
    }
  }
  add(s);
  init();
  for (int i = 1; i <= 9; ++i) {
    if (cnt[i] > 0) {
      s += (char)('0' + i);
      cnt[i]--;
      break;
    }
  }
  for (int i = 0; i <= s2[0] - '0'; ++i) {
    while (cnt[i] > 0) {
      s += (char)('0' + i);
      cnt[i]--;
    }
  }
  s += string(s2);
  for (int i = s2[0] - '0' + 1; i <= 9; ++i) {
    while (cnt[i] > 0) {
      s += (char)('0' + i);
      cnt[i]--;
    }
  }
  add(s);
  sort(a.begin(), a.end());
  if (a.empty())
    printf("0\n");
  else
    printf("%s\n", a[0].c_str());
  return 0;
}
