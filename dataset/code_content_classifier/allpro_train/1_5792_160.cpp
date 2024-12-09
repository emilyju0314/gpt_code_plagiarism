#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(){
  int T;
  cin >> T;

  while(T--){
    int n;
    cin >> n;

    int t[n];
    int mn = 0, mx = 0;

    for(int i = 0; i < n; i++){
      cin >> t[i];
      if(i != 0){
        mn = min(mn, t[i] - t[i - 1]);
        mx = max(mx, t[i] - t[i - 1]);
      }
    }

    cout << abs(mx) << " " << abs(mn) << endl;
  }
}