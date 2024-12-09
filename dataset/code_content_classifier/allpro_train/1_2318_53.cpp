#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a=0;cin>>n;
  vector<int>d(n);
  for(int i=0;i<n;i++)cin>>d.at(i);
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++)a+=d.at(i)*d.at(j);
  }
  cout<<a<<endl;
}