#include <iostream>
#include <string>
using namespace std;

string S, T, U; int loop = 1;

bool solve(string A) {
	int cnt = 0;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == A[cnt]) cnt++;
		if (A.size() == cnt) return true;
	}
	return false;
}

int main() {
	cin >> S >> T; U = T;
	for (int i = 1; i <= 20; i++) {
		if (solve(U) == false) {
			cout << i - 1 << endl;
			break;
		}
		string B = U;
		for (int j = 0; j < T.size(); j++) {
			if (U.size() >= 300000) {
				break;
			}
			U += T[j];
			U += B;
		}
	}
	return 0;
}
