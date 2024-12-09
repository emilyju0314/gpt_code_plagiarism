#include <bits/stdc++.h>
using namespace std;
char s[1000010];
int n1[1000010], n2[1000010], pre[1000010], nex[1000010];
int main() {
  ios::sync_with_stdio(false);
  cin.getline(s, 1000010);
  int l = strlen(s), num = 0;
  for (int i = 0; i < l - 1; i++) {
    if (s[i] != s[i + 1]) {
      n1[num] = i - 1;
      i++;
      while ((i < l && s[i] != s[i - 1]) || (i < l - 1 && s[i] != s[i + 1]))
        i++;
      n2[num] = i;
      num++;
    }
  }
  if (num == 0) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < num; i++) {
    nex[i] = i + 1;
    pre[i] = i - 1;
  }
  int ans = 0;
  bool tf = true;
  while (tf) {
    ans++;
    tf = false;
    int cur = 0;
    while (cur != num) {
      if (n1[cur] >= 0 && n2[cur] < l) {
        if (s[n1[cur]] != s[n2[cur]]) {
          tf = true;
          n1[cur]--;
          n2[cur]++;
        }
      }
      if (cur != 0) {
        if (n1[cur] < n2[pre[cur]]) {
          n2[pre[cur]] = n2[cur];
          pre[nex[cur]] = pre[cur];
          nex[pre[cur]] = nex[cur];
        }
      }
      cur = nex[cur];
    }
  }
  cout << ans << endl;
}
