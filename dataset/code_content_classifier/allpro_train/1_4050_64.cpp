#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  
  vector<vector<int>> x(m, vector<int>(2));
  for(int i = 0; i < m; i++) cin >> x.at(i).at(1) >> x.at(i).at(0);
  
  sort(x.begin(), x.end());
  
  int now = 0, ans = 0;
  for(int i = 0; i < m; i++){
    if(x.at(i).at(1) > now){
      now = x.at(i).at(0) - 1;
      ans++;
    }
  }
  
  cout << ans << endl;
}