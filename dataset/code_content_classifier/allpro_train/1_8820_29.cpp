#include <iostream>
using namespace std;

int main() {
  int n,q;

  while(1) {
  cin >> n >> q;
  if(n == 0 && q == 0) break;
    int a[101]={};
  for(int i=0;i<n;i++){
    int m;
    cin >> m;
    for(int j=0;j<m;j++){
      int d;
      cin >> d;
      a[d]++;
    }
  }
  int ans=0;
  int cnt = 0;
  for(int i=0;i<101;i++){
    if(a[i] > cnt && a[i] >= q) ans = i,cnt = a[i];
    }
  cout << ans <<endl;
  }

  return 0;
}