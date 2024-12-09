#include <iostream>
using namespace std;
int main() {
  int N;cin>>N;
  while(N>0) {
    int v[5],b=0,f=0,d[]={0,0,0,1,0,3,2,0};
    for(;b<5;++b) {
      v[b]=N;f|=1<<--N;cin>>N;
    }
    for(b=0;b<5;++b) cout<<((v[b]==d[f])?1:(d[f]?2:3))<<endl;
  }
  return 0;
}