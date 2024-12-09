#include <bits/stdc++.h>
using namespace std;
bool cmp(const pair<int, int> &left, const pair<int, int> &right) {
  return left.second < right.second;
}
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else
    return gcd(b, a % b);
}
int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int> > a;
  vector<pair<int, int> > b;
  int x, y, s1 = 0, s2 = 0;
  long long sum1 = 0, sum2 = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    scanf("%d", &y);
    if (x < 0) {
      a.push_back(make_pair(abs(x), y));
      sum1 += y;
      s1++;
    } else {
      b.push_back(make_pair(x, y));
      sum2 += y;
      s2++;
    }
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  if (s1 == s2 || abs(s1 - s2) <= 1) {
    cout << sum1 + sum2 << endl;
    return 0;
  }
  long long ans = 0;
  if (s1 < s2) {
    ans = sum1;
    for (int i = 0; i < s1 + 1; i++) {
      ans += b[i].second;
    }
  } else {
    ans = sum2;
    for (int i = 0; i < s2 + 1; i++) {
      ans += a[i].second;
    }
  }
  cout << ans << endl;
}
