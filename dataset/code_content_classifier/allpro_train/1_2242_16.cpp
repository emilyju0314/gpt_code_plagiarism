#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  int n,q;
  cin>>n>>q;
  vector< queue<int> > qs(n);
  for(int i=0;i<q;i++){
    int t,x;
    cin>>t>>x;
    if(t==0){
      x--;
      cout<<qs[x].front()<<"\n";
      qs[x].pop();
    }
    if(t==1){
      int k=0;
      for(int j=0;j<n;j++)
        if(qs[j].size()<qs[k].size()) k=j;
      qs[k].emplace(x);
    }
  }
  return 0;
}

