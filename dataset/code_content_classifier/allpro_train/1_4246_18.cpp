#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  cin >> m;
  vector<int> b(m);
  for(int i = 0; i < m; i++){
    cin >> b[i];
  }
  for(int i : b){
    if(!binary_search(a.begin(), a.end(), i)){
      cout << 0 << endl;
      return 0;
    }
  }
  cout << 1 << endl;
  return 0;
}

