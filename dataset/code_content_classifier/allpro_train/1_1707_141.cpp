#include <bits/stdc++.h>
using namespace std;

int main(){
  long long A,V,B,W,T;cin>>A>>V>>B>>W>>T;
  cout<<((V-W)*T>=abs(A-B)?"YES":"NO")<<endl;
}
