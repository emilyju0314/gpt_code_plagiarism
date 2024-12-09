#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k,a=1;
  cin>>n>>k;
  for(int i=0;i<n;i++){
    a+=(a<k?a:k);
  }
  cout<<a<<endl;
  return 0;
}