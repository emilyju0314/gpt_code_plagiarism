#include <bits/stdc++.h>
using namespace std;
int n;
long long sum1[234234];
long long sum2[234234];
vector<pair<long long, long long> > lines;
long long ans;
void IOS() { ios_base::sync_with_stdio(0); }
long double inter_x(long double a, long double b, long double c,
                    long double d) {
  return (d - b) / (a - c);
}
long double inter_x(pair<long long, long long> l1,
                    pair<long long, long long> l2) {
  return inter_x(l1.first, l1.second, l2.first, l2.second);
}
void add_line(pair<long long, long long> l) {
  while (lines.size() > 1 && inter_x(l, lines.back()) >=
                                 inter_x(lines.back(), lines[lines.size() - 2]))
    lines.pop_back();
  lines.push_back(l);
}
void add_line(long long a, long long b) { add_line(make_pair(a, b)); }
long long ev(pair<long long, long long> l, long long x) {
  return l.first * x + l.second;
}
long long get_max(long long x) {
  if (lines.size() == 1) return ev(lines[0], x);
  if (inter_x(lines[0], lines[1]) <= x) return ev(lines[0], x);
  int p = 1;
  int q = lines.size() - 1;
  int s;
  while (p < q) {
    s = (p + q + 1) / 2;
    if (inter_x(lines[s], lines[s - 1]) > x)
      p = s;
    else
      q = s - 1;
  }
  return ev(lines[p], x);
}
int main() {
  IOS();
  cin >> n;
  long long a;
  for (int i = 1; i <= n; ++i) {
    cin >> a;
    sum1[i] = sum1[i - 1] + a;
    sum2[i] = sum2[i - 1] + a * i;
  }
  for (int i = 1; i <= n; ++i) {
    add_line(-i + 1, -sum2[i - 1] + (i - 1) * sum1[i - 1]);
    ans = max(ans, get_max(sum1[i]) + sum2[i]);
  }
  cout << ans << endl;
}
