#include <iostream>
#include <vector>
using namespace std;

int saiki( long long int m, long long int n, vector< long long int > v ) {

  for ( long long int i = min( m, n ); i >= 1; i-- ) {
    v.push_back( i );
    if ( i == n ) {
      for ( long long int j = 0; j < v.size(); j++ ) {
	if ( j > 0 ) cout << " ";
	cout << v[j];
      }
      cout << endl;
    }else {
      saiki( i, n - i, v );
    }
    v.pop_back();
  }

  return 0;

}

int main() {

  while( true ) {

    long long int n;
    cin >> n;
    if ( n == 0 ) break;

    vector< long long int > v;

    saiki( n, n, v );

  }

  return 0;

}