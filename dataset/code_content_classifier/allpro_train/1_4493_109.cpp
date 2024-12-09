#include <bits/stdc++.h>
using namespace std;
 
int N, M;
int A[3];
vector<int> G[51];
bool used[51];
bool dp[101][51][51];  // a step, b start, c goal
 
int main(){
 
  cin>>N>>M;
  for(int i=0;i<3;i++)cin>>A[i];
  for(int i=0;i<M;i++){
    int f,t;
    cin>>f>>t;
    f--;t--;
    G[f].push_back(t);
  }
  int ite = 0;
 
  for(int i=0;i<N;i++)
    dp[0][i][i] = true;
  for(int i=1;i<101;i++){
    for(int j=0;j<N;j++){
      for(int k=0;k<N;k++){
        if(dp[i-1][j][k]){
          for(int to : G[k]){
            dp[i][j][to] = true;
          }
        }
      }
    }
  }
   
  used[N-1] = true;
  while(1){
    bool ok = false;
    vector<int> idx;
    for(int i=0;i<N;i++){
      if(used[i])continue;
      int cnt = 0;
      for(int j=0;j<3;j++){
        int a = A[j];
        bool t = false;
        for(int k=0;k<N;k++){
          if(dp[a][i][k] && used[k]){
            t = true;
          }
        }
        if(t){
          cnt++;
        }
      }
      // OK
      if(cnt == 3){
        ok=true;
        idx.push_back(i);
      }
    }
    if(ok){
      ite++;
      for(int i : idx){
        used[i]=true;
      }
      if(used[0]){
        cout<<ite<<endl;
        return 0;
      }
    }
    else{
      break;
    }
  }
  cout<<"IMPOSSIBLE"<<endl;
   
  return 0;
}