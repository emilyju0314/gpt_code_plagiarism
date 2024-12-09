#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
const double EPS = 1e-15;
using ll = long long;
using ull = unsigned long long;
const int inf = 2e9;
const ll INF = 2e18;
const ll MOD = 1e9+7;
const ll MOD1 = 998244353;
typedef pair<int,int> P;

#define REP(i,n) for (int i = 0; i < (n); i++)
#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second
#define mp make_pair

int main(){
ll n, sum = 0, ans = 0;
std::map<ll, ll> a;
a[0] = -1;
scanf("%lld", &n);
REP(i, n){
  ll tmp;
  scanf("%lld", &tmp);
  sum += tmp;
  auto it = a.find(sum);
  if(it == a.end()) a[sum] = i;
  else ans = max(ans, i - it->second);
}
printf("%lld\n", ans);
}
