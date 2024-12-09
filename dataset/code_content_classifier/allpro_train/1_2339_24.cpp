#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int y,m,d;
	string str;
	while (cin >> str,str != "#") {
		cin >> y >> m >> d;
		if (y >= 31) {
			if (y > 31 ||(y == 31 && m >= 5)) {
				cout << "? " << y-30 << " " << m << " " << d << endl;
			}
			else {
				cout << "HEISEI " << y << " " << m << " " << d << endl;
			}
		}
		else {
			cout << "HEISEI " << y << " " << m << " " << d << endl;
		}
	}
	return 0;
}

