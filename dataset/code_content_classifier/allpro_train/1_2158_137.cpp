#include<iostream>
using namespace std;

int main(){
  int w,d,h1[10],h2[10];
  bool use[10];

  while(cin >> w >> d,w){
    int ans = 0;
    for(int i=0;i<w;i++)cin >> h1[i], ans += h1[i];
    for(int i=0;i<d;i++)cin >> h2[i], ans += h2[i], use[i] = false;

    for(int i=0;i<w;i++){
      for(int j=0;j<d;j++){
	if(!use[j] && h1[i] == h2[j]){
	  use[j] = true;
	  ans -= h1[i];
	  break;
	}
      }
    }

    cout << ans << endl;
  }
}