#include<bits/stdc++.h>
using namespace std;

using Graph=vector<vector<int>>;
int main(){
  int n;
  cin>>n;
  vector<int> upper(n+1);
  vector<int> self(n+1);
  self[n]=true;

  Graph g(n);
  for(int i=0;i<n;i++){
    int m;
    cin>>m;
    while(m--){
      int x;
      cin>>x;
      x--;
      if(x==i) self[i]=true;
      if(x<i) g[x].push_back(i);
      if(i<x) upper[i]=true;
    }
  }
  vector<int> flag(n);
  int res=0;
  int l=0;
  for(int i=0;i<=n;i++){
    if(self[i] || flag[i]){
      res++;
      while(l<i){
	for(auto to:g[l]) flag[to]=false;
	l++;
      }
    }
    else if(upper[i]){
      for(auto to:g[i]) flag[to]=true;
    }
    else{
      while(l<i){
	for(auto to:g[l]) flag[to]=false;
	l++;
      }
    }
  }
  cout<<res-1<<endl;
  
  return 0;
}

