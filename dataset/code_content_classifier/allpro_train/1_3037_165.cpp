#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
long long ccw(pair<long long, long long> a, pair<long long, long long> b,
              pair<long long, long long> c) {
  return a.first * b.second + b.first * c.second + c.first * a.second -
         a.second * b.first - b.second * c.first - c.second * a.first;
}
int n;
pair<long long, long long> arr[2010];
int chk[2010];
char str[2010];
vector<int> ans;
int main() {
  int i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%lld%lld", &arr[i].first, &arr[i].second);
  scanf("%s", str);
  pair<long long, long long> mini = arr[0];
  int t = 0;
  for (i = 0; i < n; i++) {
    if (mini > arr[i]) {
      mini = arr[i];
      t = i;
    }
  }
  ans.push_back(t);
  chk[t] = 1;
  int j;
  for (i = 0; i < n - 2; i++) {
    if (str[i] == 'L') {
      t = -1;
      for (j = 0; j < n; j++) {
        if (chk[j]) continue;
        if (t < 0 || ccw(arr[ans.back()], arr[t], arr[j]) < 0) t = j;
      }
    } else {
      t = -1;
      for (j = 0; j < n; j++) {
        if (chk[j]) continue;
        if (t < 0 || ccw(arr[ans.back()], arr[t], arr[j]) > 0) t = j;
      }
    }
    ans.push_back(t);
    chk[t] = 1;
  }
  for (i = 0; i < n; i++) {
    if (chk[i]) continue;
    ans.push_back(i);
  }
  for (int &v : ans) printf("%d ", v + 1);
  printf("\n");
  return 0;
}
