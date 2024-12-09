#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;

int absmax(int p, int q) {
	int a, b;
	a = p;
	b = q;
	if( a < 0 ) a *= -1;
	if( b < 0 ) b *= -1;
	if( a < b ) return b;
	return a;
}

struct pairs {
	int p, q;
};

int main(void){
	int N;
	cin >> N;
	string ans[] = { "C", "P" };

	for(int i = 0; i < N; i++) {
		pairs p, q;
		vector< pairs > sp;
		cin >> p.p >> p.q;
		for( q.p = - absmax(p.p, p.q) ; q.p <= absmax(p.p, p.q); q.p ++) {
			for( q.q = - absmax(p.p, p.q); q.q <= absmax(p.p, p.q); q.q ++) {
				int tmp = q.p * q.p + q.q * q.q;
				if( tmp > 0 && ( ( q.p * p.p + q.q * p.q ) % tmp == 0 ) && 
					( q.p * p.q - q.q * p.p ) % tmp == 0 ) {
						sp.push_back( q );
				}
			}
		}
		cout << ans[sp.size() == 8] << endl;
	}
	return 0;
}