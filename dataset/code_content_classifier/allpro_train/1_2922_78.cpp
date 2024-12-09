#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long> ans(n,0);
  for(int i=0; i<n-1; ++i){
    int c, s, f;
    cin >> c >> s >> f;
    for(int j=0; j<=i; ++j){
      ans[j] = max(ans[j], (long long)s);
      if(ans[j] % f >0){
        ans[j] /= f;
        ++ans[j];
        ans[j] *= f;
      }
      ans[j] += c;
    }
  }
  for(int i=0; i<n; ++i) cout << ans[i] << endl;
}