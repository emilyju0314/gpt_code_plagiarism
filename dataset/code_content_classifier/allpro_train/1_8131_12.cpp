#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

int N,t[1000];

int dp[2][1000];
int rec(int sec,int last){
  if(dp[sec][last]>=0)return dp[sec][last];
  int &ret=dp[sec][last];
  
  if(last<=1)return last==0||sec?t[0]:t[1];
  if(last==2&&sec)return t[2];
  
  ret=(int)1e9;
  if(sec==0){
    ret=min(ret,rec(1,last)+t[0]+t[1]);
  }
  else{
    if(last>2)ret=min(ret,rec(0,last-2)+t[last]+t[1]);
    ret=min(ret,rec(1,last-1)+t[last]+t[0]);
  }
  return ret;
}
int main(){
  scanf("%d",&N);
  rep(i,N)scanf("%d",t+i);
  sort(t,t+N);
  
  if(N<=2){
    printf("%d\n",N==1?t[0]:t[1]);
    return 0;
  }
  
  memset(dp,-1,sizeof(dp));
  printf("%d\n",rec(0,N-1));
  
  return 0;
}
