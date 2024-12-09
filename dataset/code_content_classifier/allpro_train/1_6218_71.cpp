#include <iostream>
using namespace std;

int main(){
	int n;
	while( cin >> n , n ){
		for(int i=0 ; i < n ; i++ ){
			int a1, b1, c1, d1, a2, b2, c2, d2;
			cin >> a1 >> b1 >> c1 >> d1 >> a2 >> b2 >> c2 >> d2;
			int w = a1 * a2 - b1 * b2 - c1 * c2 - d1 * d2;
			int x = a1 * b2 + a2 * b1 + c1 * d2 - c2 * d1;
			int y = a1 * c2 - b1 * d2 + a2 * c1 + b2 * d1;
			int z = a1 * d2 + b1 * c2 - b2 * c1 + a2 * d1;
			cout << w << " " << x << " " << y << " " << z << endl;
		}
	}
}