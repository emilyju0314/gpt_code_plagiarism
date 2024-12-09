#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, i, tmp = 0;
	cin >> N;
	for (i = 0; i < N; ++i) {
		string S;
		cin >> S;
		if (S == "A") ++tmp;
		else {
			if (!tmp) break;
			--tmp;
		}
	}
	if (N != i || tmp) cout << "NO";
	else cout << "YES";
	cout << endl;
}
