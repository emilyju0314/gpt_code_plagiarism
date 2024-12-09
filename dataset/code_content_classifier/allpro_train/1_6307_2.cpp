#include<bits/stdc++.h>
using namespace std;
#define int long long
string A[20];

int n;
bool used[1<<18][10][10],mem[1<<18][10][10];
bool dfs(int bit,int l,int r){
  if(bit == (1<<n)-1) return 1;
  if(used[bit][l][r])return mem[bit][l][r];
  used[bit][l][r] = 1;
  
  bool res = 0;
  for(int i=0;i<n;i++){
    if(bit>>i&1) continue;
    int nbit = bit | (1<<i);
    
    if(l == A[i][0]-'0') res |= dfs(nbit,A[i][1]-'0',r);
    if(l == A[i][1]-'0') res |= dfs(nbit,A[i][0]-'0',r);
    if(r == A[i][0]-'0') res |= dfs(nbit,l,A[i][1]-'0');
    if(r == A[i][1]-'0') res |= dfs(nbit,l,A[i][0]-'0');
    if(res) break;
  }
  return mem[bit][l][r] = res; 
}

signed main(){

  while(cin>>n){
    for(int i=0;i<n;i++) cin>>A[i];
    memset(used,0,sizeof(used));
    memset(mem,0,sizeof(mem));
    bool ans = dfs(1,A[0][0]-'0',A[0][1]-'0');
    cout<<(ans? "Yes":"No") <<endl;
  }
  return 0;
}