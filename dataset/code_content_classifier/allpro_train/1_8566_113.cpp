#include <iostream>
using namespace std;

int main(){
  int x,y,w,h;
  int t,n;
  cin >> t;
  while( t-- ){
    cin >> x>>y>>w>>h;
    cin >> n;

    w+=x; h+=y;
    int ans=0, a,b;
    for( int i=0;i<n;i++ ){
      cin >> a >> b;
      if( a>=x && a<=w && b>=y && b<=h )
	ans++;
    }
    cout << ans << endl;
  }

  return 0;
}