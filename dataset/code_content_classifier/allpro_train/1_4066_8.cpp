#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define chmax(a,b) (a<(b)?(a=b,1):0)
#define chmin(a,b) (a>(b)?(a=b,1):0)
#define valid(y,x,h,w) (0<=y&&y<h&&0<=x&&x<w)
const int INF = 1<<29;
const double EPS = 1e-8;
const double PI = acos(-1);
typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

struct CHT {
  vector<pll> deq;              // first * x + second
  ll s,t;
  CHT(ll n) {
    deq.resize(n);
    s=0, t=0;
  }
  void add(ll a, ll b) {      // a : non increasing
    const pll p(a,b);
    while(s+1<t && check(deq[t-2],deq[t-1],p)) t--;
    deq[t++] = p;
  }
  ll incl_query(ll x) {            // x : non decreasing
    if (s==t) {
      return 1LL<<55;
    }
    while(s+1<t && f(deq[s], x) >= f(deq[s+1], x)) s++;
    return f(deq[s], x);
  }
  ll query(ll x) {           // without condition
    ll low = s-1, high = t-1;
    while(low+1<high) {
      ll mid = low+high>>1;
      if (isright(deq[mid], deq[mid+1], x)) low = mid;
      else high = mid;
    }
    return f(deq[high], x);
  }
private:
  bool isright(const pll &p1, const pll &p2, ll x) {
    return (p1.second-p2.second) >= x * (p2.first-p1.first);
  }
  bool check(const pll &p1, const pll &p2, const pll &p3) {
    return (p2.first-p1.first)*(p3.second-p2.second) >=
      (p2.second-p1.second)*(p3.first-p2.first);
  }
  ll f(const pll &p, ll x) {
    return p.first * x + p.second;
  }
};

ll p[10000];
ll c[10000];
ll dp[10001][101];

int main() {
  ll n,m,d,x;
  while(cin>>n>>m>>d>>x) {
    REP(i,n) {
      cin >> p[i];
    }
    REP(i,m) {
      int a, b;
      cin >> a >> b;
      if (b > 0) {
        // y = (x-a) + b = 0
        // x = a - b
        c[i] = a-b;
      } else {
        // y = -(x-a) + b = 0
        // x = a + b
        c[i] = a+b;
      }
    }
    sort(c,c+m);
    vector<CHT> cht(d+1, n);
    vector<ll> id(d+1,0);
    REP(i,n)REP(k,d+1)dp[i][k] = 1LL<<50;
    dp[0][0] = 0;
    while(id[0]<m&&c[id[0]]<p[0]) id[0]++;
    cht[0].add(m-id[0], dp[0][0]-p[0]*(m-id[0]));
    REP(i,n) {
      for (int k=d; k>=1; --k) {
        while(id[k]<m&&c[id[k]]+x*k<p[i]) id[k]++;
        dp[i][k] = cht[k-1].incl_query(p[i]);
        // cout << dp[i][k] << "," << m-id[k] << " " ;
        cht[k].add(m-id[k], dp[i][k]-p[i]*(m-id[k]));

      }
      // cout << endl;
    }
    cout << *min_element(dp[n-1], dp[n-1]+d+1) << endl;
  }
}