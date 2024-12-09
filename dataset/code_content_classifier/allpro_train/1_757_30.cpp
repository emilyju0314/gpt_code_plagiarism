#include<bits/stdc++.h>
using namespace std;
int N;
long long A,S,res;
map<long long,long long>mp;
int main(){
  cin>>N;
  mp[0]=1;
  while(N--){
    cin>>A;
    S+=A;
    ++mp[S];
  }
  for(auto it=mp.begin();it!=mp.end();++it){
    res+=it->second*(it->second-1)/2;
  }
  cout<<res<<endl;
}