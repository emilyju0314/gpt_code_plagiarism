#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,k,a; cin>>n>>k; a=k;
  for(int i=1; i<n; i++) a*=k-1;
  cout<<a;
}