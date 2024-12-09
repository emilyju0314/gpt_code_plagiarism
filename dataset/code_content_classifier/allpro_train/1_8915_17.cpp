#include <bits/stdc++.h>
using namespace std;
#define r(i,n) for(int i=0;i<n;i++)
typedef pair<int,int>P;
 
int dp[100009][2];
int c[100009];
vector<int>v[100009];
bool so[2000009];
bool used[100009][2];
 
 
int main(){
 
  so[0]=so[1]=1;
 
  for(int i=2;i<=2000000;i++)if(!so[i]){
    for(int j=i+i;j<=2000000;j+=i) so[j]=1;
  }
 
 
  int n,m,s,t;
  cin>>n>>m>>s>>t;s--;t--;
  r(i,m){
    int a,b;
    cin>>a>>b;
    a--;b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
 
  queue<P>q;
  q.push(P(s,0));
  used[s][0]=1;
  while(!q.empty()){
    int x=q.front().first;
    int y=q.front().second;q.pop();
    r(i,v[x].size()){
      int nex=v[x][i];
      int cost=dp[x][y]+1;
      if(!used[nex][cost%2]){
        used[nex][cost%2]=1;
        dp[nex][cost%2]=cost;
        q.push(P(nex,cost%2));
      }
    }
  }
  if(dp[t][0]==2)cout<<2<<endl;
  else if(!used[t][1])cout<<-1<<endl;
  else{
    while(so[dp[t][1]])dp[t][1]+=2;
    cout<<dp[t][1]<<endl;
  }
}
