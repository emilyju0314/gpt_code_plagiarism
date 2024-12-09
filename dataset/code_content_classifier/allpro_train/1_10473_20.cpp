#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb push_back
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

int h,w,n;
string s[55];
ll c[55][55][3]; // 0 using / 1 on / 2 off
ll vi[1111],vj[1111];
ll dist[55][55];
vector<ll> t[55][55];
ll dp[1010][2];

int dd[]={-1,0,1,0,-1};

void dfs(int i,int j,int prei,int prej,ll sum,ll dst[55][55]){
  dst[i][j]=sum;
  rep(d,4){
    int ni=i+dd[d],nj=j+dd[d+1];
    if(ni==prei&&nj==prej)continue;
    if(ni>=0&&ni<h&&nj>=0&&nj<w&&s[ni][nj]!='#')dfs(ni,nj,i,j,sum+1,dst);
  }
}

int main(){
	cin.sync_with_stdio(false);
  cin>>h>>w>>n;
  rep(i,h)cin>>s[i];
  rep(k,3)rep(i,h)rep(j,w)cin>>c[i][j][k];
  rep(i,n)cin>>vi[i]>>vj[i];
  ll nt=0;
  t[vi[0]][vj[0]].push_back(0);
  rep(i,n-1){
    memset(dist,0,sizeof(dist));
    dfs(vi[i],vj[i],-1,-1,0,dist);
    ll ni=vi[i+1],nj=vj[i+1];
    while(dist[ni][nj]!=0){
      t[ni][nj].push_back(nt+dist[ni][nj]);
      rep(d,4){
        int nni=ni+dd[d],nnj=nj+dd[d+1];
        if(ni>=0&&ni<h&&nj>=0&&nj<w&&dist[nni][nnj]+1==dist[ni][nj]){
          ni=nni; nj=nnj;
          break;
        }
      }
    }
    nt+=dist[vi[i+1]][vj[i+1]];
  }
  ll res=0;
  rep(i,h)rep(j,w){
    if(t[i][j].size()==0)continue;
    rep(k,1010)rep(l,2)dp[k][l]=INF;
    dp[1][0]=c[i][j][1]+c[i][j][2];
    dp[1][1]=c[i][j][1];
    ll m=t[i][j].size();
    repl(k,1,m)rep(l,2){
      if(dp[k][l]==INF)continue;
      ll pt=t[i][j][k]-t[i][j][k-1];
      if(l==0){
        minch(dp[k+1][0],dp[k][l]+c[i][j][1]+c[i][j][2]);
        minch(dp[k+1][1],dp[k][l]+c[i][j][1]);
      }else{
        minch(dp[k+1][0],dp[k][l]+c[i][j][2]+pt*c[i][j][0]);
        minch(dp[k+1][1],dp[k][l]+pt*c[i][j][0]);
      }
    }
    //dbg(dp[m][0]);
    res+=dp[m][0];
  }
  cout<<res<<endl;
	return 0; 
}