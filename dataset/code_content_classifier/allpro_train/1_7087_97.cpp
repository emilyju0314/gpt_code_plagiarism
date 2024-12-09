#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int n,s;
  while( cin >> n ){
    int sum = 0,ans = 0,a[10000];
    for(int i = 0 ; i < n ; i++){
      cin >> a[i];
    }
    sort(a,a+n);
    for(int i = 0 ; i < n ; i++){
      sum+=a[i];
      ans+=sum;
    }
    cout << ans << endl;
  }
  return 0;
}