#include <bits/stdc++.h>
using namespace std;

int main() {
  long N,A,B,i,counter=0;
  cin >> N;
  for(i=1;i<=N;i++){
    counter=counter+((N-1)/i);
  }
  cout<<counter;
}