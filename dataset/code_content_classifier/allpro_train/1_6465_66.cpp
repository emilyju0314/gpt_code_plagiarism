#include <bits/stdc++.h>
using namespace std;
int dirx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int diry[8] = {1, -1, 0, 0, 1, -1, 1, -1};
string tostring(long long n) {
  if (!n) return "0";
  string ans = "";
  while (n != 0) {
    ans += (n % 10) + '0';
    n /= 10;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
double toDouble(string s) {
  double ans = 0;
  int i = 0, flag = 0, cnt = 0, ff = 1;
  while (i < s.length()) {
    if (s[i] == '-') {
      ff = -1;
      i++;
      continue;
    }
    if (s[i] == '.') {
      flag = 1;
      i++;
      continue;
    }
    ans *= 10;
    ans += s[i] - '0';
    if (flag) cnt++;
    i++;
  }
  ans *= ff;
  return ans / pow(10, cnt);
}
int ar[1005];
int main() {
  int n, a, b;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d %d", &a, &b);
    ar[a]++;
    ar[b]++;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (ar[i] == 1);
  }
  cout << ans << endl;
  return 0;
}
