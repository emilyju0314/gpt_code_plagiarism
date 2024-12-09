#include <bits/stdc++.h>
using namespace std;


int main() {
  long long N,M;
  cin>>N>>M;
  
  map<long long,long long> kaz;
  for(int i=0;i<N;i++){
    long long a,b;
    cin>>a>>b;
    kaz[a]+=b;
  }
  long long sum=0;
  for(auto &x:kaz){
    if(x.second<M){
      sum+=x.first*x.second;
      M-=x.second;
    }
    else{
      sum+=x.first*M;
      break;
    }
  }
  cout<<sum<<endl;
    
  
}