#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int n;
  double xa,ya,ra,xb,yb,rb,l;
  cin >> n;
  for(int i=0;i<n;i++) {
    cin >> xa >> ya >> ra >> xb >> yb >> rb;
    l = sqrt((xb-xa)*(xb-xa) + (yb-ya)*(yb-ya));
    if(l > ra + rb)
      cout << 0 << endl;
    else if((l <= ra + rb) && (l >= abs(ra-rb)))
      cout << 1 << endl;
    else if(l < ra - rb)
      cout << 2 << endl;
    else if(l < rb - ra)
      cout << -2 << endl;
  }
}