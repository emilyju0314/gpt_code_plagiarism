#include <iostream>
#include <cstdlib>
#include <deque>

using namespace std;

void del( deque<int>& q, int& pos, int &n ) {
  q.erase( q.begin() + pos );
  n--;
  pos = ( pos + n - 1 ) % n;
}


// AOJ1275: "And Then There Was One"
int main() {
  while( 1 ) {
    int n, k, m;
    cin >> n >> k >> m;
    if( !n && !k && !m ) { return EXIT_SUCCESS; }

    deque<int> stones;
    for( int i = 0; i < n; i++ ) {
      stones.push_back( i + 1 );
    }
    m--;
    del( stones, m, n );
    while( n > 1 ) {
      m = ( m + k ) % n;
      del( stones, m, n );
    }
    cout << stones[ 0 ] << endl;
  }
}