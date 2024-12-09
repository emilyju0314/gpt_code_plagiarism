#include <bits/stdc++.h>
using namespace std;
string str;
vector<int> cnt(26, 0);
int main() {
  cin >> str;
  for (int i = 0; i < str.size(); i++) cnt[str[i] - 'a']++;
  vector<int> odd;
  for (int i = 0; i < 26; i++) {
    if (cnt[i] % 2) odd.push_back(i);
  }
  for (int i = 0; i < odd.size() / 2; i++) {
    cnt[odd[i]]++;
    cnt[odd[odd.size() - 1 - i]]--;
  }
  string ans = "";
  for (int i = 0; i < 26; i++) {
    char a = 'a' + i;
    for (int j = 0; j < cnt[i] / 2; j++) ans += a;
  }
  if (odd.size() % 2) {
    char a = 'a' + odd[odd.size() / 2];
    ans += a;
  }
  for (int i = 25; i >= 0; i--) {
    char a = 'a' + i;
    for (int j = 0; j < cnt[i] / 2; j++) ans += a;
  }
  cout << ans;
  return 0;
}
