#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n;
  while(cin >> n){
    int cnt = 0;
    bool f = false;
    for(int i=0;i<n;i++){
      char c;
      int x;
      cin >> c >> x;
      if(c == '(') cnt += x;
      else{
        cnt -= x;
        if(cnt < 0) f = true;
      }
    }
    if(!f && cnt == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}