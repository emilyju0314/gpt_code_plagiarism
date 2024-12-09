#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


struct Precision{
  Precision(){
    cout<<fixed<<setprecision(12);
  }
}precision_beet;

//INSERT ABOVE HERE
signed main(){
  int n;
  cin>>n;
  vector<int> h(n);
  for(int i=0;i<n;i++) cin>>h[i];

  const int MAX = 400;
  vector<double> dp(MAX,1e15);
  dp[1]=0;
  for(int i=0;i<n;i++){    
    vector<double> nx(MAX,1e15);
    for(int j=1;j<MAX;j++){
      for(int k=1;k<MAX;k++){
        double di=0;
        if(h[i]<=j&&h[i]<=k) di=(j-h[i])+(k-h[i]);
        else if(j<=h[i]&&k<=h[i]) di=(h[i]-j)+(h[i]-k);
        else{
          int a=h[i]-min(j,k),b=max(j,k)-h[i];
          assert(a>0&&b>0);
          di=double(a*a+b*b)/(a+b);
        }          
        chmin(nx[k],dp[j]+di/2.0);        
      }
    }    
    swap(dp,nx);
  }
  cout<<*min_element(dp.begin(),dp.end())<<endl;
  return 0;
}

