#include <bits/stdc++.h>
using namespace std;

int main(){
  long n, m, k, tmp;  cin >> n >> m >> k;
  vector<long> a(n+1, 0), b(m+1, 0);
  for(int i=1; i<=n; i++){
    cin >> tmp;
    a[i] = a[i-1] + tmp;
  }
  for(int i=1; i<=m; i++){
    cin >> tmp;
    b[i] = b[i-1] + tmp;
  }
  int b_idx = m, ans = 0;
  for(int i=0; i<=n; i++){
    if(a[i] > k)  break;
    while(a[i] + b[b_idx] > k)  b_idx--;
    ans = max(ans, i+b_idx);
  }

  cout << ans << endl;

  return 0;
}
