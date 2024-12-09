#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, x;
long long ans;
unordered_map<int, int> cnt;
string st;
char ss[1000005];
int main() {
  scanf("%d", &n);
  while (n--) {
    scanf(" %s", ss);
    st = ss;
    x = 0;
    for (i = 0; i < st.length(); i++) x ^= (1 << (st[i] - 'a'));
    for (i = 0; i < 26; i++) ans += cnt[x ^ (1 << i)];
    ans += cnt[x];
    cnt[x]++;
  }
  cout << ans << endl;
  return 0;
}
