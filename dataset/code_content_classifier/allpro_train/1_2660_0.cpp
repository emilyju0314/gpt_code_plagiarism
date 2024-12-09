#include<bits/stdc++.h>
using namespace std;
int id[200010];
int root(int i){
  return !id[i]?i:id[i]=root(id[i]);
}
int main(){
  int n,q; cin>>n>>q;
  while(q--){
    int t,u,v; cin>>t>>u>>v; u++, v++;
    if(t){
      cout<<(root(u)==root(v))<<"\n";
    } else{
      if(root(v)!=root(u))
      	id[root(v)]=root(u);
    }
  }
}