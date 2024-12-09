#include <bits/stdc++.h>
using namespace std;
struct graw {
  long long a;
  long long b;
  long long c;
};
vector<graw> vert;
vector<graw> hor;
bool check(graw a, graw b) {
  return b.b <= a.a && a.a <= b.c && a.b <= b.a && a.c >= b.a;
}
bitset<5001> xi[5001];
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > c) swap(a, c);
    if (b > d) swap(b, d);
    if (a == c) {
      vert.push_back({a, b, d});
    } else {
      hor.push_back({b, a, c});
    }
  }
  if (hor.size() > vert.size()) {
    swap(hor, vert);
  }
  for (long long i = 0; i < hor.size(); i++) {
    for (long long j = 0; j < vert.size(); j++) {
      if (check(hor[i], vert[j])) xi[i].set(j);
    }
  }
  long long ans = 0;
  for (long long i = 0; i < hor.size(); i++) {
    for (long long j = i + 1; j < hor.size(); j++) {
      long long k = (xi[i] & xi[j]).count();
      k = k * (k - 1) / 2;
      ans += k;
    }
  }
  cout << ans;
}
