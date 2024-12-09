#include <bits/stdc++.h>
using namespace std;
struct node {
  int h, m;
};
bool operator<=(node n1, node n2) {
  if (n1.h < n2.h)
    return 1;
  else if (n1.h == n2.h) {
    if (n1.m <= n2.m)
      return 1;
    else
      return 0;
  } else
    return 0;
}
bool operator==(node n1, node n2) { return n1.h == n2.h && n1.m == n2.m; }
int n;
node A[105];
int same_cnt = 0;
bool need_to_add(node n1, node n2) {
  if (n1 == n2)
    same_cnt++;
  else
    same_cnt = 1;
  if (same_cnt > 10) {
    same_cnt = 1;
    return 1;
  }
  if (n1 <= n2)
    return 0;
  else
    return 1;
}
int main(void) {
  cin >> n;
  string s;
  getline(cin, s);
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    int a = (s[1] - '0') * 10 + (s[2] - '0');
    int b = (s[4] - '0') * 10 + (s[5] - '0');
    if (s[7] == 'p' && a != 12) a += 12;
    if (s[7] == 'a' && a == 12) a = 0;
    A[i] = (node){a, b};
  }
  int ans = 1;
  for (int i = 1; i < n; i++) {
    if (need_to_add(A[i - 1], A[i])) {
      ans++;
    }
  }
  cout << ans;
  return 0;
}
