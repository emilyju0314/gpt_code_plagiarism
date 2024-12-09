#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;
template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}
int main() {
  cin.tie(0);
  cout << fixed << setprecision(10);
  while(1) {
    ll n, i, j; cin >> n >> j >> i;
    i--; j--;
    if(n == 0) break;
    vector<ll> v(n);
    ll tmp = 1;
    for(int i=0;i<n;++i) {
      v[i] = tmp;
      tmp *= 2;
    }
    reverse(v.begin(), v.end());
    string ans = "";
    for(ll k=0;k<n;++k) {
      if(i%2 == j%2) {
        ans.push_back('L');
      } else {
        ans.push_back('R');
      }
      i = i / 2;
      if(j - v[k] >= 0) {
        j = j - v[k];
      } else {
        j = v[k] - j - 1;
      }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
  }
}

