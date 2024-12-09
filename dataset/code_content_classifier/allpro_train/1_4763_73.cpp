#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  int n;
  cin>>n;
  int ans=n;  
  for(int i=0;i<10;i++){
    int tmp=n-i*10,res=i;   
    if(tmp<0) continue;
    res+=tmp/25;tmp%=25;
    res+=tmp/5;tmp%=5;
    res+=tmp/1;tmp%=1;
    chmin(ans,res);
  }
  cout<<ans<<endl;
  return 0;
}

