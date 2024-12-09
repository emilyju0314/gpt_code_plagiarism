#include <bits/stdc++.h>
using namespace std;
const int MOD(1000000007);
const int INF((1 << 30) - 1);
const int MAXN(55);
int a[MAXN];
string b[MAXN];
string gen(int x) {
  string ret = "";
  if (x < 26)
    ret += 'A';
  else
    ret += 'B';
  ret += ('a' + x % 26);
  return ret;
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n - k + 1; i++) {
    string s;
    cin >> s;
    a[i] = (s == "YES");
  }
  int now = 0;
  for (int i = 0; i < k; i++) b[i] = gen(now++);
  if (a[0] == 0) b[k - 1] = b[0];
  for (int i = 1; i <= n - k; i++) {
    if (a[i] == 1)
      b[i + k - 1] = gen(now++);
    else
      b[i + k - 1] = b[i];
  }
  for (int i = 0; i < n; i++) cout << b[i] << " ";
}
