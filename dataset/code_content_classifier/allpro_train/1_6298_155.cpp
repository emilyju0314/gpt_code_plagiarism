#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,k;
  cin >> n>>k;
  vector<long> h(n);
  long a=1000000000;
  for(int i=0; i<n; i++) cin >> h[i];
  sort(h.begin(),h.end());
  for(int i=0; i<n-k+1; i++){
  	a=min(h[i+k-1]-h[i],a);
  }
  
  
    cout << a << endl;
}