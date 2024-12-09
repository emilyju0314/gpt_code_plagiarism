#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  int cnt = 0;
  map<int, int> m;

  for(int i = 0; i < 3; i++){
      cin >> a >> b;
      m[a] += 1;
      m[b] += 1;
  }

  for(auto itr: m){
      if(itr.second >= 2) cnt++;
  }

  if(cnt >= 2) cout << "YES";
  else cout << "NO";
}