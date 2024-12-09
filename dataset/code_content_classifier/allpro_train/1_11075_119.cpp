#include<bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]){
  int n, m;
  cin >> n >> m;
  int c[m], d[m];
  int road[n + 1];
  memset(road, 0, sizeof(road));
  for (int i = 0; i < m; i++) {
    cin >> c[i] >> d[i];
    for (int j = c[i]; j < d[i]; j++) {
      road[j] = 1;
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    if(road[i] == 1)ans++;
    // std::cout << road[i];
    // if(i == n)std::cout << std::endl;
    // else std::cout << " ";
  }
  
  std::cout << ans*2 + n + 1 << std::endl;
  return 0;
}