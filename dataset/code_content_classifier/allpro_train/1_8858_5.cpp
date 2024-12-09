#include <bits/stdc++.h>
using namespace std;
const int maxN = 1000005;
map<pair<int, int>, int> mp;
vector<pair<int, int> > Q;
vector<int> q;
int dp[3][maxN], d[maxN];
char a[maxN];
int n;
void solve(int x) {
  int X = Q[x].first, Y = Q[x].second, r = -1, r2 = -1;
  if (d[X + 1] != X + 1) r = mp[make_pair(X + 1, d[X + 1])];
  if (d[Y - 1] != Y - 1) r2 = mp[make_pair(d[Y - 1], Y - 1)];
  int num[10];
  memset(num, 0, sizeof num);
  if (r == -1)
    if (a[X + 1] == '0')
      num[0] = 1;
    else if (a[X + 1] == '1')
      num[1] = 1;
    else
      num[2] = 1;
  else
    num[0] = dp[0][r], num[1] = dp[1][r], num[2] = dp[2][r];
  if (r2 == -1)
    if (a[Y - 1] == '0')
      num[3] = 1;
    else if (a[Y - 1] == '1')
      num[4] = 1;
    else
      num[5] = 1;
  else
    num[3] = dp[0][r2], num[4] = dp[1][r2], num[5] = dp[2][r2];
  if (a[d[X + 1] + 1] == '&') {
    if (num[0] || num[3]) dp[0][x] = 1;
    if (num[1] && num[4]) dp[1][x] = 1;
    if (num[2] && num[5]) dp[2][x] = dp[0][x] = 1;
    if ((num[2] && num[4]) || (num[5] && num[1])) dp[2][x] = 1;
  } else if (a[d[X + 1] + 1] == '|') {
    if (num[1] || num[4]) dp[1][x] = 1;
    if (num[0] && num[3]) dp[0][x] = 1;
    if (num[2] && num[5]) dp[2][x] = dp[1][x] = 1;
    if ((num[2] && num[3]) || (num[5] && num[0])) dp[2][x] = 1;
  } else {
    if (num[2] && num[5]) dp[0][x] = dp[1][x] = 1;
    if ((num[0] || num[1]) && num[5]) dp[2][x] = 1;
    if ((num[3] || num[4]) && num[2]) dp[2][x] = 1;
    if ((num[0] && num[3]) || (num[1] && num[4])) dp[0][x] = 1;
    if ((num[0] && num[4]) || (num[1] && num[3])) dp[1][x] = 1;
  }
}
int main() {
  scanf("%d", &n);
  scanf("%s", &a);
  int len = 0;
  while (a[len]) len++;
  for (int i = 0; i < len; i++) {
    if (a[i] == '(')
      q.push_back(i);
    else if (a[i] == ')') {
      Q.push_back(make_pair(q.back(), i));
      mp[Q.back()] = (int)Q.size() - 1;
      d[q.back()] = i, d[i] = q.back();
      q.pop_back();
    } else
      d[i] = i;
  }
  for (int i = 0; i < Q.size(); i++) solve(i);
  if (len == 1) {
    if (a[0] == '?')
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    return 0;
  }
  if (dp[2][mp[make_pair(0, len - 1)]])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
