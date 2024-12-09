#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int ans=0,m=n+1,b;
  for(int i=0;i<n;i++){
    cin >> b;
    if(m>b){
      ans++;
      m=b;
    }
  }
  cout << ans << endl;
  return 0;
}