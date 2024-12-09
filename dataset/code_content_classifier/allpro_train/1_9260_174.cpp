#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main() {

  while( true ) {

    long long int n;
    cin >> n;
    if ( n == 0 ) break;

    vector< long long int > v;

    for ( long long int i = 0; i < n; i++ ) {

      long long int in;
      cin >> in;
      v.push_back( in );

    }

    double ans;
    long long int ans_s = -1, ans_a, ans_c;

    for ( long long int s = 0; s <= 15; s++ ) {
      for ( long long int a = 0; a <= 15; a++ ) {
	for ( long long int c = 0; c <= 15; c++ ) {

	  long long int r = s;
	  long long int x[256] = {};
	  for ( long long int i = 0; i < n; i++ ) {

	    r = ( a * r + c ) % 256;
	    long long int o = ( v[i] + r ) % 256;
	    x[o]++;

	  }
	  double h = 0.00;
	  for ( long long int i = 0; i < 256; i++ ) {
	    if ( x[i] == 0 ) continue;
	    double b = 1.00 * x[i] / n;
	    h -= b * log( b );
	  }
	  if ( ans_s == -1 || ans - h > 1e-10 ) {
	    ans = h;
	    ans_s = s;
	    ans_a = a;
	    ans_c = c;
	  }

	}
      }
    }

    cout << ans_s << " " << ans_a << " " << ans_c << endl;

  }

  return 0;

}