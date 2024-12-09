#include <iostream> 
using namespace std;

int main() {
	
	while (1) {
		string s; cin >> s;

		if (s == "0")break;

		int sum = 0;

		for (char c : s) {
			sum += (c - '0');
		}

		cout << sum << endl;
	}

	return 0;
}

