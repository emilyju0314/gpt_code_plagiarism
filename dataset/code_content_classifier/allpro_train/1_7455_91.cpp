#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
int t, n, m, k;
int a[N];
vector<int> ans;
char s[N];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    scanf("%d", &k);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      if (a[i] & 1) {
        ans.push_back(i);
        cnt++;
      }
    }
    if (cnt < k || (cnt > k && (cnt - k + 1) % 2 != 1))
      puts("NO");
    else {
      puts("YES");
      int num = cnt - k;
      int len = ans.size();
      ans[len - 1] = n;
      cout << ans[num] << ' ';
      for (int i = num + 1; i <= len - 1; i++) cout << ans[i] << ' ';
      cout << endl;
    }
    ans.clear();
  }
}
