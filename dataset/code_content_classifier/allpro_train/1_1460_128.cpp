#include<iostream>

using namespace std;

int main(){
  int N;cin>>N;
  long long ax[N],bx[N];
  for (int i=0;i<N;i++){
    cin>>ax[i]>>bx[i];
  }
  long long cnt=0;
  long long k = 0;
  for (int i=N-1;i>=0;i--){
    if ((ax[i] + cnt) % bx[i] !=0){
      k = bx[i] - ((ax[i] + cnt) % bx[i]);
      cnt += k;
    }
}
  cout<<cnt<<endl;
}
