#include <bits/stdc++.h>
using namespace std;
using namespace std;
vector<long long> ans;
vector<int> prefixFunction(string pat) {
  int m = pat.length();
  vector<int> longestPrefix(m);
  for (int i = 1, k = 0; i < m; i++) {
    while (k > 0 && pat[k] != pat[i]) {
      k = longestPrefix[k - 1];
    }
    if (pat[k] == pat[i])
      longestPrefix[i] = ++k;
    else
      longestPrefix[i] = k;
  }
  return longestPrefix;
}
void kmp(string str, string pat) {
  int n = str.length();
  int m = pat.length();
  vector<int> longestPrefix = prefixFunction(pat);
  for (int i = 0, k = 0; i < n; i++) {
    while (k > 0 && pat[k] != str[i]) {
      k = longestPrefix[k - 1];
    }
    if (pat[k] == str[i]) k++;
    if (k == m) {
      ans.push_back(i - m + 2);
      k = longestPrefix[k - 1];
    }
  }
}
int main() {
  long long sum = 0;
  string s;
  cin >> s;
  int n = s.length();
  kmp(s, "bear");
  int m = ans.size();
  if (m) sum += ans[0] * (n - ans[0] - 2);
  for (int i = 1; i < m && m; i++) {
    sum += (ans[i] - ans[i - 1]) * (n - ans[i] - 2);
  }
  cout << sum;
  return 0;
}
