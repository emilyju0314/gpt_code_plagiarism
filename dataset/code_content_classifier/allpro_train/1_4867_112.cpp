#include <bits/stdc++.h>
using namespace std;
vector<int> dp[100005];
string s[100005];
int same, same2[1000005], same3[1000005], same4[1000005];
int mod = 1e9 + 7;
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    char c[1000005];
    scanf("%s", c);
    s[i] = string(c);
  }
  for (int i = 0; i < s[0].size(); i++) {
    dp[0].push_back(1);
  }
  dp[0].push_back(1);
  for (int i = 1; i < n; i++) {
    for (same = 0; same != max(s[i].size(), s[i - 1].size()) &&
                   s[i][same] == s[i - 1][same];
         same++) {
    }
    int now = 0;
    for (int j = 0; j <= s[i - 1].size(); j++) {
      while ((j + now < s[i - 1].size() && j + 1 + now < s[i].size()) &&
             s[i - 1][j + now] == s[i][j + 1 + now])
        now++;
      same2[j] = j + now;
      now--;
      if (now < 0) now = 0;
    }
    now = 0;
    for (int j = 0; j <= s[i].size(); j++) {
      while ((j + now < s[i].size() && j + 1 + now < s[i - 1].size()) &&
             s[i][j + now] == s[i - 1][j + 1 + now])
        now++;
      same3[j] = j + now;
      now--;
      if (now < 0) now = 0;
    }
    now = 0;
    for (int j = 0; j <= s[i].size() || j <= s[i - 1].size(); j++) {
      while ((j + now < s[i].size() && j + now < s[i - 1].size()) &&
             s[i][j + now] == s[i - 1][j + now])
        now++;
      same4[j] = j + now;
      now--;
      if (now < 0) now = 0;
    }
    deque<int> q1, q2;
    q1.push_back(s[i - 1].size());
    int last;
    for (int j = s[i - 1].size() - 1; j >= 0; j--) {
      if (s[i - 1][j] > s[i - 1][j + 1]) {
        q1.push_front(j);
        last = 1;
      } else if (s[i - 1][j] < s[i - 1][j + 1]) {
        q1.push_back(j);
        last = 0;
      } else {
        if (last)
          q1.push_front(j);
        else
          q1.push_back(j);
      }
    }
    q2.push_back(s[i].size());
    for (int j = s[i].size() - 1; j >= 0; j--) {
      if (s[i][j] > s[i][j + 1]) {
        q2.push_front(j);
        last = 1;
      } else if (s[i][j] < s[i][j + 1]) {
        q2.push_back(j);
        last = 0;
      } else {
        if (last)
          q2.push_front(j);
        else
          q2.push_back(j);
      }
    }
    long long sum = 0;
    dp[i].resize(s[i].size() + 1);
    while (!q1.empty() || !q2.empty()) {
      if (q1.empty()) {
        dp[i][q2.front()] = sum;
        q2.pop_front();
      } else if (q2.empty()) {
        break;
      } else {
        int a = q1.front(), b = q2.front();
        int big = 0;
        if (min(a, b) <= same) {
          if (a > b) {
            if (same2[b] < a) {
              char first, second;
              if (same2[b] >= s[i - 1].size())
                first = 0;
              else
                first = s[i - 1][same2[b]];
              if (same2[b] + 1 >= s[i].size())
                second = 0;
              else
                second = s[i][same2[b] + 1];
              if (first <= second) {
                big = 1;
              }
            } else {
              char first, second;
              if (same4[a + 1] >= s[i - 1].size())
                first = 0;
              else
                first = s[i - 1][same4[a + 1]];
              if (same4[a + 1] >= s[i].size())
                second = 0;
              else
                second = s[i][same4[a + 1]];
              if (first <= second) {
                big = 1;
              }
            }
          } else if (a == b) {
            char first, second;
            if (same4[a + 1] >= s[i - 1].size())
              first = 0;
            else
              first = s[i - 1][same4[a + 1]];
            if (same4[a + 1] >= s[i].size())
              second = 0;
            else
              second = s[i][same4[a + 1]];
            if (first <= second) {
              big = 1;
            }
          } else {
            if (same3[a] < b) {
              char first, second;
              if (same3[a] + 1 >= s[i - 1].size())
                first = 0;
              else
                first = s[i - 1][same3[a] + 1];
              if (same3[a] >= s[i].size())
                second = 0;
              else
                second = s[i][same3[a]];
              if (first <= second) {
                big = 1;
              }
            } else {
              char first, second;
              if (same4[b + 1] >= s[i - 1].size())
                first = 0;
              else
                first = s[i - 1][same4[b + 1]];
              if (same4[b + 1] >= s[i].size())
                second = 0;
              else
                second = s[i][same4[b + 1]];
              if (first <= second) {
                big = 1;
              }
            }
          }
          if (big) {
            sum += dp[i - 1][a];
            sum %= mod;
            q1.pop_front();
          } else {
            dp[i][b] = sum;
            q2.pop_front();
          }
        } else {
          if (s[i][same] >= s[i - 1][same]) {
            sum += dp[i - 1][a];
            sum %= mod;
            q1.pop_front();
          } else {
            dp[i][b] = sum;
            q2.pop_front();
          }
        }
      }
    }
  }
  long long ans = 0;
  for (auto it : dp[n - 1]) {
    ans += it;
    ans %= mod;
  }
  printf("%lld\n", ans);
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
