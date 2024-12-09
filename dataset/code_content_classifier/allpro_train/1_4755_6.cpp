#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

// mod
const ll MOD = 1000000007ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

// floating
typedef double Real;
const Real EPS = 1e-11;
#define EQ0(x) (abs(x)<EPS)
#define EQ(a,b) (abs(a-b)<EPS)
typedef complex<Real> P;

int h,w;
char mp[25][25];

bool oldp[1<<16];
string oneline(string s){
  int n = s.size();
  int beg = 0;
  int goal = 0;
  REP(i,n){
    if(s[i]=='o'){
      beg |= 1<<i;
    }
    if(s[i]=='@'){
      goal = i;
    }
  }
  oldp[beg] = true;
  queue<int> Q;
  Q.push(beg);
  while(!Q.empty()){
    int po = Q.front(); Q.pop();
    REP(i,n){
      if((po>>i)&1){
        // to right
        int nxt = po;
        FOR(j,i,n-1){
          if(j==i){
            nxt ^= (1<<j);
          }
          if(((nxt>>(j+1))&1)==1){
            nxt ^= (1<<j);
            if(j<n-2){
              nxt ^= (1<<(j+1));
            }
          }else if(j==n-2){
            nxt ^= (1<<(j+1));
          }
        }
        if((nxt>>goal)&1)return "yes";
        if(!oldp[nxt]){
          oldp[nxt] = true;
          Q.push(nxt);
        }
        // to left
        nxt = po;
        FORR(j,1,i+1){
          if(j==i){
            nxt ^= (1<<j);
          }
          if(((nxt>>(j-1))&1)==1){
            nxt ^= (1<<j);
            if(j>1){
              nxt ^= (1<<(j-1));
            }
          }else if(j==1){
            nxt ^= (1<<(j-1));
          }
        }
        if((nxt>>goal)&1)return "yes";
        if(!oldp[nxt]){
          oldp[nxt] = true;
          Q.push(nxt);
        }
      }
    }
  }
  return "no";
}

int dp[353][353];
void dfs(int ai,int aj,int bi,int bj){
  int aid = ai*w+aj;
  int bid = bi*w+bj;
  if(dp[aid][bid])return;
  dp[aid][bid] = true;
  int ani,anj,bni,bnj;
  if(ai==bi){
    if(aj<bj){
      dfs(ai,0,bi,bj);
      dfs(ai,0,bi,aj+1);
      dfs(ai,aj,bi,w-1);
      dfs(ai,bj-1,bi,w-1);
    }else{
      dfs(ai,aj,bi,0);
      dfs(ai,bj+1,bi,0);
      dfs(ai,w-1,bi,bj);
      dfs(ai,w-1,bi,aj-1);
    }
    dfs(0,aj,bi,bj);
    dfs(h-1,aj,bi,bj);
    dfs(ai,aj,0,bj);
    dfs(ai,aj,h-1,bj);
  }else if(aj==bj){
    if(ai<bi){
      dfs(0,aj,bi,bj);
      dfs(0,aj,ai+1,bj);
      dfs(ai,aj,h-1,bj);
      dfs(bi-1,aj,h-1,bj);
    }else{
      dfs(ai,aj,0,bj);
      dfs(bi+1,aj,0,bj);
      dfs(h-1,aj,bi,bj);
      dfs(h-1,aj,ai-1,bj);
    }
    dfs(ai,0,bi,bj);
    dfs(ai,w-1,bi,bj);
    dfs(ai,aj,bi,0);
    dfs(ai,aj,bi,w-1);
  }else{
    dfs(0,aj,bi,bj);
    dfs(h-1,aj,bi,bj);
    dfs(ai,aj,0,bj);
    dfs(ai,aj,h-1,bj);
    dfs(ai,0,bi,bj);
    dfs(ai,w-1,bi,bj);
    dfs(ai,aj,bi,0);
    dfs(ai,aj,bi,w-1);
  }
}

int main(){
  scanf("%d%d",&h,&w);
  REP(i,h)scanf("%s",mp[i]);
  if(h==1){
    string s;
    REP(i,w)s+=mp[0][i];
    puts(oneline(s).c_str());
  }else if(w==1){
    string s;
    REP(i,h)s+=mp[i][0];
    puts(oneline(s).c_str());
  }else{
    int n = 0;
    REP(i,h)n+=count(mp[i],mp[i]+w,'o');
    if(n>=3){
      puts("yes");
    }else{
      int gi,gj;
      REP(i,h)REP(j,w)if(mp[i][j]=='@'){
        gi=i;
        gj=j;
      }
      if(n==1){
        int si,sj;
        REP(i,h)REP(j,w)if(mp[i][j]=='o'){
          si=i;
          sj=j;
        }
        if((gi==si || gi==0 || gi==h-1)&&(gj==0 || gj==w-1)){
          puts("yes");
        }else if(gj==sj&&(gi==0 || gi==h-1)){
          puts("yes");
        }else{
          puts("no");
        }
      }else{
        int ai,aj,bi,bj;
        ai=-1;
        REP(i,h)REP(j,w){
          if(mp[i][j]=='o'){
            if(ai==-1){
              ai=i;
              aj=j;
            }else{
              bi=i;
              bj=j;
            }
          }
        }
        dfs(ai,aj,bi,bj);
        int id = gi*w+gj;
        bool ok = false;
        REP(i,h*w){
          ok |= dp[id][i];
          ok |= dp[i][id];
        }
        if(ok){
          puts("yes");
        }else{
          puts("no");
        }
      }
    }
  }
  return 0;
}