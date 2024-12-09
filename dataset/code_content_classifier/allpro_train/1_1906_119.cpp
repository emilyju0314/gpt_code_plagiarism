#include<bits/stdc++.h>
using namespace std;
signed main(){
  stack<int>a[10000];
  int b,c,d;
  int q,w;
  cin>>q>>w;
  for(int i=0;i<w;i++){
    cin>>b>>c;
    if(b==0) cin>>d,a[c].push(d);
    if(b==1) if(!a[c].empty()) cout<<a[c].top()<<"\n";
    if(b==2) if(!a[c].empty()) a[c].pop();
  }
}

