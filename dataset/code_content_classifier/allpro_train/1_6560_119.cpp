#include <iostream>
using namespace std;

int main() {
	long long int s, m = 1000; cin >> s;
	 
	while(s > 100) {
		m = min(m, abs(s % 1000 - 753));
		s /= 10;
	}
	
	cout << m;	
}