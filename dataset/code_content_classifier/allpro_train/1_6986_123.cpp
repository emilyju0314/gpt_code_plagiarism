#include <iostream>

using namespace std;

int main() {
	int x;
	cin >> x;
	
	for (int a = -118; a <= 119; a++) {
		for (int b = -118; b <= 119; b++) {
			if (a * a * a * a * a - b * b * b * b * b == x) {
				cout << a << " " << b << endl;
				return 0;
			}
		}
	}
	
	return 0;
}