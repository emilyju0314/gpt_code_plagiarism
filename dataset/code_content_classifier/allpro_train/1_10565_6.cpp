#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)

#define CHMIN(a,b) (a)=min((a),(b))
#define CHMAX(a,b) (a)=max((a),(b))

typedef long long ll;

int N,A,B;
int a[830], b[830];
int c[830];

bool g[830][830];

int main(){
  scanf("%d%d%d",&N,&A,&B);
  REP(i,N)scanf("%d%d",a+i,b+i);
  REP(i,N)c[i] = a[i]-b[i];
  int ans = 0;
  vector<int> pos, neg;
  REP(i,N){
    if(abs(c[i])<=A || (B<=abs(c[i]) && abs(c[i])<=2*A)){
      ans++;
    }else{
      (c[i]<0 ? neg : pos).push_back(c[i]);
    }
  }
  int n = pos.size(), m = neg.size();
  REP(i,n)REP(j,m){
    int x = pos[i] + neg[j];
    if(abs(x)<=A || (B<=abs(x) && abs(x)<=2*A)){
      g[i][n+j] = true;
    }else{
      g[i][n+j] = false;
    }
  }
  int s = n+m;
  int t = n+m+1;
  REP(i,n)g[s][i] = true;
  REP(j,m)g[n+j][t] = true;
  while(true){
    vector<int> bef(n+m+2, -1);
    vector<bool> used(n+m+2, false);
    stack<int> S;
    S.push(s);
    used[s] = true;
    while(!S.empty()){
      int p = S.top(); S.pop();
      REP(to,n+m+2)if(!used[to]){
        if(!g[p][to])continue;
        used[to] = true;
        bef[to] = p;
        S.push(to);
      }
    }
    if(!used[t])break;
    int cur = t;
    while(cur != s){
      int b = bef[cur];
      g[b][cur] = false;
      g[cur][b] = true;
      cur = b;
    }
    ans++;
  }
  printf("%d\n",ans);
  return 0;
}
