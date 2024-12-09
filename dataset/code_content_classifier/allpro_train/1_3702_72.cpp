#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N,K;
  cin >> N >> K;
  long int Case=0;
  for (long int i=K; i<N+2; i++){
    Case += (N-i+1)*i + 1;
  }
  cout << Case % 1000000007 <<endl;
}