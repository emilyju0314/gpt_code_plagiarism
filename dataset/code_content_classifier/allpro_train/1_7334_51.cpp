#include <iostream>
#define ll long long
using namespace std;

int main(){
  ll n; cin>>n;
  ll sum=0; ll q;
  
  for(int i=1;i<=n;i++){
    q=n/i;
    sum = sum + i*q*(q+1)/2;
  }
  
  cout<<sum;
  
  return 0;
}