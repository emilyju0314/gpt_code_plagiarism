#include <bits/stdc++.h>
using namespace std;

int main(){
  int K,N,j=0;
  cin>>K>>N;
  vector<int> A(N);
  for(int &i:A)
    cin>>i;
  for(int i=0;i<N;i++)
    j=max(j,(A.at((i+1)%N)+K-A.at(i))%K);
  cout<<K-j<<endl;
}