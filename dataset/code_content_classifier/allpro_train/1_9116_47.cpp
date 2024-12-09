#include <bits/stdc++.h>
// #include <atcoder/modint>
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define INF 2000000000000000000
#define ll long long
#define ld long double
#define pll pair<ll, ll>
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N;
  cin >> N;
  vector<ll> A(N), B(N);
  for (ll i = 0; i < N; ++i) {
    cin >> A.at(i);
  }
  for (ll i = 0; i < N; ++i) {
    cin >> B.at(i);
  }
  ll ans = 0;
  for (ll i = 0; i < N; ++i) {
    ans += A.at(i) * B.at(i);
  }
  ll ori_ans = ans;
  //black
  for (ll i = 0; i < N; ++i) {
    ll l = i - 1, r = i + 1;
    ll now_ans = ori_ans;
    while (0 <= l && r < N) {
      now_ans -= A.at(l) * B.at(l) + A.at(r) * B.at(r);
      now_ans += A.at(l) * B.at(r) + A.at(r) * B.at(l);
      ans = max(ans, now_ans);
      l -= 1, r += 1;
    }
  }
  //red
  for (ll i = 0; i < N; ++i) {
    ll l = i , r = i + 1;
    ll now_ans = ori_ans;
    while (0 <= l && r < N) {
      now_ans -= A.at(l) * B.at(l) + A.at(r) * B.at(r);
      now_ans += A.at(l) * B.at(r) + A.at(r) * B.at(l);
      ans = max(ans, now_ans);
      l -= 1, r += 1;
    }
  }
  cout << ans << "\n";
}
