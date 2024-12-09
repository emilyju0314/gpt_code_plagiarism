#include <iostream>
 
using namespace std;
 
int main(){
 
  while(1) {
 
  int N;
  cin >> N;
  if(N == 0) break;
 
  int b[100000];
   
  for(int i=0;i<N;i++) {
    cin >> b[i];
  }
 
  int count = 0,flag = 2;
  int t;
 
  while(1) {
    for(int i=1;i<=N;i++) {
      if(b[i-1] != i) break;
 
      if(i == N) flag = 0;
    }
     
    if(flag == 0) break;
 
    count++;
    if(count > 10000) {
      flag = 1;
      break;
    }
    t = N;
    for(int i=0;i<N;i++) b[i]--;
 
    for(int i=0;i<N;i++) {
      if(b[i] == 0) {
    for(int j=i;j<N-1;j++) {
      b[j] = b[j+1];
    }
    N--;
    i--;
      }
    }
    N++;
    b[N-1] = t;
 
    //  for(int i=0;i<N;i++) cout << b[i] <<" ";
    //cout << endl;
 
  }
 
 
  if(flag == 1) cout << "-1"<<endl;
  else cout << count << endl;
 
  }
 
  return 0;
}