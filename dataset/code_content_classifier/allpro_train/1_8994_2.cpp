#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int n,s,sum,ma,mi;

  while(cin >> n, n){
    cin >> sum;
    ma = mi = sum;
    for(int i=1;i<n;i++){
      cin >> s;
      sum += s;
      ma = max(ma,s);
      mi = min(mi,s);
    }

    cout << (sum-ma-mi)/(n-2) << endl;
  }
}