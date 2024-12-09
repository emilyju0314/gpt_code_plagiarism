#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		stack<int> s;
		for (int i = 9; i >= 0; i--) {
			if (n >= pow(2, i)) {
				n -= pow(2, i);
				s.push(pow(2, i));
			}
		}

		while (!s.empty()) {
			cout << s.top();
			s.pop();

			if (s.size() != 0) {
				cout << " ";
				continue;
			}
			cout << endl;
		}
	}
	return 0;
}