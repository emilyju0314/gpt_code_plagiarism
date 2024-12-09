#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,x,y=0,c;cin>>n>>x;
  vector<int>a(n);for(int i=0;i<n;i++)cin>>a.at(i);
  sort(a.begin(),a.end());
  for(int i=0;i<n;i++){
    y+=a.at(i);
    if(y>x){c=i;break;}
    else if(i==n-1){
      if(y<x)c=n-1;
      else c=n;
    }
  }
  cout<<c<<endl;
}
