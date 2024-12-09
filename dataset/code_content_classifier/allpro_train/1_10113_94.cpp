#include<iostream>

using namespace std;

int main(){
  int i,j,N,M,C,A[25][25],B[25],c=0,t[25]={};
  cin>>N>>M>>C;
  for(i=0;i<M;i++) cin>>B[i];
  for(i=0;i<N;i++){
    for(j=0;j<M;j++){
      cin>>A[i][j];
      t[i]+=A[i][j]*B[j];
    }
  }
  for(i=0;i<N;i++){
    if(t[i]+C>0) c++;
  }
  cout<<c<<endl;
  return 0;
}
