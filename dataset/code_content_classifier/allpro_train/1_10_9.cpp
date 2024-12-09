#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int oo = 1e9 + 7;
int a[maxn], c[maxn], n;
int pos[maxn];
long long ans[maxn];
void update(int x) {
  for (int i = x; i <= n && i; i += i & (-i)) c[i]++;
}
long long query(int x) {
  long long ans = 0;
  while (x) ans = ans + 1ll * c[x], x -= x & (-x);
  return ans;
}
priority_queue<int> q1, q2;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), pos[a[i]] = i;
  long long a1 = 0, ln = 0, rn = 0;
  for (long long i = 1; i <= n; i++) {
    update(pos[i]);
    a1 = a1 + i - query(pos[i]);
    if (q1.size() && pos[i] < q1.top()) {
      ln += pos[i];
      q1.push(pos[i]);
    } else {
      rn += pos[i];
      q2.push(-pos[i]);
    }
    while (q1.size() < q2.size()) {
      long long c = -q2.top();
      ln += c;
      rn -= c;
      q2.pop();
      q1.push(c);
    }
    while (q1.size() > q2.size() + 1) {
      long long c = q1.top();
      ln -= c;
      rn += c;
      q1.pop();
      q2.push(-c);
    }
    long long top = q1.top();
    ans[i] = a1 + 1ll * top * q1.size() - ln -
             1ll * q1.size() * (q1.size() - 1) / 2 + rn - top * q2.size() -
             1ll * q2.size() * (q2.size() + 1) / 2;
    ;
    ;
  }
  for (int i = 1; i <= n; i++) {
    if (i != 1) printf(" ");
    printf("%lld", ans[i]);
  }
}
