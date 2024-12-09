#include <bits/stdc++.h>
using namespace std;
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define fi first
#define se second
#define dbg(...) _dbg(#__VA_ARGS__",", __VA_ARGS__)
void _dbg(string){cout<<endl;}
template<class H,class... T> void _dbg(string s,H h,T... t){int l=s.find(',');cout<<s.substr(0,l)<<" = "<<h<<", ";_dbg(s.substr(l+1),t...);}
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define INF 1120000000

int main(){
  long T; int n;
  cin>>T>>n;
  vector<long> s(n),t(n);
  rep(i,n) cin>>s[i]>>t[i];

  auto solve = [&](){
    long mx = 0;
    long crnt = 0;
    int j = 0;
    rep(i,n){
      // t[i]?????§?????????
      crnt += t[i]-s[i];
      while(j<n && s[j] < t[i]-T){
        if(crnt - (t[j]-s[j]) <= T && t[i] - T <= t[j]) mx = max(mx, crnt - (t[j]-s[j]) + t[j] - (t[i]-T));
        crnt -= t[j]-s[j];
        j++;
      }//dbg(crnt);
      mx = max(mx, crnt);
    }
    return mx;
  };

  long ans = solve();

  rep(i,n) s[i]*=-1, t[i]*=-1, swap(s[i],t[i]);
  reverse(all(s)); reverse(all(t));

  ans = max(ans, solve());

  cout << ans << endl;

  return 0;
}