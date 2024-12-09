#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A,B,a=0,b=0,c=0;
  cin >> N >> A >> B;
  for(int i=0; i<N; i++){
    int P;
    cin >> P;
    if(P<=A){
      a++;
    }
    else if(P<=B){
      b++;
    }
    else{
      c++;
    }
  }
  cout << min(a,min(b,c)) << endl;
}
