#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

struct Data{
  int L,R;//[L,R]
  long long sum;
  Data(int L=0,int R=0,long long sum=0):L(L),R(R),sum(sum){}
  bool operator < (const Data& data)const{
    if( sum != data.sum ) return sum < data.sum;
    return L > data.L;
  }
};


const int IINF = INT_MAX, MAX = 4010;

int n,pre[MAX][MAX],dp[MAX];
ll sum[MAX];

int main(){
  cin >> n;
  vector<ll> A(n);
  rep(i,n){
    cin>>A[i];
    if( i == 0 ) sum[i] = A[i];
    else         sum[i] = sum[i-1] + A[i];
  }

  vector<Data> buf;
  rep(i,n+1)REP(j,i+1,n+1)buf.push_back(Data(i,j,sum[j-1]-((i-1>=0)?sum[i-1]:0LL)));
  sort(buf.begin(),buf.end());
  rep(i,MAX)dp[i] = -IINF;
  rep(i,MAX)rep(j,MAX)pre[i][j] = IINF;

  dp[0] = 0LL;

  rep(i,buf.size()){
    int cur = buf[i].L, next = buf[i].R;
    //cout << "buf[" << i << "] = " << cur << "," << next << " " << buf[i].sum << endl;
    if( dp[cur] == -IINF ) continue;
    if( dp[next] < dp[cur] + 1 ){
      //cout << "update dp[" << next << "] = " << dp[cur] + 1 << " pre[" << next << "] = " << cur << endl;
      dp[next] = dp[cur] + 1;
      pre[dp[next]][next] = cur;
    }
  }


  int cur = n,cnt = IINF;
  vector<int> path;

  for(int i = MAX-1; i >= 0; i-- ) if( pre[i][cur] != IINF ){
      cnt = i;
      break;
    }

  assert( cnt != IINF );
  while( cnt >= 0 && pre[cnt][cur] != IINF ){
    path.push_back(cur);
    cur = pre[cnt][cur];
    cnt--;
  }

  if( !path.empty() )reverse(path.begin(),path.end());
  if( path.size() >= 1)path.erase(path.end()-1);

  cout << path.size() + 1 << endl;
  rep(i,path.size()) {
    if( i ) cout << ' ';
    cout << path[i];
  } cout << endl;

  return 0;
}