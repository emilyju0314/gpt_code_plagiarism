#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
  int a,b,c,d,e,f,cnt;
  for(int i=0; i<3; i++) {
      cin >> a >> b >> c >> d >> e >> f;
      cnt=3600*(d-a)+60*(e-b)+(f-c);
      cout << cnt/3600 << " " << (cnt%3600)/60 << " " << cnt%60 << endl;
  }
}
