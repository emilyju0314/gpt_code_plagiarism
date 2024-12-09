#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF 1e16
#define mod 1000000007

ll sum(ll a){
  return a*(a+1)/2;
}

ll sqsum(ll a){
  return a*(a+1)*(2*a+1)/6;
}

ll qsum(ll a){
  return sum(a)*sum(a);
}

ll n,m;
vector<P> qs;
ll cnt[3][50001],cntjust[3][50001];

int main(){
  cin>>n>>m;
  rep(i,m){
    ll q,k;
    cin>>q>>k;
    if(q==0){
      ll lb=0,ub=n+1;
      while(ub-lb>1){
        ll mid=(ub+lb)/2;
        if(sum(mid)<k)lb=mid;
        else ub=mid;
      }
      k=ub;
    }
    if(k>n)continue;
    qs.push_back(P(q,k));
    cnt[q][k]++;
    cntjust[q][k]++;
  }
  rep(i,3)rep(j,n)cnt[i][j+1]+=cnt[i][j];
  m=qs.size();
  ll add=0,sub=0;
  rep(i,m){
    ll q=qs[i].fi,k=qs[i].se;
    if(q==0){
      sub+=k*k;
    }else{
      sub+=sqsum(n)-sqsum(k-1);
    }
  }

  rep(i,m){
    ll q=qs[i].fi,k=qs[i].se;
    if(q==0){
      add+=k*(cnt[1][k]+cnt[2][k]);
    }else if(q==1){
      add+=(sum(n)-sum(k-1))*cnt[2][k-1];
      add+=(sum(n)-sum(k-1))*cntjust[2][k];
    }else if(q==2){
      add+=(sum(n)-sum(k-1))*cnt[1][k-1];
    }
  }

  rep(i,m){
    ll q=qs[i].fi,k=qs[i].se;
    if(q==0){
      sub+=cnt[1][k]*cnt[2][k];
    }
  }

  cout<<qsum(n)+add-sub<<endl;
  return 0;
}

