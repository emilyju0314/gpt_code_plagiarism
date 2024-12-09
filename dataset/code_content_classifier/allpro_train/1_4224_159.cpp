#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
  int H,W,N;cin>>H>>W>>N;
  vector<pair<int,int>>XY(N);
  for(pair<int,int> &xy:XY)cin>>xy.first>>xy.second;
  sort(XY.begin(),XY.end());
  int ans=H;
  int h=0;
  for(pair<int,int> xy:XY){
    if(xy.first==xy.second+h)h++;
    else if(xy.first>=xy.second+h+1){ans=xy.first-1;break;}
  }
  cout<<ans<<endl;
}