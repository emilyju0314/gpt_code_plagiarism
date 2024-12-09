#include <bits/stdc++.h>
using namespace std;

int main() {
  string S,T;
  cin>>S>>T;
  int N=S.size(),M=T.size();
  int Z=18972;
  for(int i=0;i<=N-M;i++){
    int A=0;
    for(int j=0;j<M;j++){
      if(S[i+j]!=T[j]){
        A++;
      }
    }
    Z=min(Z,A);
  }
  cout<<Z<<endl;
}