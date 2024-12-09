#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,A,B,j=0;
  cin>>N>>A>>B;
  for(int i=1;i<=N;i++){
    int l=0;
    for(int k=i;k>0;k/=10)
      l+=k%10;
    if(A<=l && l<=B)
      j+=i;
  }
  cout<<j<<endl;
}